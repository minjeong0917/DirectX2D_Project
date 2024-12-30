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
	LogoRenderer->USpriteRenderer::SetSprite("Logo",0);
	LogoRenderer->SetScale3D({ 732.0f, 267.0f, 1.0f });


	//LogoRenderer->CreateAnimation("Idle", "Logo", 0, 0, 0.1f);
	//USpriteRenderer::FrameAnimation* Animation = LogoRenderer->FindAnimation("Idle");
	//Animation->IsAutoScale = true;
	//Animation->AutoScaleRatio = 4.0f;
	//LogoRenderer->ChangeAnimation("Idle");
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
