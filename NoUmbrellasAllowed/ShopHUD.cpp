#include "PreCompile.h"

#include "ShopHUD.h"
#include <EngineCore/ImageWidget.h>
#include <EngineCore/FontWidget.h>
#include <EngineCore/CameraActor.h>
#include <EngineCore/EngineCamera.h>
#include "ShopGameMode.h"
AShopHUD::AShopHUD()
{
}

AShopHUD::~AShopHUD()
{
}

void AShopHUD::BeginPlay()
{
	AHUD::BeginPlay();
	{
		Cursor = CreateWidget<UImageWidget>(2);
		Cursor->SetSprite("Cursor",0);
		Cursor->SetAutoScaleRatio(2.0f);
		
	}


	{
		std::shared_ptr<UFontWidget> Widget = CreateWidget<UFontWidget>(1);

		Widget->SetWorldLocation({ 200, 300 });
		Widget->SetFont("PF");
		Widget->SetText("æ»≥Á«œººø‰");
	}
}

void AShopHUD::Tick(float _DeltaTime)
{
	AHUD::Tick(_DeltaTime);

	std::shared_ptr<class ACameraActor> Camera = GetWorld()->GetCamera(0);
	FVector MousePos = Camera->ScreenMousePosToWorldPos();

	Cursor->SetWorldLocation({ MousePos.X + 8.0f, MousePos.Y - 30.0f });

	AShopGameMode* Shop = GetWorld()->GetGameMode<AShopGameMode>();
	if (Shop->CursorActive == true)
	{
		Cursor->SetActive(true);
	}
	else if (Shop->CursorActive == false)
	{
		Cursor->SetActive(false);
	}
}