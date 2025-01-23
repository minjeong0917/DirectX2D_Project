#include "PreCompile.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/Collision.h>
#include "Slot.h"
#include <EnginePlatform/EngineInput.h>
#include "InvenInfo.h"
ASlot::ASlot()
{
    std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
    RootComponent = Default;

    SlotRender = CreateDefaultSubObject<USpriteRenderer>();
    SlotRender->SetSprite("Inventory", 1);
    SlotRender->SetAutoScaleRatio(3.0f);
    SlotRender->SetupAttachment(RootComponent);

    SlotItemRender = CreateDefaultSubObject<USpriteRenderer>();
    SlotItemRender->SetSprite("Inventory", 1);
    SlotItemRender->SetAutoScale(false);
    SlotItemRender->SetScale3D({ 0.8f,0.8f,1.0f });
    SlotItemRender->SetRelativeLocation({ 0.0f,0.2f,0.0f });
    SlotItemRender->SetActive(false);
    SlotItemRender->SetupAttachment(SlotRender);

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


void ASlot::SetSlotItemSetting(std::string _SpriteName , int _Index, FVector _Scale)
{
    SlotItemRender->SetSprite(_SpriteName, _Index);
    SlotItemRender->SetRelativeScale3D(_Scale);
}


void ASlot::SetItemActive(bool _IsActive)
{
     SlotItemRender->SetActive(_IsActive);
}

void ASlot::SetSlotSprite(int _Index)
{
    SlotRender->SetSprite("Inventory", _Index);
}

void ASlot::OnCollisionStay(UCollision* _This, UCollision* _Other)
{
    IsStay = true;
}


void ASlot::OnCollisionEnd(UCollision* _This, UCollision* _Other)
{
    IsStay = false;
}
