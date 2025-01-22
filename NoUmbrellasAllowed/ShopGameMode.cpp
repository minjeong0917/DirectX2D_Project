#include "PreCompile.h"

#include "ShopGameMode.h"
#include "UI.h"
#include "Customer.h"
#include "Calculator.h"
#include "CalculatorButton.h"
#include <EngineCore/EngineCore.h>
#include "Cursor.h"
#include "ItemShelf.h"
#include "CardSlot.h"
#include "Book.h"
#include "BookButton.h"
#include "BookSmall.h"
#include "Card.h"
#include "CardInfo.h"
#include "Merchandise.h"
#include "MerchandiseMaterial.h"
#include "MerchandiseInfo.h"
#include "PlayerBalloon.h"
#include "ConversationList.h"
#include "CardTotalPrice.h"

#include <EnginePlatform/EngineInput.h>
#include <EngineCore/CameraActor.h>
#include <EngineCore/EngineCamera.h>
#include <EngineCore/TimeEventComponent.h>
#include <EngineBase/EngineRandom.h>

AShopGameMode::AShopGameMode()
{
    TimeEventComponent = CreateDefaultSubObject<UTimeEventComponent>();

    GetWorld()->CreateCollisionProfile("Calculator");
    GetWorld()->CreateCollisionProfile("Cursor");
    GetWorld()->CreateCollisionProfile("ItemShelf");
    GetWorld()->CreateCollisionProfile("Merchandise");
    GetWorld()->CreateCollisionProfile("SelectedTool");
    GetWorld()->CreateCollisionProfile("BookMain");
    GetWorld()->CreateCollisionProfile("BookSmall");
    GetWorld()->CreateCollisionProfile("CardSlot");
    GetWorld()->CreateCollisionProfile("SelectedCard");
    GetWorld()->CreateCollisionProfile("Card");

    for (int i = 0; i < 14; i++)
    {
        GetWorld()->CreateCollisionProfile("Button_" + std::to_string(i));
        GetWorld()->LinkCollisionProfile("Button_" + std::to_string(i), "Cursor");
        GetWorld()->LinkCollisionProfile("Cursor","Button_" + std::to_string(i));

    }

    for (int i = 0; i < 6; i++)
    {
        GetWorld()->CreateCollisionProfile("Tools_" + std::to_string(i));
        GetWorld()->LinkCollisionProfile("Tools_" + std::to_string(i), "Cursor");

    }

    GetWorld()->LinkCollisionProfile("Calculator", "Cursor");
    GetWorld()->LinkCollisionProfile("ItemShelf", "Cursor");
    GetWorld()->LinkCollisionProfile("Merchandise", "SelectedTool");
    GetWorld()->LinkCollisionProfile("BookMain", "Cursor");
    GetWorld()->LinkCollisionProfile("BookSmall", "Cursor");
    GetWorld()->LinkCollisionProfile("BookSmall", "SelectedTool");
    GetWorld()->LinkCollisionProfile("CardSlot", "SelectedCard");
    GetWorld()->LinkCollisionProfile("Card", "Cursor");

    for (int i = 0; i < 4; i++)
    {
        GetWorld()->CreateCollisionProfile("BookButton_" + std::to_string(i));
        GetWorld()->LinkCollisionProfile("BookButton_" + std::to_string(i), "Cursor");
    }
    for (int i = 0; i <22; i++)
    {
        GetWorld()->CreateCollisionProfile("BookPage_" + std::to_string(i));
        GetWorld()->LinkCollisionProfile("BookPage_" + std::to_string(i), "Cursor");

    }
    // BackGround
    std::shared_ptr<class AUI> BackGround = GetWorld()->SpawnActor<AUI>();
    BackGround->SetUISprite("UI", 2);
    BackGround->SetUIScale3D({ 1920.0f, 1078.0f, 1.0f });
    BackGround->SetRelativeLocation({ 0.0f, -700.0f, 1000.0f });


    // Ocean
    std::shared_ptr<class AUI> Ocean = GetWorld()->SpawnActor<AUI>();
    Ocean->CreateAnimation("Idle", "Ocean", 3.0f, 0, 4, 0.2f);
    Ocean->ChangeAnimation("Idle");
    Ocean->SetRelativeLocation({ 0.0f, -250.0f, 999.0f });


    // Bridge
    std::shared_ptr<class AUI> Bridge = GetWorld()->SpawnActor<AUI>();
    Bridge->SetUISprite("UI", 1);
    Bridge->SetUIScale3D({ 1800.0f, 219.0f, 1.0f });
    Bridge->SetActorLocation({ 0.0f, -250.0f, 900.0f });

    // PlayerBalloons
    PlayerBalloon = GetWorld()->SpawnActor<APlayerBalloon>();
    PlayerBalloon->SetActive(false);

    // WalkCustomer
    for (int i = 0; i < 8; i++)
    {
        AllOutPeopleAni.push_back("WalkCustomer0" + std::to_string(i + 1));
    }

    WalkCustomer1 = GetWorld()->SpawnActor<AUI>();
    PeopleCreateAni(WalkCustomer1);

    WalkCustomer2 = GetWorld()->SpawnActor<AUI>();
    PeopleCreateAni(WalkCustomer2);


    // DoorDown
    DoorDown = GetWorld()->SpawnActor<AUI>();
    DoorDown->SetUISprite("UI", 6);
    DoorDown->SetUIScale3D({ 246.0f, 165.0f, 1.0f });
    DoorDown->SetActorLocation({ 0.0f, -260.0f, 500.0f });


    // DoorUp
    DoorUp = GetWorld()->SpawnActor<AUI>();
    DoorUp->SetUISprite("UI", 5);
    DoorUp->SetUIScale3D({ 252.0f, 363.0f, 1.0f });
    DoorUp->SetActorLocation({ 0.0f, -120.0f, 600.0f });


    // main
    std::shared_ptr<class AUI> Main = GetWorld()->SpawnActor<AUI>();
    Main->CreateAnimation("Idle", "Main", 3.0f, 0, 6, 0.2f);
    Main->ChangeAnimation("Idle");
    Main->SetRelativeLocation({ 0.0f, -540.0f, 11.0f });

    //Customer
    Customer = GetWorld()->SpawnActor<ACustomer>();
    Customer->SetActive(false);

    // Table
    std::shared_ptr<class AUI> Table = GetWorld()->SpawnActor<AUI>();
    Table->SetUISprite("UI", 4);
    Table->SetUIScale3D({ 1920.0f, 347.0f, 1.0f });
    Table->SetRelativeLocation({ 0.0f, -545.0f, -100.0f });

    ItemShelf = GetWorld()->SpawnActor<AItemShelf>();

    Merchandise = GetWorld()->SpawnActor<AMerchandise>();
    Merchandise->SetActive(false);

    MerchandiseMaterial = GetWorld()->SpawnActor<AMerchandiseMaterial>();
    MerchandiseMaterial->SetActive(false);

    CardSlot = GetWorld()->SpawnActor<ACardSlot>();
    CardSlot->SetActive(false);

    CardTotalPrice = GetWorld()->SpawnActor<ACardTotalPrice>();
    CardTotalPrice->SetActive(false);

    
    Book = GetWorld()->SpawnActor<ABook>();
    Book->SetActive(false);


    BookSmall = GetWorld()->SpawnActor<ABookSmall>();
 
    // Hue
    std::shared_ptr<class AUI> HueBodyAnimation = GetWorld()->SpawnActor<AUI>();
    HueBodyAnimation->CreateAnimation("Idle", "companion_idle_loop.png", 3.1f, 0, 13, 0.2f);
    HueBodyAnimation->ChangeAnimation("Idle");
    HueBodyAnimation->SetRelativeLocation({ 370.0f, -300.0f, -101.0f });

    Calculator = GetWorld()->SpawnActor<ACalculator>();

    // ToolsIcon
    std::shared_ptr<class AUI> ToolsIcon = GetWorld()->SpawnActor<AUI>();
    ToolsIcon->SetUISprite("ItemShelf", 0);
    ToolsIcon->SetUIScale3D({ 87.0f, 30.0f, 1.0f });
    ToolsIcon->SetRelativeLocation({ 0.0f, -450.0f, -151.0f });

    // OutLine   
    std::shared_ptr<class AUI> OutLine = GetWorld()->SpawnActor<AUI>();
    OutLine->SetUISprite("UI", 3);
    OutLine->SetUIScale3D({ 1920.0f, 1080.0f, 1.0f });
    OutLine->SetActorLocation({ 0.0f, -540.0f, -800.0f });

    Cursor = GetWorld()->SpawnActor<ACursor>();

    FVector StartLoc = { -720.0f, -38.0f, -152.0f };
    FVector IterLoc = {0.0f , -48.0f, -2.0f };

    for (int i = 0; i < 5; i++)
    {
        Card = GetWorld()->SpawnActor<ACard>();
        Card->SetActorLocation({ StartLoc.X, StartLoc.Y + IterLoc.Y * i, StartLoc.Z + IterLoc.Z * i });
        AllCardLocations.push_back({ StartLoc.X, StartLoc.Y + IterLoc.Y * i, StartLoc.Z + IterLoc.Z * i });
        Card->SetActive(false);
        AllCard.push_back(Card);
    }

    std::shared_ptr<ACameraActor> Camera = GetWorld()->GetMainCamera();
    Camera->SetActorLocation({ 0.0f, 0.0f, -1000.0f, 1.0f });
    Camera->GetCameraComponent()->SetZSort(0, true);

}

