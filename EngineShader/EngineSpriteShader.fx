

struct EngineVertex
{
    float4 COLOR : COLOR;
	float4 UV : TEXCOORD;
    
    float4 POSITION : POSITION;
};

struct VertexShaderOutPut
{
    // veiwport행렬이 곱해지는 포지션
    float4 SVPOSITION : SV_POSITION; 
    float4 UV : TEXCOORD;

    float4 COLOR : COLOR;
};

cbuffer FTransform : register(b0)
{
    float4 Scale;
    float4 Rotation;
    float4 Location;

    float4x4 ScaleMat;
    float4x4 RotationMat;
    float4x4 LocationMat;
    float4x4 World;
    float4x4 View;
    float4x4 Projection;
    float4x4 WVP;
};

cbuffer FSpriteData : register(b1)
{
    float4 CuttingPos;
    float4 CuttingSize;
};


VertexShaderOutPut VertexToWorld(EngineVertex _Vertex)
{
    VertexShaderOutPut OutPut;
    
    
    OutPut.SVPOSITION = mul(_Vertex.POSITION, WVP);
	
    OutPut.UV.x = (_Vertex.UV.x * CuttingSize.x) + CuttingPos.x;
    OutPut.UV.y = (_Vertex.UV.y * CuttingSize.y) + CuttingPos.y;
	
    
    OutPut.COLOR = _Vertex.COLOR;
	
    return OutPut;
}


Texture2D ImageTexture : register(t0);

SamplerState ImageSampler : register(s0);

float4 PixelToWorld(VertexShaderOutPut _Vertex) : SV_Target0
{
    float4 Color = ImageTexture.Sample(ImageSampler, _Vertex.UV.xy);
    return Color;
}