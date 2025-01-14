#include "PreCompile.h"

#include "Bookbutton.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/Collision.h>

ABookButton::ABookButton()
{
    std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
    RootComponent = Default;

    // 나가기 버튼
    BackButtonRender = CreateDefaultSubObject<USpriteRenderer>();
    BackButtonRender->SetSprite("BookButton", 0);
    BackButtonRender->SetAutoScaleRatio(3.0f);
    BackButtonRender->SetWorldLocation({ 910.0f, 303.0f, -172.0f });
    BackButtonRender->SetupAttachment(RootComponent);
    AllBookButtonRenders.push_back(BackButtonRender);

    BackButtonCollision = CreateDefaultSubObject<UCollision>();
    BackButtonCollision->SetCollisionProfileName("BookButton_0");
    BackButtonCollision->SetWorldLocation({ 0.0f, 0.5f, 0.0f });
    BackButtonCollision->SetupAttachment(BackButtonRender);

    BackButtonCollision->SetCollisionStay([this](UCollision* _This, UCollision* _Other)
        {
            this->OnCollisionStay(_This, _Other);
        });
    BackButtonCollision->SetCollisionEnd([this](UCollision* _This, UCollision* _Other)
        {
            this->OnCollisionEnd(_This, _Other);

        });

    // 목차 페이지 이동 버튼
    IndexButtonRender = CreateDefaultSubObject<USpriteRenderer>();
    IndexButtonRender->SetSprite("BookButton", 2);
    IndexButtonRender->SetAutoScaleRatio(3.0f);
    IndexButtonRender->SetWorldLocation({ 444.0f, 319.0f, -172.0f });
    IndexButtonRender->SetupAttachment(RootComponent);
    AllBookButtonRenders.push_back(IndexButtonRender);

    IndexButtonCollision = CreateDefaultSubObject<UCollision>();
    IndexButtonCollision->SetCollisionProfileName("BookButton_1");
    IndexButtonCollision->SetWorldLocation({ 0.0f, 0.5f, 0.0f });
    IndexButtonCollision->SetupAttachment(IndexButtonRender);

    IndexButtonCollision->SetCollisionStay([this](UCollision* _This, UCollision* _Other)
        {
            this->OnCollisionStay(_This, _Other);
        });
    IndexButtonCollision->SetCollisionEnd([this](UCollision* _This, UCollision* _Other)
        {
            this->OnCollisionEnd(_This, _Other);

        });

    // 전 페이지 이동 버튼
    BackPageButtonRender = CreateDefaultSubObject<USpriteRenderer>();
    BackPageButtonRender->SetSprite("BookButton", 4);
    BackPageButtonRender->SetAutoScaleRatio(3.0f);
    BackPageButtonRender->SetWorldLocation({ 789.0f, 319.0f, -172.0f });
    BackPageButtonRender->SetupAttachment(RootComponent);
    AllBookButtonRenders.push_back(BackPageButtonRender);

    BackPageButtonCollision = CreateDefaultSubObject<UCollision>();
    BackPageButtonCollision->SetCollisionProfileName("BookButton_2");
    BackPageButtonCollision->SetWorldLocation({ 0.0f, 0.5f, 0.0f });
    BackPageButtonCollision->SetupAttachment(BackPageButtonRender);

    BackPageButtonCollision->SetCollisionStay([this](UCollision* _This, UCollision* _Other)
        {
            this->OnCollisionStay(_This, _Other);
        });
    BackPageButtonCollision->SetCollisionEnd([this](UCollision* _This, UCollision* _Other)
        {
            this->OnCollisionEnd(_This, _Other);

        });

    // 다음 페이지 이동 버튼
    NextPageButtonRender = CreateDefaultSubObject<USpriteRenderer>();
    NextPageButtonRender->SetSprite("BookButton", 6);
    NextPageButtonRender->SetAutoScaleRatio(3.0f);
    NextPageButtonRender->SetWorldLocation({ 849.0f, 319.0f, -172.0f });
    NextPageButtonRender->SetupAttachment(RootComponent);
    AllBookButtonRenders.push_back(NextPageButtonRender);

    NextPageButtonCollision = CreateDefaultSubObject<UCollision>();
    NextPageButtonCollision->SetCollisionProfileName("BookButton_3");
    NextPageButtonCollision->SetWorldLocation({ 0.0f, 0.5f, 0.0f });
    NextPageButtonCollision->SetupAttachment(NextPageButtonRender);

    NextPageButtonCollision->SetCollisionStay([this](UCollision* _This, UCollision* _Other)
        {
            this->OnCollisionStay(_This, _Other);
        });
    NextPageButtonCollision->SetCollisionEnd([this](UCollision* _This, UCollision* _Other)
        {
            this->OnCollisionEnd(_This, _Other);

        });

}

ABookButton::~ABookButton()
{
}

void ABookButton::Tick(float _DeltaTime)
{
    AActor::Tick(_DeltaTime);
}

void ABookButton::OnCollisionStay(UCollision* _This, UCollision* _Other)
{
    IsEnter = true;
    std::string ProfileName = _This->GetCollisionProfileName();
    size_t Index = std::stoi(ProfileName.substr(11));

    if (UEngineInput::IsDown(VK_LBUTTON))
    {
        int SpriteIndex = Index * 2 + 1;
        AllBookButtonRenders[Index]->SetSprite("BookButton", SpriteIndex);

        if (Index == 0)
        {
            IsBack = true;
        }
        if (Index == 1)
        {
            IsMoveToIndex = true;
        }
        if (Index == 2)
        {
            IsMoveToBackPage = true;
        }
        if (Index == 3)
        {
            IsMoveToNextPage = true;
        }
    }



    
}
void ABookButton::OnCollisionEnd(UCollision* _This, UCollision* _Other)
{
    IsEnter = false;

    std::string ProfileName = _This->GetCollisionProfileName();
    size_t Index = std::stoi(ProfileName.substr(11));

    if (Index == 0)
    {
        IsBack = false;
    }
    if (Index == 1)
    {
        IsMoveToIndex = false;
    }
    if (Index == 2)
    {
        IsMoveToBackPage = false;
    }
    if (Index == 3)
    {
        IsMoveToNextPage = false;
    }

    int SpriteIndex = Index * 2;
    AllBookButtonRenders[Index]->SetSprite("BookButton", SpriteIndex);
}
