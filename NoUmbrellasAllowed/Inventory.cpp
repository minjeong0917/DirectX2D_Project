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
#include "CardInfo.h"


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

    FVector StartLoc = { 1390.0f, -200.0f, -131.0f };
    FVector IterLoc = { 0.0f , -48.0f, -2.0f };

    for (int i = 0; i < 5; i++)
    {
        MerchandiseCard = GetWorld()->SpawnActor<ACard>();
        MerchandiseCard->SetActorLocation({ StartLoc.X, StartLoc.Y + IterLoc.Y * i, StartLoc.Z + IterLoc.Z * i });
        MerchandiseCard->SetActive(false);
        AllMerchandiseCard.push_back(MerchandiseCard);
        AllMerchandiseCardLocations.push_back({ StartLoc.X, StartLoc.Y + IterLoc.Y * i, StartLoc.Z + IterLoc.Z * i });
    }

    MerchandiseNameText = CreateDefaultSubObject<UFontRenderer>();
    MerchandiseNameText->SetFont("DungGeunMo", 26.0f, TColor<unsigned char>(245, 222, 96, 255), FW1_CENTER);
    MerchandiseNameText->SetWorldLocation({ 0.22f, 0.978f, -0.2f });
    MerchandiseNameText->SetActive(false);
    MerchandiseNameText->SetupAttachment(InvenRender);

    InvenText1 = CreateDefaultSubObject<UFontRenderer>();
    InvenText1->SetFont("DungGeunMo", 20.0f, TColor<unsigned char>(81, 64, 60, 255), FW1_CENTER);
    InvenText1->SetWorldLocation({ 0.15f, 0.61f, -0.01f });
    InvenText1->SetText("감정가");
    InvenText1->SetActive(false);
    InvenText1->SetupAttachment(InvenRender);

    InvenText2 = CreateDefaultSubObject<UFontRenderer>();
    InvenText2->SetFont("DungGeunMo", 20.0f, TColor<unsigned char>(81, 64, 60, 255), FW1_CENTER);
    InvenText2->SetWorldLocation({ 0.15f, 0.51f, -0.01f });
    InvenText2->SetText("매입가");
    InvenText2->SetActive(false);
    InvenText2->SetupAttachment(InvenRender);

    TotalPriceText = CreateDefaultSubObject<UFontRenderer>();
    TotalPriceText->SetFont("DungGeunMo", 32.0f, TColor<unsigned char>(75, 71, 70, 255), FW1_RIGHT);
    TotalPriceText->SetWorldLocation({ 0.43f, 0.57f, -0.01f });
    TotalPriceText->SetText("0");
    TotalPriceText->SetActive(false);
    TotalPriceText->SetupAttachment(InvenRender);

    BuyPriceText = CreateDefaultSubObject<UFontRenderer>();
    BuyPriceText->SetFont("DungGeunMo", 32.0f, TColor<unsigned char>(75, 71, 70, 255), FW1_RIGHT);
    BuyPriceText->SetWorldLocation({ 0.43f, 0.47f, -0.01f });
    BuyPriceText->SetText("0");
    BuyPriceText->SetActive(false);
    BuyPriceText->SetupAttachment(InvenRender);

    ItemRenderer = CreateDefaultSubObject<USpriteRenderer>();
    ItemRenderer->SetSprite("Inventory", 0);
    ItemRenderer->SetAutoScaleRatio(2.5f);
    ItemRenderer->SetWorldLocation({ 1383.0f, 146.0f, -133.0f });
    ItemRenderer->SetActive(false);
    ItemRenderer->SetupAttachment(RootComponent);

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
        InvenText1->SetActive(true);
        InvenText2->SetActive(true);
        TotalPriceText->SetActive(true);
        BuyPriceText->SetActive(true);
        ItemRenderer->SetActive(true);


        ShowItemInfo(CurClickIndex);
        MerchandiseCardCheck(CurClickIndex, _DeltaTime);
    }
    else if(InvenRender->GetWorldLocation().X > 1230.0f)
    {
        MerchandiseNameText->SetActive(false);
        InvenText1->SetActive(false);
        InvenText2->SetActive(false);
        TotalPriceText->SetActive(false);
        BuyPriceText->SetActive(false);
        ItemRenderer->SetActive(false);

        for (int i = 0; i < AllMerchandiseCard.size(); i++)
        {
            AllMerchandiseCard[i]->SetActive(false);
            AllMerchandiseCard[i]->SetTextActive(false);
        }

    }
}

