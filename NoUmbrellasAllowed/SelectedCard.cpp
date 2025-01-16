#include "PreCompile.h"
#include "BookPageInfo.h"

#include "SelectedCard.h"
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

ASelectedCard::ASelectedCard()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

    SelectedCardRender = CreateDefaultSubObject<USpriteRenderer>();
    SelectedCardRender->SetSprite("Blue", 0);
    SelectedCardRender->SetAutoScaleRatio(3.0f);
    SelectedCardRender->SetupAttachment(RootComponent);
    



}

ASelectedCard::~ASelectedCard()
{
}
void ASelectedCard::BeginPlay()
{
    AActor::BeginPlay();

    {
        CardNameText = GetWorld()->GetHUD()->CreateWidget<UFontWidget>(1);

        CardNameText->SetWorldLocation({ 200, 300 });
        CardNameText->SetFont("PF", 25.0f, TColor<unsigned char>(97, 76, 45, 255));
        CardNameText->SetText("완벽한 상태");
    }
}


void ASelectedCard::Tick(float _DeltaTime)
{
    AActor::Tick(_DeltaTime);

    std::shared_ptr<class ACameraActor> Camera = GetWorld()->GetCamera(0);
    FVector MousePos = Camera->ScreenMousePosToWorldPos();

    SelectedCardRender->SetWorldLocation({ MousePos.X + 8.0f, MousePos.Y - SelectedCardRender->GetWorldScale3D().hY(), -200.0f});

    CardNameText->SetWorldLocation({ MousePos.X -80.0f, MousePos.Y+70.0f, -200.0f });
}


void ASelectedCard::SetCardNameText(std::string _Text)
{
    if (CardNameText != nullptr)
    {
        CardNameText->SetText(_Text);
    }
}

void ASelectedCard::SetTextActive(bool _IsActive)
{
    if (CardNameText != nullptr)
    {
        CardNameText->SetActive(_IsActive);
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