#include "PreCompile.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/Collision.h>
#include "Inventory.h"
#include <EnginePlatform/EngineInput.h>
#include "Slot.h"
#include "InvenInfo.h"

AInventory::AInventory()
{
    std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
    RootComponent = Default;

    InvenRender = CreateDefaultSubObject<USpriteRenderer>();
    InvenRender->SetSprite("Inventory", 0);
    InvenRender->SetAutoScaleRatio(3.0f);
    InvenRender->SetWorldLocation({ 1230.0f,-345.0f, -130.0f});
    //InvenRender->SetWorldLocation({ 650.0f,-345.0f, -130.0f});
    InvenRender->SetupAttachment(RootComponent);

    InvenButtonCollision = CreateDefaultSubObject<UCollision>();
    InvenButtonCollision->SetCollisionProfileName("InvenButton");
    InvenButtonCollision->SetScale3D({ 0.06f,0.18f,1.0f });
    InvenButtonCollision->SetRelativeLocation({ -0.47f, 0.48f, 0.0f });
    InvenButtonCollision->SetupAttachment(InvenRender);

    InvenButtonCollision->SetCollisionStay([this](UCollision* _This, UCollision* _Other)
        {
            this->OnCollisionStay(_This, _Other);
        });
    InvenButtonCollision->SetCollisionEnd([this](UCollision* _This, UCollision* _Other)
        {
            this->OnCollisionEnd(_This, _Other);

        });

    FVector StartPos = { 1037.0f,  224.3f };
    FVector IterPos = { 127.3f,  -119.6f };

    for (int y = 0; y < 5; y++)
    {
        for (int i = 0; i < 2; i++)
        {
            std::shared_ptr<class ASlot> Slot = GetWorld()->SpawnActor<ASlot>();
            Slot->SetActorLocation({ StartPos.X + IterPos.X * i , StartPos.Y + IterPos.Y * y ,-135.0f });
            AllSlots.push_back(Slot);
        }
    }



 
}

AInventory::~AInventory()
{
}
void AInventory::Tick(float _DeltaTime)
{
    AActor::Tick(_DeltaTime);
    ChangeLocation(_DeltaTime);

    for (int i = 0; i < InvenInfo::GetInst().GetAllSlotInfos().size(); i++)
    {
        if (InvenInfo::GetInst().GetAllSlotInfos()[i].MerchandiseName != "NONE")
        {
            std::string SpriteName = InvenInfo::GetInst().GetAllSlotInfos()[i].SpriteName;
            int Index =InvenInfo::GetInst().GetAllSlotInfos()[i].SpriteIndex;

            AllSlots[i]->SetSlotItemSetting(SpriteName, Index, {0.6f ,0.6f,1.0f});
            AllSlots[i]->SetItemActive(true);

            if (AllSlots[i]->GetIsStay() == true)
            {
                AllSlots[i]->SetSlotSprite(2);
            }
            if (AllSlots[i]->GetIsStay() == false)
            {
                AllSlots[i]->SetSlotSprite(1);
            }
        }
    }

}

void AInventory::ChangeLocation(float _DeltaTime)
{
    if (InvenRender->GetWorldLocation().X > 1230.0f)
    {
        InvenRender->SetWorldLocation({ 1230.0f,-345.0f, -130.0f });

        FVector StartPos = { 1037.0f,  224.3f };
        FVector IterPos = { 127.3f,  -119.6f };

        for (int y = 0; y < 5; y++)
        {
            for (int i = 0; i < 2; i++)
            {
                int index = y * 2 + i;
                AllSlots[index]->SetActorLocation({ StartPos.X + IterPos.X * i , StartPos.Y + IterPos.Y * y ,-135.0f });
            }
        }
    }

    if (IsClick == 1 && InvenRender->GetWorldLocation().X > 950.0f)
    {
        InvenRender->AddWorldLocation({ -800.f * _DeltaTime , 0.0f,0.0f });


        for (int i = 0; i < 10; i++)
        {
            AllSlots[i]->AddActorLocation({ -800.f * _DeltaTime , 0.0f,0.0f });
        }

    }
    else if (IsClick == 0 && InvenRender->GetWorldLocation().X < 1230.0f)
    {
        InvenRender->AddWorldLocation({ 800.f * _DeltaTime , 0.0f,0.0f });


        for (int i = 0; i < 10; i++)
        {
            AllSlots[i]->AddActorLocation({ 800.f * _DeltaTime , 0.0f,0.0f });
        }

    }
}


void AInventory::OnCollisionStay(UCollision* _This, UCollision* _Other)
{
    if (UEngineInput::IsUp(VK_LBUTTON))
    {
        if (IsClick == 0)
        {
            IsClick = 1;
        }
        else if (IsClick == 1)
        {
            IsClick = 0;
        }

    }

}


void AInventory::OnCollisionEnd(UCollision* _This, UCollision* _Other)
{

}