void AInventory::MerchandiseCardCheck(int _Index,float _DeltaTime)
{
    int TotalCardCount = InvenInfo::GetInst().GetAllSlotInfos()[_Index].TotalCardCount;
    for (int i = 0; i < TotalCardCount; i++)
    {
        if (AllMerchandiseCard[i]->GetIsEnter() == false && InvenRender->GetWorldLocation().X <= 650.0f)
        {
            if (IsCardHover == false && AllMerchandiseCard[i]->GetActorLocation().Y <= AllMerchandiseCardLocations[i].Y)
            {
                AllMerchandiseCard[i]->SetActorLocation({ 811.0f,-200.0f +  - 48.0f * i, AllMerchandiseCardLocations[i].Z});
                AllMerchandiseCard[i]->SetCollisionActive(true);

                continue;
            }
        }

        if (AllMerchandiseCard[i]->GetIsEnter() == true && IsCardHover == false)
        {
            IsCardHover = true;

            HoverCardNum = i;
            for (int i = 0; i < TotalCardCount; i++)
            {
                if (i == HoverCardNum)
                {
                    continue;
                }
                AllMerchandiseCard[i]->SetCollisionActive(false);

            }
        }

    }

    if (IsCardHover == true)
    {

        if (AllMerchandiseCard[HoverCardNum]->GetActorLocation().Y < AllMerchandiseCardLocations[HoverCardNum].Y + 80.0f && AllMerchandiseCard[HoverCardNum]->GetIsEnter() == true)
        {
            AllMerchandiseCard[HoverCardNum]->AddActorLocation({ 0.0f, 800.0f * _DeltaTime, 0.0f });
            AllMerchandiseCard[HoverCardNum]->SetCollisionYScale(0.5f);
            AllMerchandiseCard[HoverCardNum]->SetCollisionYLocation(0.4f);
        }
        else if (AllMerchandiseCard[HoverCardNum]->GetActorLocation().Y >= AllMerchandiseCardLocations[HoverCardNum].Y && AllMerchandiseCard[HoverCardNum]->GetIsEnter() == false)
        {

            AllMerchandiseCard[HoverCardNum]->AddActorLocation({ 0.0f, -1000.0f * _DeltaTime, 0.0f });
            AllMerchandiseCard[HoverCardNum]->SetCollisionYScale(0.0f);
            AllMerchandiseCard[HoverCardNum]->SetCollisionYLocation(0.15f);

        }
        else if (AllMerchandiseCard[HoverCardNum]->GetActorLocation().Y <= AllMerchandiseCardLocations[HoverCardNum].Y)
        {
            IsCardHover = false;
        }

    }
}

