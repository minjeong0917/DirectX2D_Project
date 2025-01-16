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

ACard::ACard()
{
    std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
    RootComponent = Default;

    CardRender = CreateDefaultSubObject<USpriteRenderer>();
    CardRender->SetSprite("Blue", 0);
    CardRender->SetAutoScaleRatio(3.0f);
    CardRender->SetupAttachment(RootComponent);


}

ACard::~ACard()
{
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