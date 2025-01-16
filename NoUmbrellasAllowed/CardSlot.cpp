#include "PreCompile.h"

#include "CardSlot.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EnginePlatform/EngineInput.h>

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
