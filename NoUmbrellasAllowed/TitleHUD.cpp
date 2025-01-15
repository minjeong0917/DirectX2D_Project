#include "PreCompile.h"
#include "TitleHUD.h"

#include <EngineCore/ImageWidget.h>
#include <EngineCore/FontWidget.h>
#include <EngineCore/CameraActor.h>
#include <EngineCore/EngineCamera.h>
ATitleHUD::ATitleHUD()
{
}

ATitleHUD::~ATitleHUD()
{
}

void ATitleHUD::BeginPlay()
{
	AHUD::BeginPlay();
	
	Cursor = CreateWidget<UImageWidget>(2);
	Cursor->SetSprite("Cursor", 0);
	Cursor->SetAutoScaleRatio(2.0f);

	


}

void ATitleHUD::Tick(float _DeltaTime)
{
	AHUD::Tick(_DeltaTime);

	std::shared_ptr<class ACameraActor> Camera = GetWorld()->GetCamera(0);
	FVector MousePos = Camera->ScreenMousePosToWorldPos();

	Cursor->SetWorldLocation({ MousePos.X + 8.0f, MousePos.Y - 30.0f });

}