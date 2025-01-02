#include "PreCompile.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include "Customer.h"

ACustomer::ACustomer()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	BodyRenderer = CreateDefaultSubObject<USpriteRenderer>();
	BodyRenderer->SetSprite("Body", 0);
	BodyRenderer->SetScale3D({ 252.0f, 333.0f, 1.0f });
	BodyRenderer->SetWorldLocation({ 0.0f, -210.0f, 0.0f });
	BodyRenderer->SetupAttachment(RootComponent);

	HeadRenderer = CreateDefaultSubObject<USpriteRenderer>();
	HeadRenderer->SetSprite("Head", 0);
	HeadRenderer->SetScale3D({174.0f, 198.0f, 1.0f });
	HeadRenderer->SetWorldLocation({ 0.0f, -10.0f, 0.0f });
	HeadRenderer->SetupAttachment(RootComponent);

	HairRenderer = CreateDefaultSubObject<USpriteRenderer>();
	HairRenderer->SetSprite("Hair", 1);
	HairRenderer->SetScale3D({ 168.0f, 185.0f, 1.0f });
	HairRenderer->SetWorldLocation({ 0.0f, 90.0f, 0.0f });
	HairRenderer->SetupAttachment(RootComponent);

	RightEyeRenderer = CreateDefaultSubObject<USpriteRenderer>();
	CreateAnimation(RightEyeRenderer, "happy", "000_happy_loop.png", 3.1f, { 0,1,2, 3 }, { 0.2f,0.2f,0.2f, 3.0f });
	RightEyeRenderer->ChangeAnimation("happy");
	RightEyeRenderer->SetWorldLocation({ 27.0f, 63.0f, 0.0f });
	RightEyeRenderer->SetupAttachment(RootComponent);

	LeftEyeRenderer = CreateDefaultSubObject<USpriteRenderer>();
	CreateAnimation(LeftEyeRenderer, "happy", "000_happy_loop.png", 3.1f, { 0,1,2, 3 }, { 0.2f,0.2f,0.2f, 3.0f });
	LeftEyeRenderer->ChangeAnimation("happy");
	LeftEyeRenderer->SetWorldLocation({ -27.0f, 63.0f, 0.0f });
	LeftEyeRenderer->SetRotation({ 0.0f, -180.0f, 0.0f });
	LeftEyeRenderer->SetupAttachment(RootComponent);

	RightEyebrowRenderer = CreateDefaultSubObject<USpriteRenderer>();
	RightEyebrowRenderer->SetSprite("Eyebrow", 1);
	RightEyebrowRenderer->SetScale3D({ 57.0f, 42.0f, 1.0f });
	RightEyebrowRenderer->SetWorldLocation({ 23.0f, 75.0f, 0.0f });
	RightEyebrowRenderer->SetupAttachment(RootComponent);

	LeftEyebrowRenderer = CreateDefaultSubObject<USpriteRenderer>();
	LeftEyebrowRenderer->SetSprite("Eyebrow", 1);
	LeftEyebrowRenderer->SetScale3D({ 57.0f, 42.0f, 1.0f });
	LeftEyebrowRenderer->SetWorldLocation({ -23.0f, 75.0f, 0.0f });
	LeftEyebrowRenderer->SetRotation({ 0.0f, 180.0f, 0.0f });
	LeftEyebrowRenderer->SetupAttachment(RootComponent);

	NoseRenderer = CreateDefaultSubObject<USpriteRenderer>();
	NoseRenderer->SetSprite("Nose", 0);
	NoseRenderer->SetScale3D({ 27.0f, 51.0f, 1.0f });
	NoseRenderer->SetWorldLocation({ 0.0f, 45.0f, 0.0f });
	NoseRenderer->SetupAttachment(RootComponent);

	MouseRenderer = CreateDefaultSubObject<USpriteRenderer>();
	MouseRenderer->SetSprite("Mouse", 0);
	MouseRenderer->SetScale3D({ 48.0f, 36.0f, 1.0f });
	MouseRenderer->SetWorldLocation({ 0.0f, 10.0f, 0.0f });
	MouseRenderer->SetupAttachment(RootComponent);
}

ACustomer::~ACustomer()
{
}

void ACustomer::CreateAnimation(std::shared_ptr<class USpriteRenderer>& _Render, std::string_view _AnimationName, std::string_view _SpriteName, float _Scale, std::vector<int> _Indexs, std::vector<float> _Frame, bool _Loop)
{
	_Render->CreateAnimation(_AnimationName, _SpriteName, _Indexs, _Frame, _Loop);

	USpriteRenderer::FrameAnimation* Animation = _Render->FindAnimation(_AnimationName);
	Animation->IsAutoScale = true;
	Animation->AutoScaleRatio = _Scale;
}
