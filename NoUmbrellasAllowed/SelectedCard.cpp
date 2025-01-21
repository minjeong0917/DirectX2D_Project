#include "PreCompile.h"
#include "BookPageInfo.h"

#include "SelectedCard.h"
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

ASelectedCard::ASelectedCard()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

    SelectedCardRender = CreateDefaultSubObject<USpriteRenderer>();
    SelectedCardRender->SetSprite("Blue", 0);
    SelectedCardRender->SetAutoScaleRatio(3.0f);
    SelectedCardRender->SetupAttachment(RootComponent);


    SelectedCardCollision = CreateDefaultSubObject<UCollision>();
    SelectedCardCollision->SetCollisionProfileName("SelectedCard");
    SelectedCardCollision->SetRelativeLocation({ 0.0f, 0.5f,0.0f });
    SelectedCardCollision->SetupAttachment(SelectedCardRender);

    CardNameText = CreateDefaultSubObject<UFontRenderer>();
    CardNameText->SetFont("PF", 25.0f, TColor<unsigned char>(97, 76, 45, 255));
    CardNameText->SetupAttachment(RootComponent);

    
    CardExplainText = CreateDefaultSubObject<UFontRenderer>();
    CardExplainText->SetFont("PF", 19.0f, TColor<unsigned char>(125, 75, 71, 255), FW1_CENTER);
    CardExplainText->SetupAttachment(RootComponent);


    CardPercentText = CreateDefaultSubObject<UFontRenderer>();
    CardPercentText->SetFont("PF", 18.0f, TColor<unsigned char>(148, 65, 33, 255),FW1_RIGHT);
    CardPercentText->SetupAttachment(RootComponent);
}

ASelectedCard::~ASelectedCard()
{
}

void ASelectedCard::BeginPlay()
{
    AActor::BeginPlay();

}





void ASelectedCard::Tick(float _DeltaTime)
{
    AActor::Tick(_DeltaTime);

    std::shared_ptr<class ACameraActor> Camera = GetWorld()->GetCamera(0);
    FVector MousePos = Camera->ScreenMousePosToWorldPos();

    SelectedCardRender->SetWorldLocation({ MousePos.X + 8.0f, MousePos.Y - SelectedCardRender->GetWorldScale3D().hY(), -200.0f});

    CardNameText->SetWorldLocation({ MousePos.X - 90.0f, MousePos.Y + 70.0f, -200.0f });
    CardExplainText->SetWorldLocation({ MousePos.X + 10.0f, MousePos.Y + 10.0f, -200.0f });
    CardPercentText->SetWorldLocation({ MousePos.X + 135.0f, MousePos.Y + 65.0f, -200.0f });
}


void ASelectedCard::SetCardNameText(std::string _Text)
{
    if (CardNameText != nullptr)
    {
        CardNameText->SetText(_Text);
    }

}
void ASelectedCard::ChangeTextSize(float _Size)
{
    if (CardNameText != nullptr)
    {
        CardNameText->SetFont("PF", _Size, TColor<unsigned char>(97, 76, 45, 255));
    }

}

void ASelectedCard::SetCardExplainText(std::string _Text)
{
    if (CardExplainText != nullptr)
    {
        CardExplainText->SetText(_Text);
    }
}
void ASelectedCard::SetCardPercentText(std::string _Text)
{
    if (CardPercentText != nullptr)
    {
        CardPercentText->SetText(_Text);
    }
}
void ASelectedCard::SetTextActive(bool _IsActive)
{
    if (CardNameText != nullptr)
    {
        CardNameText->SetActive(_IsActive);
        CardExplainText->SetActive(_IsActive);
        CardPercentText->SetActive(_IsActive);
    }
}


void ASelectedCard::SetCardType(ECardColor _CardTye, int _CardStep)
{
    switch (_CardTye)
    {
    case ECardColor::Blue:
        SelectedCardRender->SetSprite("Blue", _CardStep);
        break;
    case ECardColor::Gray:
        SelectedCardRender->SetSprite("Gray", _CardStep);
        break;
    case ECardColor::Green:
        SelectedCardRender->SetSprite("Green", _CardStep);
        break;
    default:
        break;
    }


}