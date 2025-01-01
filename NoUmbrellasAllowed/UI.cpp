#include "PreCompile.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

#include "UI.h"

AUI::AUI()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;
	UIRenderer = CreateDefaultSubObject<USpriteRenderer>();
	UIRenderer->SetupAttachment(RootComponent);

}

AUI::~AUI()
{
}

void AUI::BeginPlay()
{
	AActor::BeginPlay();
}

void AUI::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

}

void AUI::SetUISprite(std::string _Name, int _Index)
{
	UIRenderer->USpriteRenderer::SetSprite(_Name, _Index);
}

void AUI::SetUIScale3D(const FVector& _Value)
{
	UIRenderer->USpriteRenderer::SetScale3D(_Value);
}

void AUI::CreateAnimation(std::string_view _AnimationName, std::string_view _SpriteName, float _Scale, int _Start, int _End, float Time /*= 0.1f*/, bool _Loop /*= true*/)
{
	UIRenderer->CreateAnimation(_AnimationName, _SpriteName, _Start, _End, Time, _Loop);

	USpriteRenderer::FrameAnimation* Animation = UIRenderer->FindAnimation(_AnimationName);
	Animation->IsAutoScale = true;
	Animation->AutoScaleRatio = _Scale;
}

void AUI::ChangeAnimation(std::string_view _AnimationName, bool _Force /*= false*/)
{
	UIRenderer->ChangeAnimation(_AnimationName, _Force);

}

void AUI::SetRelativeLocation(const FVector& _Value)
{
	UIRenderer->SetRelativeLocation(_Value);
}

float4 AUI::GetLocation()
{
	float4 Location = UIRenderer->GetTransformRef().RelativeLocation;
	return Location;
}
