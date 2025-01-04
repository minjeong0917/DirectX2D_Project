#include "PreCompile.h"
#include "ShopGameMode.h"
#include "UI.h"
#include "Customer.h"
#include <EngineCore/EngineCore.h>
#include "ContentsRandom.h"


AShopGameMode::AShopGameMode()
{

	// BackGround
	std::shared_ptr<class AUI> BackGround = GetWorld()->SpawnActor<AUI>();
	BackGround->SetUISprite("Shop", 2);
	BackGround->SetUIScale3D({ 1920.0f, 1078.0f, 1.0f });
	BackGround->SetRelativeLocation({ 0.0f, -700.0f, 0.0f });


	// Ocean
	std::shared_ptr<class AUI> Ocean = GetWorld()->SpawnActor<AUI>();
	Ocean->CreateAnimation("Idle", "Ocean", 3.0f, 0, 4, 0.2f);
	Ocean->ChangeAnimation("Idle");
	Ocean->SetRelativeLocation({ 0.0f, -250.0f, 0.0f });


	// Bridge
	std::shared_ptr<class AUI> Bridge = GetWorld()->SpawnActor<AUI>();
	Bridge->SetUISprite("Shop", 1);
	Bridge->SetUIScale3D({ 1800.0f, 219.0f, 1.0f });
	Bridge->SetActorLocation({ 0.0f, -250.0f, 0.0f });


	// WalkCustomer
	for (int i = 0; i < 8; i++)
	{
		AllOutCustormerAni.push_back("WalkCustomer0" + std::to_string(i + 1));
	}

	WalkCustomer1 = GetWorld()->SpawnActor<AUI>();
	CustomerCreateAni(WalkCustomer1);
	
	WalkCustomer2 = GetWorld()->SpawnActor<AUI>();
	CustomerCreateAni(WalkCustomer2);


	// DoorDown
	std::shared_ptr<class AUI> DoorDown = GetWorld()->SpawnActor<AUI>();
	DoorDown->SetUISprite("Shop", 6);
	DoorDown->SetUIScale3D({ 246.0f, 165.0f, 1.0f });
	DoorDown->SetActorLocation({ 0.0f, -250.0f, 0.0f });


	// DoorUp
	std::shared_ptr<class AUI> DoorUp = GetWorld()->SpawnActor<AUI>();
	DoorUp->SetUISprite("Shop", 5);
	DoorUp->SetUIScale3D({ 252.0f, 363.0f, 1.0f });
	DoorUp->SetActorLocation({ 0.0f, -120.0f, 0.0f });


	// main
	std::shared_ptr<class AUI> Main = GetWorld()->SpawnActor<AUI>();
	Main->CreateAnimation("Idle", "Main", 3.0f, 0, 6, 0.2f);
	Main->ChangeAnimation("Idle");
	//Main->SetUISprite("Shop", 0);
	//Main->SetUIScale3D({ 1920.0f, 1080.0f, 1.0f });
	Main->SetRelativeLocation({ 0.0f, -540.0f, 0.0f });

	//Customer
	Customer = GetWorld()->SpawnActor<ACustomer>();

	// Table
	std::shared_ptr<class AUI> Table = GetWorld()->SpawnActor<AUI>();
	//Table->CreateAnimation("Idle", "Table", 3.0f, 0, 6, 0.2f);
	//Table->ChangeAnimation("Idle");
	Table->SetUISprite("Shop", 4);
	Table->SetUIScale3D({ 1920.0f, 347.0f, 1.0f });
	Table->SetRelativeLocation({ 0.0f, -545.0f, 0.0f});


	// Hue
	std::shared_ptr<class AUI> HueBodyAnimation = GetWorld()->SpawnActor<AUI>();
	HueBodyAnimation->CreateAnimation("Idle", "companion_idle_loop.png", 3.1f, 0, 13, 0.2f);
	HueBodyAnimation->ChangeAnimation("Idle");
	HueBodyAnimation->SetRelativeLocation({ 370.0f, -300.0f, 0.0f });


	// OutLine	
	std::shared_ptr<class AUI> OutLine = GetWorld()->SpawnActor<AUI>();
	OutLine->SetUISprite("Shop", 3);
	OutLine->SetUIScale3D({ 1920.0f, 1080.0f, 1.0f });
	OutLine->SetRelativeLocation({ 0.0f, -540.0f, 0.0f });



}

AShopGameMode::~AShopGameMode()
{
}

void AShopGameMode::BeginPlay()
{
	AActor::BeginPlay();
	ContentsRandom Random;

	{
		WalkCustomer1->SetRelativeLocation({ 840.0f, -300.0f, 0.0f });
		RandomCustomerAnimation(WalkCustomer1);
		float RandomApear = Random.Randomfloat(2.0f, 10.0f);
		WalkCustomer1->ApearTime = RandomApear;
		UEngineDebug::OutPutString(std::to_string(RandomApear));
	}
	{
		//WalkCustomer2->SetActorLocation({ -900.0f,  -300.0f, 0.0f });
		WalkCustomer2->SetRelativeLocation({ 900.0f,  -300.0f, 0.0f });
		WalkCustomer2->SetActorRotation({ 0.0f, 180.0f, 0.0f });
		RandomCustomerAnimation(WalkCustomer2);

		float RandomApear = Random.Randomfloat(6.0f, 15.0f);
		WalkCustomer2->ApearTime = RandomApear;
		UEngineDebug::OutPutString(std::to_string(RandomApear));
	}
}