void AInventory::ShowItemInfo(int _Index)
{
    std::string MerchandiseName = InvenInfo::GetInst().GetAllSlotInfos()[_Index].MerchandiseName;
    int TotalCardCount = InvenInfo::GetInst().GetAllSlotInfos()[_Index].TotalCardCount;
    int TotalCardPrice = InvenInfo::GetInst().GetAllSlotInfos()[_Index].CardPrice;
    int BuyPrice = InvenInfo::GetInst().GetAllSlotInfos()[_Index].BuyPrice;
    std::string SpriteName = InvenInfo::GetInst().GetAllSlotInfos()[_Index].SpriteName;
    int SpriteIndex = InvenInfo::GetInst().GetAllSlotInfos()[_Index].SpriteIndex;

    for (int i = 0; i < TotalCardCount; i++)
    {
        ECardColor CardColor = InvenInfo::GetInst().GetAllSlotInfos()[_Index].Cards[i].CardColor;
        ECardType CardType = InvenInfo::GetInst().GetAllSlotInfos()[_Index].Cards[i].CardType;

        int Step = InvenInfo::GetInst().GetAllSlotInfos()[_Index].Cards[i].CardStep;
        int CardNum = InvenInfo::GetInst().GetAllSlotInfos()[_Index].Cards[i].CardNum;

        CardInfo::GetInst().SetCardType(CardType);
        CardInfo::GetInst().CardTypeInfo(CardType);

        std::string Name = CardInfo::GetInst().GetAllCardType()[CardNum].CardName;
        std::string Explain = CardInfo::GetInst().GetAllCardType()[CardNum].CardExplanation;
        std::string Percent = CardInfo::GetInst().GetAllCardType()[CardNum].CardPercentText;

        AllMerchandiseCard[i]->SetActive(true);
        AllMerchandiseCard[i]->SetCardColor(CardColor, Step);
        AllMerchandiseCard[i]->SetTextActive(true);

        AllMerchandiseCard[i]->SetCardNameText(Name);
        AllMerchandiseCard[i]->SetCardExplainText(Explain);
        AllMerchandiseCard[i]->SetCardPercentText(Percent);

    }

    ItemRenderer->SetSprite(SpriteName, SpriteIndex);
    MerchandiseNameText->SetText(MerchandiseName);
    BuyPriceText->SetText(std::to_string(BuyPrice));
    TotalPriceText->SetText(std::to_string(TotalCardPrice));
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

        FVector StartLoc = { 1390.0f, -200.0f, -131.0f };
        FVector IterLoc = { 0.0f , -48.0f, -2.0f };

        for (int i = 0; i < 5; i++)
        {
            AllMerchandiseCard[i]->SetActorLocation({StartLoc.X, StartLoc.Y + IterLoc.Y * i, StartLoc.Z + IterLoc.Z * i});
            AllMerchandiseCardLocations[i] = { StartLoc.X, StartLoc.Y + IterLoc.Y * i, StartLoc.Z + IterLoc.Z * i };
        }

    }

    if (IsClick == 1 && InvenRender->GetWorldLocation().X > 950.0f)
    {
        InvenRender->AddWorldLocation({ -1000.f * _DeltaTime , 0.0f,0.0f });
        ItemRenderer->AddWorldLocation({ -1000.f * _DeltaTime , 0.0f,0.0f });
        for (int i = 1; i < 6; i++)
        {
            AllInvenSlotRender[i - 1]->AddWorldLocation({ -1000.f * _DeltaTime , 0.0f,0.0f });
        }

        for (int i = 0; i < 10; i++)
        {
            AllSlots[i]->AddActorLocation({ -1000.f * _DeltaTime , 0.0f,0.0f });
        }

        for (int i = 0; i < 5; i++)
        {
            AllMerchandiseCard[i]->AddActorLocation({ -1000.f * _DeltaTime , 0.0f,0.0f });
        }
            
    }
    else if (IsClick == 0 && InvenRender->GetWorldLocation().X < 1230.0f)
    {
        InvenRender->AddWorldLocation({ 1000.f * _DeltaTime , 0.0f,0.0f });
        ItemRenderer->AddWorldLocation({ 1000.f * _DeltaTime , 0.0f,0.0f });

        for (int i = 1; i < 6; i++)
        {
            AllInvenSlotRender[i - 1]->AddWorldLocation({ 1000.f * _DeltaTime , 0.0f,0.0f });
        }

        for (int i = 0; i < 10; i++)
        {
            AllSlots[i]->AddActorLocation({ 1000.f * _DeltaTime , 0.0f,0.0f });
        }
        for (int i = 0; i < 5; i++)
        {
            AllMerchandiseCard[i]->AddActorLocation({ 1000.f * _DeltaTime , 0.0f,0.0f });
        }

    }
    else if (IsClick == 2 && InvenRender->GetWorldLocation().X > 650.0f)
    {
        InvenRender->AddWorldLocation({ -1000.f * _DeltaTime , 0.0f,0.0f });
        ItemRenderer->AddWorldLocation({ -1000.f * _DeltaTime , 0.0f,0.0f });

        for (int i = 1; i < 6; i++)
        {
            AllInvenSlotRender[i - 1]->AddWorldLocation({ -1000.f * _DeltaTime , 0.0f,0.0f });
        }

        for (int i = 0; i < 10; i++)
        {
            AllSlots[i]->AddActorLocation({ -1000.f * _DeltaTime , 0.0f,0.0f });
        }
        for (int i = 0; i < 5; i++)
        {
            AllMerchandiseCard[i]->AddActorLocation({ -1000.f * _DeltaTime , 0.0f,0.0f });
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
