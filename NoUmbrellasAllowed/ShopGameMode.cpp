#include "PreCompile.h"
#include "ShopGameMode.h"
#include "UI.h"
#include <EngineCore/EngineCore.h>

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

	// WalkCustomer
	//WalkCustomer = GetWorld()->SpawnActor<AUI>();
	//WalkCustomer->CreateAnimation("WalkCustomer", "000_femaleCustomer_run_01.png", 3.0f, 0, 3, 0.2f);
	//WalkCustomer->ChangeAnimation("WalkCustomer");
	//WalkCustomer->SetRelativeLocation({ 640.0f, -250.0f, 0.0f });

	// Bridge
	std::shared_ptr<class AUI> Bridge = GetWorld()->SpawnActor<AUI>();
	Bridge->SetUISprite("Shop", 1);
	Bridge->SetUIScale3D({ 1800.0f, 219.0f, 1.0f });
	Bridge->SetActorLocation({ 0.0f, -250.0f, 0.0f });

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

	// Table
	std::shared_ptr<class AUI> Table = GetWorld()->SpawnActor<AUI>();
	Table->SetUISprite("Shop", 4);
	Table->SetUIScale3D({ 1920.0f, 347.0f, 1.0f });
	Table->SetRelativeLocation({ 0.0f, -545.0f, 0.0f});

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

}

void AShopGameMode::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	UEngineDebug::OutPutString("FPS : " + std::to_string(1.0f / _DeltaTime));

	//WalkCustomer->AddRelativeLocation({ (-1.0f) * _DeltaTime * 10, 0.0f,0.0f });
}