AShopGameMode::~AShopGameMode()
{
}

void AShopGameMode::BeginPlay()
{
    AActor::BeginPlay();
    UEngineRandom Random;


    {
        WalkCustomer1->SetRelativeLocation({ 840.0f, -300.0f, 800.0f });
        RandomPeopleAnimation(WalkCustomer1);
        float RandomApear = Random.Randomfloat(2.0f, 10.0f);
        WalkCustomer1->ApearTime = RandomApear;

    }
    {
        WalkCustomer2->SetRelativeLocation({ 900.0f,  -300.0f, -801.0f });
        WalkCustomer2->SetActorRotation({ 0.0f, 180.0f, 0.0f });
        WalkCustomer2->ChangeAnimation(AllOutPeopleAni[3]);

        float RandomApear = Random.Randomfloat(6.0f, 15.0f);
        WalkCustomer2->ApearTime = RandomApear;

    }
}

void AShopGameMode::Tick(float _DeltaTime)
{
    AActor::Tick(_DeltaTime);

    //UEngineDebug::OutPutString("FPS : " + std::to_string(1.0f / _DeltaTime));

    std::shared_ptr<class ACameraActor> Camera = GetWorld()->GetCamera(0);
    FVector MousePos = Camera->ScreenMousePosToWorldPos();
    Cursor->SetActorLocation({ MousePos.X + 8.0f,MousePos.Y - 30.0f, -1000.0f });


    PeopleMove(_DeltaTime, WalkCustomer1, true);
    PeopleMove(_DeltaTime, WalkCustomer2, false);



    // TestCode
    if (UEngineInput::IsPress('I'))
    {
        IsOut = true;
    }

    // Customer - InOut
    if (IsOut == true)
    {
        CustomerOut(_DeltaTime);
    }
    if (IsOut == false)
    {
        NotExistCustomerTime += _DeltaTime;
        if(NotExistCustomerTime > 3.0f)
        {
            CustomerEnter(_DeltaTime);
            if (IsExistCustomer == true)
            {
                if (IsMerchandisActive == false)
                {
                    MerchandiseActive(_DeltaTime);
                }
                else if (IsMerchandisActive == true)
                {
                    if (CurPrice < TotalPrice)
                    {
                        CurPrice += 1;
                    }
                    else if (CurPrice > TotalPrice)
                    {
                        CurPrice -= 1;
                    }
                    CardTotalPrice->SetPrice(CurPrice);
                }

                if (Merchandise->GetActorLocation().Y > -100.0f)
                {
                    //Merchandise->PlusAlpha(_DeltaTime);
                    Merchandise->AddActorLocation({ 0.0f, -1.0f * _DeltaTime * 100 , 0.0f });
                    MerchandiseMaterial->AddActorLocation({ 0.0f, -1.0f * _DeltaTime * 100 , 0.0f });
                }
            }
        }
    }

    // Cursor - Active
    if (ItemShelf != nullptr)
    {
        if (false == ItemShelf->GetIsToolsClick() || Book->GetIsEnter() == true)
        {
            Cursor->SetRenderActive(true);
        }
        else if (true == ItemShelf->GetIsToolsClick() || Book->GetIsEnter() == false)
        {
            Cursor->SetRenderActive(false);
        }
    }

    // Cursor - Active
    if (Book->GetIsDrawCard() == false)
    {
        Cursor->SetActive(true);
    }
    else if (Book->GetIsDrawCard() == true)
    {
        Cursor->SetActive(false);
    }


    CardCompareAndChange(_DeltaTime);
    MerchandiseCardCheck(_DeltaTime);

  
    // Book - Active
    if (Book->GetIsBack() == true)
    {
        Book->SetPage0();
        Book->SetActive(false);
        BookSmall->SetRenderActive(true);
        Book->SetButtonActive(false);
        Book->SetIsBack(false);
        Book->SetButtonActive(false);
    } 
    else if ((Merchandise->GetIsEnter() == true && Merchandise->IsActive() == true && ItemShelf->IsSelectedToolActive() == true) || (BookSmall->GetIsEnter() == true && UEngineInput::IsDown(VK_LBUTTON)))
    {
        Book->SetActive(true);
        BookSmall->SetRenderActive(false);
        Book->SetButtonActive(true);
        Book->SetButtonActive(true);
    }


    if (Merchandise->GetIsEnter() == false || ItemShelf->IsSelectedToolActive() == false)
    {
        MerchandiseMaterial->SetActive(false);
    }
    
    if (Merchandise->GetIsEnter() == true && ItemShelf->IsSelectedToolActive() == true)
    {
        MerchandiseCheck = true;
        if (ItemShelf->GetCurToolIndex() == 5)
        {
            MerchandiseMaterial->SetActive(true);
        }
    }
    else
    {
        MerchandiseCheck = false;

    }
}

