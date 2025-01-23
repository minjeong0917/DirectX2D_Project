#include "PreCompile.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/Collision.h>
#include "Slot.h"
#include <EnginePlatform/EngineInput.h>

ASlot::ASlot()
{
    std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
    RootComponent = Default;

    SlotRender = CreateDefaultSubObject<USpriteRenderer>();
    SlotRender->SetSprite("Inventory", 1);
    SlotRender->SetAutoScaleRatio(3.0f);
    SlotRender->SetupAttachment(RootComponent);

    SlotCollision = CreateDefaultSubObject<UCollision>();
    SlotCollision->SetCollisionProfileName("Slot");
    SlotCollision->SetScale3D({ 0.8f,0.8f,1.0f });
    SlotCollision->SetRelativeLocation({ 0.0f,0.5f,0.0f });
    SlotCollision->SetupAttachment(SlotRender);

    SlotCollision->SetCollisionStay([this](UCollision* _This, UCollision* _Other)
        {
            this->OnCollisionStay(_This, _Other);
        });
    SlotCollision->SetCollisionEnd([this](UCollision* _This, UCollision* _Other)
        {
            this->OnCollisionEnd(_This, _Other);

        });


}

ASlot::~ASlot()
{
}

void ASlot::OnCollisionStay(UCollision* _This, UCollision* _Other)
{
    SlotRender->SetSprite("Inventory", 2);
}

void ASlot::OnCollisionEnd(UCollision* _This, UCollision* _Other)
{
    SlotRender->SetSprite("Inventory", 1);

}
