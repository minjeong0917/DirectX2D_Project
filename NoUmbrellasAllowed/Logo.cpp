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


}