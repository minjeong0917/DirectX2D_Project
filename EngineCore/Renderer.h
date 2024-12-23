#pragma once
#include "SceneComponent.h"

struct EngineVertex
{
	float4 POSITION;
	float4 TEXCOORD;
	float4 COLOR;
};
struct FSpriteData
{
	float4 CuttingPos = { 0.0f, 0.0f };
	float4 CuttingSize = { 1.0f, 1.0f };
};
// 설명 :
class URenderer : public USceneComponent
{
	friend class UEngineCamera;

public:
	// constrcuter destructer
	ENGINEAPI URenderer();
	ENGINEAPI ~URenderer();

	// delete Function
	URenderer(const URenderer& _Other) = delete;
	URenderer(URenderer&& _Other) noexcept = delete;
	URenderer& operator=(const URenderer& _Other) = delete;
	URenderer& operator=(URenderer&& _Other) noexcept = delete;

	void SetOrder(int _Order) override;
	void SetTexture(std::string_view _Value);
	void SetSpriteData(float4 _CuttingPos, float4 _CuttingSize)
	{
		SpriteData.CuttingPos = _CuttingPos;
		SpriteData.CuttingSize = _CuttingSize;
	}

protected:
	ENGINEAPI void BeginPlay() override;

private:
	virtual void Render(UEngineCamera* _Camera, float _DeltaTime);

public:
	FSpriteData SpriteData;

	std::shared_ptr<class UEngineTexture> Texture = nullptr;


	Microsoft::WRL::ComPtr<ID3D11SamplerState> SamplerState = nullptr;


	// InputAssembler1
	Microsoft::WRL::ComPtr<ID3D11Buffer> VertexBuffer = nullptr;
	Microsoft::WRL::ComPtr<ID3D11InputLayout> InputLayOut = nullptr;
	void InputAssembler1Init();
	void InputAssembler1Setting();
	void InputAssembler1LayOut();

	// VertexShader
	Microsoft::WRL::ComPtr<ID3D11VertexShader> VertexShader = nullptr;
	void VertexShaderInit();
	void VertexShaderSetting();

	// 중간 컴파일 결과물
	Microsoft::WRL::ComPtr<ID3DBlob> VSShaderCodeBlob = nullptr;
	Microsoft::WRL::ComPtr<ID3DBlob> VSErrorCodeBlob = nullptr;


	// InputAssembler2
	Microsoft::WRL::ComPtr<ID3D11Buffer> IndexBuffer = nullptr;
	D3D11_PRIMITIVE_TOPOLOGY Topology = D3D11_PRIMITIVE_TOPOLOGY::D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	void InputAssembler2Init();
	void InputAssembler2Setting();

	// Rasterizer
	Microsoft::WRL::ComPtr<ID3D11RasterizerState> RasterizerState = nullptr;
	void RasterizerInit();
	void RasterizerSetting();

	// ViewPort
	D3D11_VIEWPORT ViewPortInfo;

	// Pixel Shader
	Microsoft::WRL::ComPtr<ID3D11PixelShader> PixelShader = nullptr;
	void PixelShaderInit();
	void PixelShaderSetting();

	// 중간 컴파일 결과물
	Microsoft::WRL::ComPtr<ID3DBlob> PSShaderCodeBlob = nullptr;
	Microsoft::WRL::ComPtr<ID3DBlob> PSErrorCodeBlob = nullptr;


	Microsoft::WRL::ComPtr<ID3D11Buffer> TransformConstBuffer = nullptr;
	Microsoft::WRL::ComPtr<ID3D11Buffer> SpriteConstBuffer = nullptr;
	void ShaderResInit();
	void ShaderResSetting();

	void OutPutMergeSetting();

};

