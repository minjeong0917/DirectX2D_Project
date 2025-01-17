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
    CardNameText->SetWorldLocation({ CardRender->GetWorldLocation().X - 85.0f ,CardRender->GetWorldLocation().Y + 160.0f,CardRender->GetWorldLocation().Z });
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

void ACard::SetCardNameText(std::string _Text)
{
    if (CardNameText != nullptr)
    {
        CardNameText->SetText(_Text);
    }
}

void ACard::SetTextActive(bool _IsActive)
{
    if (CardNameText != nullptr)
    {
        CardNameText->SetActive(_IsActive);
    }
}