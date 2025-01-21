#include "PreCompile.h"
#include "EngineStructuredBuffer.h"

std::map<int, std::map<std::string, std::shared_ptr<UEngineStructuredBuffer>>> UEngineStructuredBuffer::BufferMap;

void UEngineStructuredBuffer::Release()
{
	BufferMap.clear();
}

UEngineStructuredBuffer::UEngineStructuredBuffer()
{
}

UEngineStructuredBuffer::~UEngineStructuredBuffer()
{
}

std::shared_ptr<UEngineStructuredBuffer> UEngineStructuredBuffer::CreateOrFind(UINT _Byte, const std::string_view& _Name)
{
	if (0 == _Byte)
	{
		MSGASSERT("0����Ʈ ������۰� ����������� �߽��ϴ�.");
	}

	std::string UpperName = UEngineString::ToUpper(_Name);

	if (true == BufferMap.contains(_Byte))
	{
		if (true == BufferMap[_Byte].contains(UpperName))
		{
			return BufferMap[_Byte][UpperName];
		}
	}

	// ���ʷ� ��������� �����̴�.
	std::shared_ptr<UEngineStructuredBuffer> NewRes = std::make_shared<UEngineStructuredBuffer>();
	NewRes->SetName(UpperName);
	NewRes->ResCreate(_Byte, 1);
	BufferMap[_Byte][UpperName] = NewRes;

	return NewRes;
}

void UEngineStructuredBuffer::ResCreate(UINT _DataSize, UINT _DataCount)
{
	// 20 30 40 50 60 
	// _BindIndex ���Ⱑ ��� �ٲ� ���ü� �ִ�.
	// ���α׷��ֿ��� �־��� �����̱� �����̴�.
	// �̹��� comptr�� ����ߴ�.

	Buffer = nullptr;

	{
		DataCount = _DataCount;
		DataSize = _DataSize;
		BufferInfo.ByteWidth = _DataCount * _DataSize;
		// �ؽ�ó�� ���� �빮��
		BufferInfo.BindFlags = D3D11_BIND_SHADER_RESOURCE;
		BufferInfo.CPUAccessFlags = D3D11_CPU_ACCESS_FLAG::D3D11_CPU_ACCESS_WRITE;
		BufferInfo.Usage = D3D11_USAGE_DYNAMIC;
		BufferInfo.MiscFlags = D3D11_RESOURCE_MISC_BUFFER_STRUCTURED; // ��Ʈ��ó�� ��ó
		BufferInfo.StructureByteStride = _DataSize; // 1���� ������ ũ�Ⱑ ������ �˷���� �Ѵ�.

		if (S_OK != UEngineCore::GetDevice().GetDevice()->CreateBuffer(&BufferInfo, nullptr, &Buffer))
		{
			MSGASSERT("��Ʈ��ó�� ���� ������ �����߽��ϴ�..");
			return;
		}

		// SRV ����ü�� �־���� �մϴ�.
		// Texture�� �ٸ���.
		// Texture�� SRV�� �׳ɸ���� �ټ� ������
		// ����ó�� ���ۿ��� ���°� �޶��.

		D3D11_SHADER_RESOURCE_VIEW_DESC tSRVDesc = {};
		// directx������ texture�� �迭���ɼ��� �ִ�.
		// �� �迭�� �޷��޶�� ���̴�. 
		// �ִϴ� �ؽ�ó�� �ƴϴ�.BUFFER �������� ź���� SRV��� ���� �˷��ִ°�.
		tSRVDesc.ViewDimension = D3D11_SRV_DIMENSION_BUFFEREX;
		tSRVDesc.Format = DXGI_FORMAT_UNKNOWN;
		// ������ ��� ���� ���ų�.
		tSRVDesc.BufferEx.FirstElement = 0;
		// Flage
		tSRVDesc.BufferEx.Flags = 0;
		// �迭�� ī��Ʈ
		tSRVDesc.BufferEx.NumElements = DataCount;

		if (S_OK != UEngineCore::GetDevice().GetDevice()->CreateShaderResourceView(Buffer.Get(), &tSRVDesc, &SRV))
		{
			MSGASSERT("��Ʈ��ó�� ���� ������ �����߽��ϴ�..");
			return;
		}


	}
}

void UEngineStructuredBuffer::ChangeData(void* _Data, UINT _Size)
{
	if (_Size != BufferInfo.ByteWidth)
	{
		MSGASSERT("����Ʈ ũ�Ⱑ �ٸ��� ���õǾ����ϴ�" + GetName());
		return;
	}

	// FTransform& RendererTrans = GetTransformRef();
	D3D11_MAPPED_SUBRESOURCE Data = {};
	// �� �����͸� ����ϴ� ������ ������ ��� ����
	// ��� �׷���ī��� �� �׷���ī�忡 �ִ� ������� �����ؾ� ��.
	UEngineCore::GetDevice().GetContext()->Map(Buffer.Get(), 0, D3D11_MAP_WRITE_DISCARD, 0, &Data);

	// Data.pData �׷���ī��� ����� �ּҰ�.
	if (nullptr == Data.pData)
	{
		MSGASSERT("�׷���ī�尡 ������ �ź��߽��ϴ�.");
	}
	memcpy_s(Data.pData, BufferInfo.ByteWidth, _Data, BufferInfo.ByteWidth);
	UEngineCore::GetDevice().GetContext()->Unmap(Buffer.Get(), 0);
}

void UEngineStructuredBuffer::Setting(EShaderType _Type, UINT _BindIndex)
{
	// ���� ������۸� 
	ID3D11Buffer* ArrPtr[1] = { Buffer.Get() };

	switch (_Type)
	{
	case EShaderType::VS:
		UEngineCore::GetDevice().GetContext()->VSSetShaderResources(_BindIndex, 1, &SRV);
		break;
	case EShaderType::PS:
		UEngineCore::GetDevice().GetContext()->PSSetShaderResources(_BindIndex, 1, &SRV);
		break;
	case EShaderType::HS:
	case EShaderType::DS:
	case EShaderType::GS:
	case EShaderType::CS:
	default:
		MSGASSERT("���� �������� �ʴ� ���̴��� �����Ϸ��� �߽��ϴ�.");
		break;
	}
}
