#include "PreCompile.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/Collision.h>
#include "Inventory.h"
#include <EnginePlatform/EngineInput.h>
#include "Slot.h"
#include "InvenInfo.h"
#include <EngineCore/FontRenderer.h>
#include "Card.h"

AInventory::AInventory()
{
    std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
    RootComponent = Default;


    for (int i = 0; i < 5; i++)
    {
        InvenSlotRender = CreateDefaultSubObject<USpriteRenderer>();
        InvenSlotRender->SetSprite("Inventory", (i+1));
        InvenSlotRender->SetAutoScaleRatio(3.0f);
        InvenSlotRender->SetupAttachment(RootComponent);

        AllInvenSlotRender.push_back(InvenSlotRender);
        AllInvenSlotRender[i]->SetWorldLocation({ 1230.0f, -345.0f, -130.0f + (i+1) * (-2.0f) });
    }

    InvenRender = CreateDefaultSubObject<USpriteRenderer>();
    InvenRender->SetSprite("Inventory", 0);
    InvenRender->SetAutoScaleRatio(3.0f);
    InvenRender->SetWorldLocation({ 1230.0f,-345.0f, -130.0f});
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

    MerchandiseNameText = CreateDefaultSubObject<UFontRenderer>();
    MerchandiseNameText->SetFont("DungGeunMo", 26.0f, TColor<unsigned char>(245, 222, 96, 255), FW1_CENTER);
    MerchandiseNameText->SetWorldLocation({ 0.22f, 0.978f, -0.2f });
    //MerchandiseNameText->SetText("아무것도 없음");
    MerchandiseNameText->SetActive(false);
    MerchandiseNameText->SetupAttachment(InvenRender);

    //FVector StartLoc = { -720.0f, -38.0f, -152.0f };
    //FVector IterLoc = { 0.0f , -48.0f, -2.0f };

    //for (int i = 0; i < 5; i++)
    //{
    //    MerchandiseCard = GetWorld()->SpawnActor<ACard>();
    //    MerchandiseCard->SetActorLocation({ StartLoc.X, StartLoc.Y + IterLoc.Y * i, StartLoc.Z + IterLoc.Z * i });
    //    MerchandiseCard->SetActive(false);
    //    AllMerchandiseCard.push_back(MerchandiseCard);
    //    AllMerchandiseCardLocations.push_back({ StartLoc.X, StartLoc.Y + IterLoc.Y * i, StartLoc.Z + IterLoc.Z * i });
    //}

}

AInventory::~AInventory()
{

}
void AInventory::BeginPlay()
{
    AActor::BeginPlay();

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
                AllSlots[i]->SetSlotSprite(7);

                if (UEngineInput::IsUp(VK_LBUTTON))
                {
                    IsClick = 2;
                    CurClickIndex = i;
                }
            }
            if (AllSlots[i]->GetIsStay() == false)
            {
                AllSlots[i]->SetSlotSprite(6);
            }
        }
    }

    if (IsClick == 2)
    {
        MerchandiseNameText->SetActive(true);

        std::string MerchandiseName = InvenInfo::GetInst().GetAllSlotInfos()[CurClickIndex].MerchandiseName;
        MerchandiseNameText->SetText(MerchandiseName);
    }
    else
    {
        MerchandiseNameText->SetActive(false);
    }
}

void AInventory::ChangeLocation(float _DeltaTime)
{
    if (InvenRender->GetWorldLocation().X > 1230.0f)
    {
        InvenRender->SetWorldLocation({ 1230.0f,-345.0f, -130.0f });

        for (int i = 1; i < 6; i++)
        {
            AllInvenSlotRender[i-1]->SetWorldLocation({ 1230.0f, -345.0f, -130.0f + i * (-2.0f) });
        }

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
        InvenRender->AddWorldLocation({ -1000.f * _DeltaTime , 0.0f,0.0f });
        for (int i = 1; i < 6; i++)
        {
            AllInvenSlotRender[i - 1]->AddWorldLocation({ -1000.f * _DeltaTime , 0.0f,0.0f });
        }

        for (int i = 0; i < 10; i++)
        {
            AllSlots[i]->AddActorLocation({ -1000.f * _DeltaTime , 0.0f,0.0f });
        }
            
    }
    else if (IsClick == 0 && InvenRender->GetWorldLocation().X < 1230.0f)
    {
        InvenRender->AddWorldLocation({ 1000.f * _DeltaTime , 0.0f,0.0f });

        for (int i = 1; i < 6; i++)
        {
            AllInvenSlotRender[i - 1]->AddWorldLocation({ 1000.f * _DeltaTime , 0.0f,0.0f });
        }

        for (int i = 0; i < 10; i++)
        {
            AllSlots[i]->AddActorLocation({ 1000.f * _DeltaTime , 0.0f,0.0f });
        }

    }
    else if (IsClick == 2 && InvenRender->GetWorldLocation().X > 650.0f)
    {
        InvenRender->AddWorldLocation({ -1000.f * _DeltaTime , 0.0f,0.0f });

        for (int i = 1; i < 6; i++)
        {
            AllInvenSlotRender[i - 1]->AddWorldLocation({ -1000.f * _DeltaTime , 0.0f,0.0f });
        }

        for (int i = 0; i < 10; i++)
        {
            AllSlots[i]->AddActorLocation({ -1000.f * _DeltaTime , 0.0f,0.0f });
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
        else if (IsClick == 1 || IsClick == 2)
        {
            IsClick = 0;
        }

    }

}


void AInventory::OnCollisionEnd(UCollision* _This, UCollision* _Other)
{

}
