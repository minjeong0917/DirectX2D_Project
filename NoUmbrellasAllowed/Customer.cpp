#include "PreCompile.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include "Customer.h"

ACustomer::ACustomer()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;
	// Hair Info
	{
		AllHairInfo.resize(10);
		AllHairSetInfo.resize(4);

		// Wonman 0st HairInfo
		AllHairInfo[0].Scale = { 171.0f, 270.0f, 1.0f };
		AllHairInfo[0].Location = { 0.0f, 50.0f, 0.0f };

		AllHairSetInfo[0].Scale = { 147.0f, 396.0f, 1.0f };
		AllHairSetInfo[0].Location = { 0.0f, -10.0f, 0.0f };

		// Wonman 1st HairInfo
		AllHairInfo[1].Scale = { 57.0f * 3.0f, 82.0f * 3.0f, 1.0f };
		AllHairInfo[1].Location = { 0.0f, 50.0f, 0.0f };

		AllHairSetInfo[1].Scale = { 26.0f * 3.0f, 26.0f * 3.0f, 1.0f };
		AllHairSetInfo[1].Location = { 0.0f, 160.0f, 0.0f };

		// Wonman 1st HairInfo
		AllHairInfo[2].Scale = { 56.0f * 3.0f, 74.0f * 3.0f, 1.0f };
		AllHairInfo[2].Location = { 0.0f, 70.0f, 0.0f };

		AllHairSetInfo[2].Scale = { 53.0f * 3.0f, 136.0f * 3.0f, 1.0f };
		AllHairSetInfo[2].Location = { 0.0f, -10.0f, 0.0f };

		// Wonman 3st HairInfo
		AllHairInfo[3].Scale = { 168.0f, 227.0f, 1.0f };
		AllHairInfo[3].Location = { 0.0f, 78.0f, 0.0f };
	}


	int HairNum = 2;

	if (HairNum < 3)
	{
		HairRenderer2 = CreateDefaultSubObject<USpriteRenderer>();
		HairRenderer2->SetSprite("Set", HairNum);

		HairRenderer2->SetScale3D(AllHairSetInfo[HairNum].Scale);
		HairRenderer2->SetWorldLocation(AllHairSetInfo[HairNum].Location);
		HairRenderer2->SetupAttachment(RootComponent);
	}

	int Form = 3;

	BodyRenderer = CreateDefaultSubObject<USpriteRenderer>();
	BodyRenderer->SetSprite("Body", Form);
	BodyRenderer->SetScale3D({ 252.0f, 333.0f, 1.0f });
	BodyRenderer->SetWorldLocation({ 0.0f, -210.0f, 0.0f });
	BodyRenderer->SetupAttachment(RootComponent);

	HeadRenderer = CreateDefaultSubObject<USpriteRenderer>();
	HeadRenderer->SetSprite("Head", Form);
	HeadRenderer->SetScale3D({ 174.0f, 198.0f, 1.0f });
	HeadRenderer->SetWorldLocation({ 0.0f, -10.0f, 0.0f });
	HeadRenderer->SetupAttachment(RootComponent);



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
	MouseRenderer->SetScale3D({ 48.0f, 39.0f, 1.0f });
	MouseRenderer->SetWorldLocation({ 0.0f, 10.0f, 0.0f });
	MouseRenderer->SetupAttachment(RootComponent);

	HairRenderer = CreateDefaultSubObject<USpriteRenderer>();
	HairRenderer->SetSprite("WomanHair", HairNum);

	HairRenderer->SetScale3D(AllHairInfo[HairNum].Scale);
	HairRenderer->SetWorldLocation(AllHairInfo[HairNum].Location);
	HairRenderer->SetupAttachment(RootComponent);

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
