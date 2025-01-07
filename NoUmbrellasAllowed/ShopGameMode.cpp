#include "PreCompile.h"
#include "ShopGameMode.h"
#include "UI.h"
#include "Customer.h"
#include "Calculator.h"
#include <EngineCore/EngineCore.h>

#include <EnginePlatform/EngineInput.h>
#include <EngineCore/CameraActor.h>
#include <EngineCore/EngineCamera.h>
#include <EngineCore/TimeEventComponent.h>
#include <EngineBase/EngineRandom.h>

AShopGameMode::AShopGameMode()
{
    TimeEventComponent = CreateDefaultSubObject<UTimeEventComponent>();

    // BackGround
    std::shared_ptr<class AUI> BackGround = GetWorld()->SpawnActor<AUI>();
    BackGround->SetUISprite("Shop", 2);
    BackGround->SetUIScale3D({ 1920.0f, 1078.0f, 1.0f });
    BackGround->SetRelativeLocation({ 0.0f, -700.0f, 1000.0f });


    // Ocean
    std::shared_ptr<class AUI> Ocean = GetWorld()->SpawnActor<AUI>();
    Ocean->CreateAnimation("Idle", "Ocean", 3.0f, 0, 4, 0.2f);
    Ocean->ChangeAnimation("Idle");
    Ocean->SetRelativeLocation({ 0.0f, -250.0f, 999.0f });


    // Bridge
    std::shared_ptr<class AUI> Bridge = GetWorld()->SpawnActor<AUI>();
    Bridge->SetUISprite("Shop", 1);
    Bridge->SetUIScale3D({ 1800.0f, 219.0f, 1.0f });
    Bridge->SetActorLocation({ 0.0f, -250.0f, 900.0f });


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
    DoorDown->SetUISprite("Shop", 6);
    DoorDown->SetUIScale3D({ 246.0f, 165.0f, 1.0f });
    DoorDown->SetActorLocation({ 0.0f, -250.0f, 500.0f });


    // DoorUp
    DoorUp = GetWorld()->SpawnActor<AUI>();
    DoorUp->SetUISprite("Shop", 5);
    DoorUp->SetUIScale3D({ 252.0f, 363.0f, 1.0f });
    DoorUp->SetActorLocation({ 0.0f, -120.0f, 600.0f });


    // main
    std::shared_ptr<class AUI> Main = GetWorld()->SpawnActor<AUI>();
    Main->CreateAnimation("Idle", "Main", 3.0f, 0, 6, 0.2f);
    Main->ChangeAnimation("Idle");
    //Main->SetUISprite("Shop", 0);
    //Main->SetUIScale3D({ 1920.0f, 1080.0f, 1.0f });
    Main->SetRelativeLocation({ 0.0f, -540.0f, 11.0f });

    //Customer
    Customer = GetWorld()->SpawnActor<ACustomer>();
    Customer->SetActive(false);

    // Table
    std::shared_ptr<class AUI> Table = GetWorld()->SpawnActor<AUI>();
    //Table->CreateAnimation("Idle", "Table", 3.0f, 0, 6, 0.2f);
    //Table->ChangeAnimation("Idle");
    Table->SetUISprite("Shop", 4);
    Table->SetUIScale3D({ 1920.0f, 347.0f, 1.0f });
    Table->SetRelativeLocation({ 0.0f, -545.0f, 10.0f });


    // Hue
    std::shared_ptr<class AUI> HueBodyAnimation = GetWorld()->SpawnActor<AUI>();
    HueBodyAnimation->CreateAnimation("Idle", "companion_idle_loop.png", 3.1f, 0, 13, 0.2f);
    HueBodyAnimation->ChangeAnimation("Idle");
    HueBodyAnimation->SetRelativeLocation({ 370.0f, -300.0f, 9.0f });

    Calculator = GetWorld()->SpawnActor<ACalculator>();

    // OutLine   
    std::shared_ptr<class AUI> OutLine = GetWorld()->SpawnActor<AUI>();
    OutLine->SetUISprite("Shop", 3);
    OutLine->SetUIScale3D({ 1920.0f, 1080.0f, 1.0f });
    OutLine->SetActorLocation({ 0.0f, -540.0f, -999.0f });


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
        //WalkCustomer2->SetActorLocation({ -900.0f,  -300.0f, 0.0f });
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

    PeopleMove(_DeltaTime, WalkCustomer1, true);
    PeopleMove(_DeltaTime, WalkCustomer2, false);

    // TestCode
    if (UEngineInput::IsPress('O'))
    {
        IsOut = true;
    }


    if (IsOut == false)
    {
        NotExistCustomerTime += _DeltaTime;
        if(NotExistCustomerTime > 5.0f)
        {
            CustomerEnter(_DeltaTime);
        }

    }
    else if (IsOut == true)
    {
        CustomerOut(_DeltaTime);
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
    int HairRand = Random.RandomInt(0, 3);
    int HeadRand = Random.RandomInt(0, 3);
    int BodyRand = Random.RandomInt(0, 3);
    int EyeRand = Random.RandomInt(0, 3);
    int NoseRand = Random.RandomInt(0, 3);
    int MouseRand = Random.RandomInt(0, 3);

    if (IsExistCustomer == false)
    {
        TimeEventComponent->AddEvent(2.5f, [this](float DeltaTime, float CurTime) {DoorOpen(DeltaTime); }, [this]() { IsExistCustomer = true; }, false);

    }

    if (IsExistCustomer == true)
    {
        if (CustomerActive == 0)
        {
            CustomerActive += 1;
            Customer->RandomCustomer(Gender, HairRand, HeadRand, BodyRand, EyeRand, NoseRand, MouseRand);
            Customer->SetActive(true);
            Customer->SetActorLocation({ 0.0f,0.0f,-100.0f });
        }

        TimeEventComponent->AddEvent(2.5f, [this](float DeltaTime, float CurTime) {DoorClose(DeltaTime); }, [this]() {NotExistCustomerTime = 0.0f; DoorOpenTime = 0.0f; DoorClosedTime = 0.0f; }, false);


    }
}



void AShopGameMode::CustomerOut(float _DeltaTime)
{

    if (IsExistCustomer == true)
    {
        TimeEventComponent->AddEvent(2.5f, [this](float DeltaTime, float CurTime) {DoorOpen(DeltaTime); }, [this]() {Customer->SetActive(false);  IsExistCustomer = false; CustomerActive = 0;
        }, false);

    }

     if (IsExistCustomer == false)
    {
        TimeEventComponent->AddEvent(2.5f, [this](float DeltaTime, float CurTime) {DoorClose(DeltaTime); }, [this]() { IsOut = false; NotExistCustomerTime = 0.0f; DoorOpenTime = 0.0f; DoorClosedTime = 0.0f; }, false);

    }

}


void AShopGameMode::DoorOpen(float _DeltaTime)
{

    DoorOpenTime += _DeltaTime;
    if (DoorOpenTime > 100.0f && DoorOpenTime < 105.0f)
    {
        DoorUp->AddRelativeLocation({ 0.0f, -1.0f * _DeltaTime, 0.0f });
        DoorDown->AddRelativeLocation({ 0.0f, 1.0f * _DeltaTime, 0.0f });
    }

    if (DoorOpenTime > 105.0f && DoorUp->GetActorTransform().WorldLocation.Y < 165.0f)
    {

        DoorUp->AddRelativeLocation({ 0.0f, 8.0f * _DeltaTime, 0.0f });
        DoorDown->AddRelativeLocation({ 0.0f, -8.0f * _DeltaTime, 0.0f });

    }
}

void AShopGameMode::DoorClose(float _DeltaTime)
{
    DoorClosedTime += _DeltaTime;

    if (DoorClosedTime > 100.0f && DoorUp->GetActorTransform().WorldLocation.Y > -135.0f)
    {

        DoorUp->AddRelativeLocation({ 0.0f, -8.0f * _DeltaTime ,0.0f });
        DoorDown->AddRelativeLocation({ 0.0f, 8.0f * _DeltaTime,0.0f });
    }

    if (DoorClosedTime > 200.0f && DoorUp->GetActorTransform().WorldLocation.Y < -120.0f)
    {

        DoorUp->AddRelativeLocation({ 0.0f, 2.0f * _DeltaTime ,0.0f });
        DoorDown->AddRelativeLocation({ 0.0f, -2.0f * _DeltaTime ,0.0f });

    }


}