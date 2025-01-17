#include "PreCompile.h"

#include "CardSlot.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/Collision.h>

ACardSlot::ACardSlot()
{
    std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
    RootComponent = Default;
    for (int i = 0; i < 6; i++)
    {
        CardSlotRender = CreateDefaultSubObject<USpriteRenderer>();
        CardSlotRender->SetSprite("CardCase", i);
        CardSlotRender->SetAutoScaleRatio(3.0f);
        AllCardSlotRender.push_back(CardSlotRender);
        AllCardSlotRender[i]->SetWorldLocation({-730.0f, -260.0f, -151.0f + i * (-2.0f)});
        CardSlotRender->SetupAttachment(RootComponent);
    }
    
    CardSlotCollision = CreateDefaultSubObject<UCollision>();
    CardSlotCollision->SetCollisionProfileName("CardSlot");
    CardSlotCollision->SetRelativeLocation({ 0.0f, 0.5f,0.0f });
    CardSlotCollision->SetupAttachment(AllCardSlotRender[0]);

    CardSlotCollision->SetCollisionEnter([this](UCollision* _This, UCollision* _Other)
        {
            this->OnCollisionEnter(_This, _Other);
        });
    CardSlotCollision->SetCollisionEnd([this](UCollision* _This, UCollision* _Other)
        {
            this->OnCollisionEnd(_This, _Other);

        });

    CardSlotInfoRender = CreateDefaultSubObject<USpriteRenderer>();
    CardSlotInfoRender->SetSprite("CardCase", 6);
    CardSlotInfoRender->SetAutoScaleRatio(3.0f);
    CardSlotInfoRender->SetWorldLocation({ -730.0f, -100.0f, -145.0f });
    CardSlotInfoRender->SetupAttachment(RootComponent);

}

ACardSlot::~ACardSlot()
{
}

void ACardSlot::Tick(float _DeltaTime)
{
    AActor::Tick(_DeltaTime);

    if (IsActive == true)
    {
        if (CardSlotInfoRender->GetTransformRef().WorldLocation.Y < 7.0f)
        {
            CardSlotInfoRender->AddWorldLocation({ 0.0f, 100.0f * _DeltaTime , 0.0f });
        }
    }
}

void ACardSlot::OnCollisionEnter(UCollision* _This, UCollision* _Other)
{
    IsEnter = true;
}

void ACardSlot::OnCollisionEnd(UCollision* _This, UCollision* _Other)
{
    IsEnter = false;
}

