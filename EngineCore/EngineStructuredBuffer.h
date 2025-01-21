#pragma once
#include "EngineResources.h"
#include "EngineDeviceBuffer.h"
#include "EngineEnums.h"

// Ÿ�ϸ��� 2����� �մϴ�.
// 300����Ʈ¥�� 100�� ¥�� Ÿ�ϸ��� �ְ�
// 300����Ʈ¥�� 80�� ¥�� Ÿ�ϸ��� �ִ�.


	// ���� :
class UEngineStructuredBuffer : public UEngineResources, public UEngineDeviceBuffer
{
	friend class UEngineShaderResources;

public:
	// constrcuter destructer
	UEngineStructuredBuffer();
	~UEngineStructuredBuffer();

	// delete Function
	UEngineStructuredBuffer(const UEngineStructuredBuffer& _Other) = delete;
	UEngineStructuredBuffer(UEngineStructuredBuffer&& _Other) noexcept = delete;
	UEngineStructuredBuffer& operator=(const UEngineStructuredBuffer& _Other) = delete;
	UEngineStructuredBuffer& operator=(UEngineStructuredBuffer&& _Other) noexcept = delete;

	static std::shared_ptr<UEngineStructuredBuffer> CreateOrFind(UINT _Byte, const std::string_view& _Name);

	void ChangeData(void* _Data, UINT _Size);
	void Setting(EShaderType _Type, UINT _BindIndex);

	static void Release();

protected:

private:
	static std::map<int, std::map<std::string, std::shared_ptr<UEngineStructuredBuffer>>> BufferMap;

	// ī��Ʈ ��Ʈ��ó�� ���۴� �׷���ī�尡 ����ϴ� ���� ũ���� ������۸� ������� �ִ�.
	// 100 ����Ʈ ¥�� � �����ʹ� 10000�� �������
	void ResCreate(UINT _DataSize, UINT _DataCount);

	UINT DataSize = 0;
	UINT DataCount = 0;

	// ��뷮 �����ʹ� �ؽ�ó�� ���� �����Ѵ�.
	// regaster(t0)
	// �����ϱ� ���ؼ� SRV
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> SRV = nullptr;
};

