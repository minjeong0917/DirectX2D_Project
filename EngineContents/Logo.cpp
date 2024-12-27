#include "PreCompile.h"
#include "Logo.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/DefaultSceneComponent.h>

ALogo::ALogo()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	LogoRenderer = CreateDefaultSubObject<USpriteRenderer>();
	LogoRenderer->CreateAnimation("Idle", "plant_01_loop.png", 0, 6, 0.2f);
	USpriteRenderer::FrameAnimation* Animation = LogoRenderer->FindAnimation("Idle");
	Animation->IsAutoScale = true;
	Animation->AutoScaleRatio = 4.0f;
	LogoRenderer->ChangeAnimation("Idle");
	LogoRenderer->SetRelativeScale3D({ 230.0f, 400.0f, 1.0f });

	LogoRenderer->SetupAttachment(RootComponent);

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

	if (UEngineInput::IsPress('A'))
	{
		AddRelativeLocation(FVector{ -100.0f * _DeltaTime, 0.0f, 0.0f });
	}

	if (UEngineInput::IsPress('D'))
	{
		AddRelativeLocation(FVector{ 100.0f * _DeltaTime, 0.0f, 0.0f });
	}

	if (UEngineInput::IsPress('W'))
	{
		AddRelativeLocation(FVector{ 0.0f, 100.0f * _DeltaTime, 0.0f });
	}

	if (UEngineInput::IsPress('S'))
	{
		AddRelativeLocation(FVector{ 0.0f, -100.0f * _DeltaTime, 0.0f });
	}

	if (UEngineInput::IsPress('Q'))
	{
		AddActorRotation(FVector{ 0.0f, 0.0f , 360.0f * _DeltaTime });
	}

	// AddActorLocation(FVector{ 100.0f * _DeltaTime, 0.0f, 0.0f});
}