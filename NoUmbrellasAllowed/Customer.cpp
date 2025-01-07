#include "PreCompile.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include "Customer.h"
#include "ContentsRandom.h"

ACustomer::ACustomer()
{
    std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
    RootComponent = Default;
    // Hair Info
    {
        AllHairInfo.resize(8);
        AllHairSetInfo.resize(4);

        // Wonman 0st HairInfo
        AllHairInfo[0].Location = { 0.0f, 50.0f, -10.0f };
        AllHairSetInfo[0].Location = { 0.0f, -10.0f, 21.0f };

        // Wonman 1st HairInfo
        AllHairInfo[1].Location = { 0.0f, 77.0f, -10.0f };
        AllHairSetInfo[1].Location = { 0.0f, 160.0f, 21.0f };

        // Wonman 1st HairInfo
        AllHairInfo[2].Location = { 0.0f, 70.0f, -10.0f };
        AllHairSetInfo[2].Location = { 0.0f, -10.0f, 21.0f };

        // Wonman 3st HairInfo
        AllHairInfo[3].Location = { 0.0f, 78.0f, -10.0f };
        AllHairInfo[4].Location = { 0.0f, 75.0f, -10.0f };
        AllHairInfo[5].Location = { 0.0f, 75.0f, -10.0f };
        AllHairInfo[6].Location = { 0.0f, 75.0f, -10.0f };
        AllHairInfo[7].Location = { 0.0f, 75.0f, -10.0f };
    }


    int HairNum = 1;
    HairRenderer2 = CreateDefaultSubObject<USpriteRenderer>();
    HairRenderer2->SetSprite("Set", HairNum);
    HairRenderer2->SetWorldLocation(AllHairSetInfo[HairNum].Location);
    HairRenderer2->SetupAttachment(RootComponent);
    HairRenderer2->SetActive(false);

    int Form = 2;

    BodyRenderer = CreateDefaultSubObject<USpriteRenderer>();
    BodyRenderer->SetSprite("Body", Form);
    BodyRenderer->SetAutoScaleRatio(3.0f);
    BodyRenderer->SetWorldLocation({ 0.0f, -210.0f, 20.0f });
    BodyRenderer->SetupAttachment(RootComponent);

    HeadRenderer = CreateDefaultSubObject<USpriteRenderer>();
    HeadRenderer->SetSprite("Head", Form);
    HeadRenderer->SetWorldLocation({ 0.0f, -11.0f, 10.0f });
    HeadRenderer->SetAutoScaleRatio(3.0f);
    HeadRenderer->SetupAttachment(RootComponent);


    RightEyeRenderer = CreateDefaultSubObject<USpriteRenderer>();
    CreateAnimation(RightEyeRenderer, "000", "000_happy_loop.png", 3.1f, { 0,1,2, 3 }, { 0.1f,0.1f,0.1f, 4.0f });
    CreateAnimation(RightEyeRenderer, "001", "001_neutral_loop.png", 3.1f, { 0,1,2, 3,4 }, { 0.1f,0.1f,0.1f, 0.1f,4.0f });
    CreateAnimation(RightEyeRenderer, "002", "002_neutral_loop.png", 3.1f, { 0,1,2, 3,4 }, { 0.1f,0.1f,0.1f, 0.1f,4.0f });
    CreateAnimation(RightEyeRenderer, "003", "003_neutral_loop.png", 3.1f, { 0,1,2, 3,4 }, { 0.1f,0.1f,0.1f, 0.1f,4.0f });
    RightEyeRenderer->ChangeAnimation("000");
    RightEyeRenderer->SetWorldLocation({ 27.0f, 63.0f, 2.0f });
    RightEyeRenderer->SetupAttachment(RootComponent);

    LeftEyeRenderer = CreateDefaultSubObject<USpriteRenderer>();
    CreateAnimation(LeftEyeRenderer, "000", "000_happy_loop.png", 3.1f, { 0,1,2, 3 }, { 0.1f,0.1f,0.1f, 4.0f });
    CreateAnimation(LeftEyeRenderer, "001", "001_neutral_loop.png", 3.1f, { 0,1,2, 3,4 }, { 0.1f,0.1f,0.1f,0.1f, 4.0f });
    CreateAnimation(LeftEyeRenderer, "002", "002_neutral_loop.png", 3.1f, { 0,1,2, 3,4 }, { 0.1f,0.1f,0.1f,0.1f, 4.0f });
    CreateAnimation(LeftEyeRenderer, "003", "003_neutral_loop.png", 3.1f, { 0,1,2, 3 ,4 }, { 0.1f,0.1f,0.1f, 0.1f,4.0f });
    LeftEyeRenderer->ChangeAnimation("000");
    LeftEyeRenderer->SetWorldLocation({ -27.0f, 63.0f, -2.0f });
    LeftEyeRenderer->SetRotation({ 0.0f, -180.0f, 0.0f });
    LeftEyeRenderer->SetupAttachment(RootComponent);

    RightEyebrowRenderer = CreateDefaultSubObject<USpriteRenderer>();
    RightEyebrowRenderer->SetSprite("Eyebrow", 1);
    RightEyebrowRenderer->SetWorldLocation({ 23.0f, 75.0f, 1.0f });
    RightEyebrowRenderer->SetupAttachment(RootComponent);

    LeftEyebrowRenderer = CreateDefaultSubObject<USpriteRenderer>();
    LeftEyebrowRenderer->SetSprite("Eyebrow", 1);
    LeftEyebrowRenderer->SetWorldLocation({ -23.0f, 75.0f, -1.0f });
    LeftEyebrowRenderer->SetRotation({ 0.0f, 180.0f, 0.0f });
    LeftEyebrowRenderer->SetupAttachment(RootComponent);

    NoseRenderer = CreateDefaultSubObject<USpriteRenderer>();
    NoseRenderer->SetSprite("Nose", 0);
    NoseRenderer->SetWorldLocation({ 0.0f, 45.0f, 2.0f });
    NoseRenderer->SetupAttachment(RootComponent);

    MouseRenderer = CreateDefaultSubObject<USpriteRenderer>();
    MouseRenderer->SetSprite("Mouse", 0);
    MouseRenderer->SetWorldLocation({ 0.0f, 10.0f, 2.0f });
    MouseRenderer->SetupAttachment(RootComponent);
    MouseRenderer->SetAutoScaleRatio(3.0f);

    HairRenderer = CreateDefaultSubObject<USpriteRenderer>();
    HairRenderer->SetSprite("Hair", HairNum);
    HairRenderer->SetWorldLocation(AllHairInfo[HairNum].Location);
    HairRenderer->SetupAttachment(RootComponent);

}

