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


void ASelectedCard::Tick(float _DeltaTime)
{
    AActor::Tick(_DeltaTime);

    std::shared_ptr<class ACameraActor> Camera = GetWorld()->GetCamera(0);
    FVector MousePos = Camera->ScreenMousePosToWorldPos();

    SelectedCardRender->SetWorldLocation({ MousePos.X + 8.0f, MousePos.Y - SelectedCardRender->GetWorldScale3D().hY(), -200.0f});
}

void ASelectedCard::SetCardType(ECardType _CardTye, int _CardStep)
{
    switch (_CardTye)
    {
    case ECardType::Blue:
        SelectedCardRender->SetSprite("Blue", _CardStep);
        break;
    case ECardType::Gray:
        SelectedCardRender->SetSprite("Gray", _CardStep);
        break;
    case ECardType::Green:
        SelectedCardRender->SetSprite("Green", _CardStep);
        break;
    default:
        break;
    }


}