void AShopGameMode::MerchandiseCardCheck(float _DeltaTime)
{
    for (int i = 0; i < MerchandiseInfo::GetInst().GetAllBasicCard().size(); i++)
    {
        if (AllCard[i]->GetIsEnter() == false)
        {
            if (IsCardHover == false && AllCard[i]->GetActorLocation().Y <= AllCardLocations[i].Y)
            {
                AllCard[i]->SetActorLocation(AllCardLocations[i]);
                AllCard[i]->SetCollisionActive(true);


                continue;
            }
        }
        if (AllCard[i]->GetIsEnter() == true && IsCardHover == false)
        {
            IsCardHover = true;

            HoverCardNum = i;
            for (int i = 0; i < MerchandiseInfo::GetInst().GetAllBasicCard().size(); i++)
            {
                if (i == HoverCardNum)
                {
                    continue;
                }
                AllCard[i]->SetCollisionActive(false);

            }
        }

    }

    if (IsCardHover == true)
    {


        if (AllCard[HoverCardNum]->GetActorLocation().Y < AllCardLocations[HoverCardNum].Y + 80.0f && AllCard[HoverCardNum]->GetIsEnter() == true)
        {
            AllCard[HoverCardNum]->AddActorLocation({ 0.0f, 800.0f * _DeltaTime, 0.0f });
            AllCard[HoverCardNum]->SetCollisionYScale(0.5f );
            AllCard[HoverCardNum]->SetCollisionYLocation(0.4f);
        } 
        else if (AllCard[HoverCardNum]->GetActorLocation().Y >= AllCardLocations[HoverCardNum].Y && AllCard[HoverCardNum]->GetIsEnter() == false)
        {
   
            AllCard[HoverCardNum]->AddActorLocation({ 0.0f, -1000.0f * _DeltaTime, 0.0f });
            AllCard[HoverCardNum]->SetCollisionYScale(0.0f);
            AllCard[HoverCardNum]->SetCollisionYLocation(0.15f);

        }
        else if (AllCard[HoverCardNum]->GetActorLocation().Y <= AllCardLocations[HoverCardNum].Y)
        {
            IsCardHover = false;
        }

    }
}

