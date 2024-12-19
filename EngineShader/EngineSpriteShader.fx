

struct EngineVertex
{
    float4 COLOR : COLOR;
    float4 POSITION : POSITION;
};

struct VertexShaderOutPut
{
    float4 SVPOSITION : SV_POSITION;
    float4 COLOR : COLOR;
};

VertexShaderOutPut VertexToWorld(EngineVertex _Vertex)
{
    VertexShaderOutPut OutPut;
	
    OutPut.SVPOSITION = _Vertex.POSITION;
    OutPut.COLOR = _Vertex.COLOR;
	
    return OutPut;
}

float4 PixelToWorld(VertexShaderOutPut _Vertex) : SV_Target0
{
    // �� �ٷ� ����
    return float4(0.1f, 0.0f, 0.5f, 1.0f);
}