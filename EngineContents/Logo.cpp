#include "PreCompile.h"
#include "Logo.h"
#include <EngineCore/Renderer.h>

ALogo::ALogo()
{
	LogoRenderer = CreateDefaultSubObject<URenderer>();

	SetActorRelativeScale3D({ 100.0f, 100.0f, 1.0f });
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
	AddActorLocation(FVector{ 1.0f, 0.0f, 0.0f });

}