void AShopGameMode::CardCompareAndChange(float _DeltaTime)
{
    // Card Compare
    for (int i = 0; i < MerchandiseInfo::GetInst().GetAllBasicCard().size(); i++)
    {
        if (CardInfo::GetInst().GetCardType() == MerchandiseInfo::GetInst().GetAllBasicCard()[i].CardType)
        {
            if (IsCardHover == false)
            {
                if (Book->GetIsDrawCard() == false && AllCard[i]->GetActorLocation().Y <= AllCardLocations[i].Y)
                {
                    AllCard[i]->SetActorLocation(AllCardLocations[i]);
                    continue;
                }

                if (Book->GetIsDrawCard() == true && AllCard[i]->GetActorLocation().Y < AllCardLocations[i].Y + 50.0f)
                {
                    AllCard[i]->AddActorLocation({ 0.0f, 500.0f * _DeltaTime, 0.0f });

                    ChangeCardNum = i;

                }
                if (IsCardChange == false && Book->GetIsDrawCard() == false && AllCard[i]->GetActorLocation().Y > AllCardLocations[i].Y)
                {
                    AllCard[i]->AddActorLocation({ 0.0f, -500.0f * _DeltaTime, 0.0f });
                }
            }
        }
    }


    // Card Change
    if (CardSlot->GetIsEnter() == true && Book->GetIsDrawCard() == true)
    {
        int CardNum = MerchandiseInfo::GetInst().GetAllBasicCard()[ChangeCardNum].CardNameNum;
        std::string MerchandiseCardName = CardInfo::GetInst().GetAllCardType()[CardNum].CardName;
        ECardType CardType = CardInfo::GetInst().GetCardType();
        int CardIndex = Book->GetCurClickNum();


        if (Book->GetCurCardName() != MerchandiseCardName && UEngineInput::IsUp(VK_LBUTTON))
        {
            IsCardChange = true;

            PlayerBalloon->SetActive(true);
            ConversationList::GetInst().SetPlayerConverastion(CardType, CardIndex);
            PlayerBalloon->SetPlayerBalloonAndText();
        }
    }

    if (IsCardChange == true)
    {

        CardChangeTime += _DeltaTime;

        if (CardChangeTime < 1.0f && Book->GetIsDrawCard() == false && AllCard[ChangeCardNum]->GetActorLocation().Y > AllCardLocations[ChangeCardNum].Y)
        {
            AllCard[ChangeCardNum]->AddActorLocation({ 0.0f, -1000.0f * _DeltaTime, 0.0f });
        }
        else if (CardChangeTime > 1.0f && CardChangeTime < 2.0f && AllCard[ChangeCardNum]->GetActorLocation().Y < AllCardLocations[ChangeCardNum].Y + 100.0f)
        {
            int CardNum = Book->GetCurClickNum();
            TotalPrice = CardTotalPrice->TotalPriceCheck();

            ECardType CardType = CardInfo::GetInst().GetCardType();

            CardInfo::GetInst().SetCardType(CardType);
            CardInfo::GetInst().CardTypeInfo(CardType);

            MerchandiseInfo::GetInst().SetCardNameNum(ChangeCardNum, CardNum);
            std::string Name = CardInfo::GetInst().GetAllCardType()[CardNum].CardName;
            std::string Explain = CardInfo::GetInst().GetAllCardType()[CardNum].CardExplanation;
            std::string Percent = CardInfo::GetInst().GetAllCardType()[CardNum].CardPercentText;


            float ChangeTextSize = CardInfo::GetInst().GetAllCardType()[CardNum].CardNameTextSize;

            AllCard[ChangeCardNum]->SetCardNameText(Name);
            AllCard[ChangeCardNum]->SetCardExplainText(Explain);
            AllCard[ChangeCardNum]->SetCardPercentText(Percent);
            AllCard[ChangeCardNum]->ChangeTextSize(ChangeTextSize);

            AllCard[ChangeCardNum]->AddActorLocation({ 0.0f, 1000.0f * _DeltaTime, 0.0f });

        }
        else if (CardChangeTime > 2.0f && AllCard[ChangeCardNum]->GetActorLocation().Y >= AllCardLocations[ChangeCardNum].Y + 50.0f)
        {
            IsCardChange = false;
            CardChangeTime = 0.0f;
            PlayerBalloon->SetActive(false);
        }

    }

}


