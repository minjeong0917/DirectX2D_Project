

struct EngineVertex
{
    float4 COLOR : COLOR;
    float4 POSITION : POSITION;
};

struct VertexShaderOutPut
{
    // veiwport행렬이 곱해지는 포지션
    float4 SVPOSITION : SV_POSITION; 
    float4 NEWPOSITION : POSITION; 

    float4 COLOR : COLOR;
};

VertexShaderOutPut VertexToWorld(EngineVertex _Vertex)
{
    VertexShaderOutPut OutPut;
    
    

    OutPut.SVPOSITION = _Vertex.POSITION;
    OutPut.NEWPOSITION = _Vertex.POSITION;
    
    OutPut.COLOR = _Vertex.COLOR;
	
    return OutPut;
}

float4 PixelToWorld(VertexShaderOutPut _Vertex) : SV_Target0
{
    // 색 바로 리턴
    //if(_Vertex.SVPOSITION.x > 640.0f)
    //{
    //    return float4(1.0f, 0.0f, 0.0f, 1.0f);
    //}
    //else
    //{
    //    return float4(0.0f, 1.0f, 0.0f, 1.0f);
    //}
    
    _Vertex.NEWPOSITION; // => 윈도우 좌표계
	
    if (_Vertex.NEWPOSITION.x < 0)
    {
        return float4(1.0f, 0.0f, 0.0f, 1.0f);
    }
    else
    {
        return float4(0.0f, 1.0f, 0.0f, 1.0f);
    }
	
    return _Vertex.COLOR;
}