void AShopGameMode::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	UEngineDebug::OutPutString("FPS : " + std::to_string(1.0f / _DeltaTime));

	CustomerMove(_DeltaTime, WalkCustomer1, true);
	CustomerMove(_DeltaTime, WalkCustomer2, false);

}

void AShopGameMode::CustomerMove(float _DeltaTime, std::shared_ptr<class AUI> _Customer, bool _IsRight)
{
	ContentsRandom Random;

	if (_IsRight == true)
	{
		if (_Customer->GetActorTransform().WorldLocation.X > -2000.0f)
		{
			_Customer->CurApearTime += _DeltaTime;
			if (_Customer->CurApearTime > _Customer->ApearTime)
			{
				_Customer->IsApear = true;
			}

			if (_Customer->IsApear == true)
			{
				_Customer->AddRelativeLocation({ (-1.0f) * _DeltaTime * CustomerSpeed, 0.0f, 0.0f });
			}
		}
		else if (_Customer->GetActorTransform().WorldLocation.X < -2000.0f)
		{
			_Customer->IsApear = false;
			_Customer->SetActorLocation({ 0.0f, 0.0f, 0.0f });

			float RandomApear = Random.Randomfloat(1.0f, 20.0f);
			UEngineDebug::OutPutString(std::to_string(RandomApear));
			_Customer->ApearTime = RandomApear;

			RandomCustomerAnimation(_Customer);
			_Customer->CurApearTime = 0.0f;
		}
	}

	if (_IsRight == false)
	{
		if (_Customer->GetActorTransform().WorldLocation.X <  2000.0f)
		{
			_Customer->CurApearTime += _DeltaTime;
			if (_Customer->CurApearTime > _Customer->ApearTime)
			{
				_Customer->IsApear = true;
			}

			if (_Customer->IsApear == true)
			{

				_Customer->AddRelativeLocation({ (1.0f) * _DeltaTime * CustomerSpeed, 0.0f, 0.0f });

			}
		}
		 if (_Customer->GetActorTransform().WorldLocation.X > 2000.0f)
		{
			_Customer->IsApear = false;
			_Customer->SetActorLocation({ 0.0f,  0.0f, 0.0f });

			float RandomApear = Random.Randomfloat(4.0f, 20.0f);
			_Customer->ApearTime = RandomApear;


			RandomCustomerAnimation(_Customer);
			_Customer->CurApearTime = 0.0f;
		}
	}

}

void AShopGameMode::CustomerCreateAni(std::shared_ptr<class AUI> _Customer)
{
	for (int i = 1; i < 9; i++)
	{
		if (i < 5)
		{
			std::string SpriteName = "femaleCustomer_walk_0" + std::to_string(i) + ".png";

			_Customer->CreateAnimation("WalkCustomer0" + std::to_string(i), SpriteName, 3.0f, 0, 3, 0.2f);
		}
		else
		{
			std::string SpriteName = "maleCustomer_walk_0" + std::to_string(i - 4) + ".png";
			_Customer->CreateAnimation("WalkCustomer0" + std::to_string(i), SpriteName, 3.0f, 0, 3, 0.2f);
		}

	}

	//_Customer->CreateAnimation("WalkCustomer01", "femaleCustomer_walk_01.png", 3.0f, 0, 3, 0.2f);
	//_Customer->CreateAnimation("WalkCustomer02", "femaleCustomer_walk_02.png", 3.0f, 0, 3, 0.2f);
	//_Customer->CreateAnimation("WalkCustomer03", "femaleCustomer_walk_03.png", 3.0f, 0, 3, 0.2f);
	//_Customer->CreateAnimation("WalkCustomer04", "femaleCustomer_walk_04.png", 3.0f, 0, 3, 0.2f);
	//_Customer->CreateAnimation("WalkCustomer05", "maleCustomer_walk_01.png", 3.0f, 0, 3, 0.2f);
	//_Customer->CreateAnimation("WalkCustomer06", "maleCustomer_walk_02.png", 3.0f, 0, 3, 0.2f);
	//_Customer->CreateAnimation("WalkCustomer07", "maleCustomer_walk_03.png", 3.0f, 0, 3, 0.2f);
	//_Customer->CreateAnimation("WalkCustomer08", "maleCustomer_walk_04.png", 3.0f, 0, 3, 0.2f);
}

void AShopGameMode::RandomCustomerAnimation(std::shared_ptr<class AUI> _Customer)
{
	ContentsRandom Random;

	int RandInt = Random.RandomInt(0, 7);
	std::string RandAni = AllOutCustormerAni[RandInt];

	_Customer->ChangeAnimation(RandAni);
}