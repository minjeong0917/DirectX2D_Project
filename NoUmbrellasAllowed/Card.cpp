#include "PreCompile.h"

#include "Card.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/Collision.h>

#include <EngineCore/CameraActor.h>
#include <EngineCore/EngineCamera.h>
#include "CardInfo.h"
#include <EngineCore/FontWidget.h>
#include "ShopHUD.h"
#include <EngineCore/FontRenderer.h>

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
    CardExplainText->SetFont("PF", 22.0f, TColor<unsigned char>(73, 72, 71, 255), FW1_CENTER);
    CardExplainText->SetupAttachment(RootComponent);


    CardPercentText = CreateDefaultSubObject<UFontRenderer>();
    CardPercentText->SetFont("PF", 20.0f, TColor<unsigned char>(148, 65, 33, 255), FW1_RIGHT);
    CardPercentText->SetupAttachment(RootComponent);
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
    CardExplainText->SetWorldLocation({ CardRender->GetWorldLocation().X + 5.0f,CardRender->GetWorldLocation().Y + 90, CardRender->GetWorldLocation().Z });
    CardPercentText->SetWorldLocation({ CardRender->GetWorldLocation().X + 130.0f,CardRender->GetWorldLocation().Y + 158.0f, CardRender->GetWorldLocation().Z });
}

void ACard::SetCardType(ECardColor _CardTye, int _CardStep)
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