void AShopGameMode::MerchandiseActive(float _DeltaTime)
{
    MerchandiseInfo::GetInst().SetMerchandiseInfo(false, EMerchandiseType::BAG, 0);
    Merchandise->SetActive(true);
    MerchandiseMaterial->SetActive(true);
    Merchandise->SetIsApear(true);

    CardSlot->SetActive(true);
    CardTotalPrice->SetActive(true);
    
    TotalPrice = CardTotalPrice->TotalPriceCheck();

    CardTotalPrice->SetPrice(CurPrice);
    CardSlot->IsActive = true;
    IsMerchandisActive = true;

    for (int i = 0; i < MerchandiseInfo::GetInst().GetAllBasicCard().size(); i++)
    {
        AllCard[i]->SetActive(true);
        AllCard[i]->SetCardType(MerchandiseInfo::GetInst().GetAllBasicCard()[i].CardColor, MerchandiseInfo::GetInst().GetAllBasicCard()[i].CardStep);

        AllCard[i]->SetTextActive(true);

        CardInfo::GetInst().SetCardType(MerchandiseInfo::GetInst().GetAllBasicCard()[i].CardType);
        CardInfo::GetInst().CardTypeInfo(MerchandiseInfo::GetInst().GetAllBasicCard()[i].CardType);

        int CardNum = MerchandiseInfo::GetInst().GetAllBasicCard()[i].CardNameNum;

        std::string Name = CardInfo::GetInst().GetAllCardType()[CardNum].CardName;
        std::string Explain = CardInfo::GetInst().GetAllCardType()[CardNum].CardExplanation;
        std::string Percent = CardInfo::GetInst().GetAllCardType()[CardNum].CardPercentText;

        AllCard[i]->SetCardNameText(Name);
        AllCard[i]->SetCardExplainText(Explain);
        AllCard[i]->SetCardPercentText(Percent);
    }





}


