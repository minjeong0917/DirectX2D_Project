#include "PreCompile.h"

#include "Card.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/FontRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/Collision.h>

#include <EngineCore/CameraActor.h>
#include <EngineCore/EngineCamera.h>
#include "CardInfo.h"
#include <EngineCore/FontWidget.h>
#include "ShopHUD.h"

ACard::ACard()
{
    std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
    RootComponent = Default;


    CardRender = CreateDefaultSubObject<USpriteRenderer>();
    CardRender->SetSprite("Blue", 0);
    CardRender->SetAutoScaleRatio(3.0f);
    CardRender->SetupAttachment(RootComponent);

    CardNameText = CreateDefaultSubObject<UFontRenderer>();
    CardNameText->SetFont("PF", 25.0f, TColor<unsigned char>(97, 76, 45, 255));
    CardNameText->SetActive(false);
    CardNameText->SetupAttachment(RootComponent);

    CardExplainText = CreateDefaultSubObject<UFontRenderer>();
    CardExplainText->SetFont("PF", 19.0f, TColor<unsigned char>(125, 75, 71, 255), FW1_CENTER);
    CardExplainText->SetupAttachment(RootComponent);

    CardPercentText = CreateDefaultSubObject<UFontRenderer>();
    CardPercentText->SetFont("PF", 18.0f, TColor<unsigned char>(148, 65, 33, 255), FW1_RIGHT);
    CardPercentText->SetupAttachment(RootComponent);

    CardCollision = CreateDefaultSubObject<UCollision>();
    CardCollision->SetCollisionProfileName("Card");
    CardCollision->SetRelativeLocation({ 0.0f, 0.85f,0.0f });
    CardCollision->SetScale3D({ 1.0f, 0.25f,1.0f });
    CardCollision->SetupAttachment(CardRender);


    CardCollision->SetCollisionEnter([this](UCollision* _This, UCollision* _Other)
        {
            this->OnCollisionEnter(_This, _Other);
        });
    CardCollision->SetCollisionEnd([this](UCollision* _This, UCollision* _Other)
        {
            this->OnCollisionEnd(_This, _Other);

        });

}

ACard::~ACard()
{
}

void ACard::BeginPlay()
{
    AActor::BeginPlay();
}

void ACard::Tick(float _DeltaTime)
{
    AActor::Tick(_DeltaTime);
    CardNameText->SetWorldLocation({ CardRender->GetWorldLocation().X - 95.0f ,CardRender->GetWorldLocation().Y + 160.0f,CardRender->GetWorldLocation().Z });
    CardExplainText->SetWorldLocation({ CardRender->GetWorldLocation().X + 5.0f,CardRender->GetWorldLocation().Y + 100, CardRender->GetWorldLocation().Z });
    CardPercentText->SetWorldLocation({ CardRender->GetWorldLocation().X + 130.0f,CardRender->GetWorldLocation().Y + 156.0f, CardRender->GetWorldLocation().Z });
}

void ACard::OnCollisionEnter(UCollision* _This, UCollision* _Other)
{
    IsEnter = true;
    SoundPlayer = UEngineSound::Play("DM-CGS-20 - Snap.wav");

}

void ACard::OnCollisionEnd(UCollision* _This, UCollision* _Other)
{
    IsEnter = false;
}


void ACard::SetCardColor(ECardColor _CardTye, int _CardStep)
{

    switch (_CardTye)
    {
    case ECardColor::Blue:
        CardRender->SetSprite("Blue", _CardStep);
        break;
    case ECardColor::Gray:
        CardRender->SetSprite("Gray", _CardStep);
        break;
    case ECardColor::Green:
        CardRender->SetSprite("Green", _CardStep);
        break;
    default:
        break;
    }


}

void ACard::SetCollisionActive(bool _IsActive)
{
    if (CardCollision != nullptr)
    {
        CardCollision->SetActive(_IsActive);
    }

}
void ACard::SetCollisionYScale(float _YScale)
{
    if (CardCollision != nullptr)
    {
        CardCollision->SetScale3D({ 1.0f,0.25f + _YScale, 1.0f });
        CardCollision->SetRelativeLocation({ 0.0f, 1.0f- _YScale,0.0f });

    }

}

void ACard::SetCollisionYLocation(float _YLoc)
{
    if (CardCollision != nullptr)
    {
        CardCollision->SetRelativeLocation({ 0.0f, 1.0f - _YLoc,0.0f });

    }

}

void ACard::ChangeTextSize(float _Size)
{
    if (CardNameText != nullptr)
    {
        CardNameText->SetFont("PF", _Size, TColor<unsigned char>(97, 76, 45, 255));
    }

}

void ACard::SetCardNameText(std::string _Text)
{
    if (CardNameText != nullptr)
    {
        CardNameText->SetText(_Text);
    }
}
void ACard::SetCardExplainText(std::string _Text)
{
    if (CardExplainText != nullptr)
    {
        CardExplainText->SetText(_Text);
    }
}
void ACard::SetCardPercentText(std::string _Text)
{
    if (CardPercentText != nullptr)
    {
        CardPercentText->SetText(_Text);
    }
}
void ACard::SetTextActive(bool _IsActive)
{
    if (CardNameText != nullptr)
    {
        CardNameText->SetActive(_IsActive);
        CardExplainText->SetActive(_IsActive);
        CardPercentText->SetActive(_IsActive);
    }
}