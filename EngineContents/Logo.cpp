#include "PreCompile.h"
#include "Logo.h"
#include <EngineCore/Renderer.h>

ALogo::ALogo()
{
	std::shared_ptr<URenderer> NewRenderer = CreateDefaultSubObject<URenderer>();
}

ALogo::~ALogo()
{
}

void ALogo::BeginPlay()
{
	AActor::BeginPlay();
}

void ALogo::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}