void AShopGameMode::PeopleMove(float _DeltaTime, std::shared_ptr<class AUI> _People, bool _IsRight)
{
    UEngineRandom Random;

    if (_IsRight == true)
    {
        if (_People->GetActorTransform().WorldLocation.X > -2000.0f)
        {
            _People->CurApearTime += _DeltaTime;
            if (_People->CurApearTime > _People->ApearTime)
            {
                _People->IsApear = true;
            }

            if (_People->IsApear == true)
            {
                _People->AddRelativeLocation({ (-1.0f) * _DeltaTime * CustomerSpeed, 0.0f, 0.0f });
            }
        }
        else if (_People->GetActorTransform().WorldLocation.X < -2000.0f)
        {
            _People->IsApear = false;
            _People->SetActorLocation({ 0.0f, 0.0f, 0.0f });

            float RandomApear = Random.Randomfloat(1.0f, 20.0f);
            _People->ApearTime = RandomApear;

            RandomPeopleAnimation(_People);
            _People->CurApearTime = 0.0f;
        }
    }

    if (_IsRight == false)
    {
        if (_People->GetActorTransform().WorldLocation.X < 2000.0f)
        {
            _People->CurApearTime += _DeltaTime;
            if (_People->CurApearTime > _People->ApearTime)
            {
                _People->IsApear = true;
            }

            if (_People->IsApear == true)
            {

                _People->AddRelativeLocation({ (1.0f) * _DeltaTime * CustomerSpeed, 0.0f, 0.0f });

            }
        }
        if (_People->GetActorTransform().WorldLocation.X > 2000.0f)
        {
            _People->IsApear = false;
            _People->SetActorLocation({ 0.0f,  0.0f, 0.0f });

            float RandomApear = Random.Randomfloat(4.0f, 20.0f);
            _People->ApearTime = RandomApear;


            RandomPeopleAnimation(_People);
            _People->CurApearTime = 0.0f;
        }
    }

}

void AShopGameMode::PeopleCreateAni(std::shared_ptr<class AUI> _People)
{
    for (int i = 1; i < 9; i++)
    {
        if (i < 5)
        {
            std::string SpriteName = "femaleCustomer_walk_0" + std::to_string(i) + ".png";

            _People->CreateAnimation("WalkCustomer0" + std::to_string(i), SpriteName, 3.0f, 0, 3, 0.2f);
        }
        else
        {
            std::string SpriteName = "maleCustomer_walk_0" + std::to_string(i - 4) + ".png";
            _People->CreateAnimation("WalkCustomer0" + std::to_string(i), SpriteName, 3.0f, 0, 3, 0.2f);
        }

    }
}

void AShopGameMode::RandomPeopleAnimation(std::shared_ptr<class AUI> _People)
{
    UEngineRandom Random;

    int RandInt = Random.RandomInt(0, 7);
    std::string RandAni = AllOutPeopleAni[RandInt];

    _People->ChangeAnimation(RandAni);
}

