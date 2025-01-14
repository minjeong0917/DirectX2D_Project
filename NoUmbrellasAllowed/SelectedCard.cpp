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

ASelectedCard::ASelectedCard()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

    SelectedCardRender = CreateDefaultSubObject<USpriteRenderer>();
    SelectedCardRender->SetSprite("Card", 2);
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