ACustomer::~ACustomer()
{
}
void ACustomer::Tick(float _DeltaTime)
{
    AActor::Tick(_DeltaTime);



}

void ACustomer::CreateAnimation(std::shared_ptr<class USpriteRenderer>& _Render, std::string_view _AnimationName, std::string_view _SpriteName, float _Scale, std::vector<int> _Indexs, std::vector<float> _Frame, bool _Loop)
{
    _Render->CreateAnimation(_AnimationName, _SpriteName, _Indexs, _Frame, _Loop);
    _Render->SetAutoScaleRatio(_Scale);
}

void ACustomer::RandomCustomer(int _Gender, int _HairRand, int _Head, int _Body, int _Eyes, int _Nose, int _Mouse)
{

    UEngineDebug::OutPutString("Gender : " + std::to_string(_Gender));

    if (_Gender == 0)
    {

        UEngineDebug::OutPutString("WomanHair : " + std::to_string(_HairRand));
        HairRenderer->SetSprite("Hair", _HairRand);
        HairRenderer->SetWorldLocation(AllHairInfo[_HairRand].Location);
        HeadRenderer->SetSprite("Head", _Head);
        BodyRenderer->SetSprite("Body", _Body);

        if (_HairRand < 3)
        {
            HairRenderer2->SetSprite("Set", _HairRand);
            HairRenderer2->SetWorldLocation(AllHairSetInfo[_HairRand].Location);
        }
        else
        {
            HairRenderer2->SetWorldLocation({ 0.0f,0.0f, -1001.0f });
        }
        RightEyeRenderer->ChangeAnimation("00" + std::to_string(_Eyes));
        LeftEyeRenderer->ChangeAnimation("00" + std::to_string(_Eyes));
    }

    if (_Gender == 1)
    {

        _HairRand += 4;
        _Head += 4;
        _Body += 4;
        _Eyes += 4;

        UEngineDebug::OutPutString("ManHair : " + std::to_string(_HairRand));
        HairRenderer->SetSprite("Hair", _HairRand);
        HairRenderer->SetWorldLocation(AllHairInfo[_HairRand].Location);
        HairRenderer2->SetWorldLocation({ 0.0f,0.0f, -10001.0f });
        HeadRenderer->SetSprite("Head", _Head);
        BodyRenderer->SetSprite("Body", _Body);

    }



}