void AShopGameMode::CustomerEnter(float _DeltaTime)
{
    UEngineRandom Random;

    int Gender = Random.RandomInt(0, 1);
    int HairRand = Random.RandomInt(0, 4);
    int HeadRand = Random.RandomInt(0, 3);
    int BodyRand = Random.RandomInt(0, 3);
    int EyeRand = Random.RandomInt(0, 3);
    int EyeBrowRand = Random.RandomInt(0, 4);
    int NoseRand = Random.RandomInt(0, 1);
    int MouseRand = Random.RandomInt(0, 5);


    if (IsExistCustomer == false)
    {
        CustomerEnterTime += _DeltaTime;
        if (CustomerEnterTime < 2.8)
        {
            DoorOpen(_DeltaTime);
        }
        else if (CustomerEnterTime > 2.8)
        {
            IsDoorClosed = false;
            IsExistCustomer = true;
            DoorAcc = 1.0f;
            CustomerEnterTime = 0.0f;
        }
    }

    if (IsExistCustomer == true)
    {
        if (CustomerActive == 0)
        {
            CustomerActive += 1;
            Customer->RandomCustomer(Gender, HairRand, HeadRand, BodyRand, EyeRand, EyeBrowRand, NoseRand, MouseRand);
            Customer->SetActive(true);
            Customer->SetActorLocation({ 0.0f,0.0f,-100.0f });
        }
        if (IsDoorClosed == false)
        {
            CustomerEnterTime += _DeltaTime;
            if (CustomerEnterTime < 2.8)
            {
                DoorClose(_DeltaTime);
            }
            else if (CustomerEnterTime > 2.8)
            {
                IsDoorClosed = true;
                IsDoorDown = false;
                NotExistCustomerTime = 0.0f;
                DoorOpenTime = 0.0f; 
                DoorClosedTime = 0.0f;
                DoorAcc = 1.0f;
                CustomerEnterTime = 0.0f;

            }

        }
    }
}



void AShopGameMode::CustomerOut(float _DeltaTime)
{

    if (IsExistCustomer == true)
    {
        CustomerEnterTime += _DeltaTime;
        if (CustomerEnterTime < 2.8)
        {
            DoorOpen(_DeltaTime);
        }
        else if (CustomerEnterTime > 2.8)
        {
            Customer->SetActive(false);
            IsDoorClosed = false;
            IsExistCustomer = false;
            CustomerActive = 0;
            CustomerEnterTime = 0.0f;
            DoorAcc = 1.0f;
        }

    }

     if (IsExistCustomer == false)
    {
         if (IsDoorClosed == false)
         {
             CustomerEnterTime += _DeltaTime;
             if (CustomerEnterTime < 2.8)
             {
                 DoorClose(_DeltaTime);
             }
             else if (CustomerEnterTime > 2.8)
             {
                 IsOut = false;
                 IsDoorClosed = true;
                 NotExistCustomerTime = 0.0f;
                 CustomerEnterTime = 0.0f;
                 DoorOpenTime = 0.0f;
                 DoorClosedTime = 0.0f;
                 DoorAcc = 1.0f;
                 IsDoorDown = false;
             }

         }

    }

}


void AShopGameMode::DoorOpen(float _DeltaTime)
{

    DoorOpenTime += _DeltaTime ;
    if (DoorOpenTime > 1.0f && DoorOpenTime < 1.1f)
    {
        DoorUp->AddRelativeLocation({ 0.0f, -100.0f * _DeltaTime, 0.0f });
        DoorDown->AddRelativeLocation({ 0.0f, 100.0f * _DeltaTime , 0.0f });
    }

    if (DoorOpenTime > 1.1f && DoorUp->GetActorTransform().WorldLocation.Y < 165.0f)
    {
        DoorAcc += _DeltaTime * 6;
        DoorUp->AddRelativeLocation({ 0.0f, 100.0f * _DeltaTime * DoorAcc, 0.0f });
        DoorDown->AddRelativeLocation({ 0.0f, -100.0f * _DeltaTime * DoorAcc, 0.0f });

    }
}

void AShopGameMode::DoorClose(float _DeltaTime)
{
    DoorClosedTime += _DeltaTime;

    if (DoorUp->GetActorTransform().WorldLocation.Y < -125.0f)
    {
        IsDoorDown = true;
    }


    if (DoorClosedTime > 1.0f && IsDoorDown == false)
    {
        DoorAcc += _DeltaTime * 6;
   
        DoorUp->AddRelativeLocation({ 0.0f, -100.0f * _DeltaTime * DoorAcc ,0.0f });
        DoorDown->AddRelativeLocation({ 0.0f, 100.0f * _DeltaTime * DoorAcc,0.0f });
    }
    else if (IsDoorDown == true && DoorUp->GetActorTransform().WorldLocation.Y < -120.0f)
    {

        DoorUp->AddRelativeLocation({ 0.0f, 100.0f * _DeltaTime ,0.0f });
        DoorDown->AddRelativeLocation({ 0.0f, -100.0f * _DeltaTime ,0.0f });
    }
}