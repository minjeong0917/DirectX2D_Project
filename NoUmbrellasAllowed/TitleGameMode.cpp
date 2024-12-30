#include "PreCompile.h"
#include "TitleGameMode.h"
#include "Logo.h"
#include "TitleUI.h"
#include <EngineCore/CameraActor.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineGUIWindow.h>
#include <EngineCore/EngineGUI.h>
#include <EngineCore/imgui.h>
#include <EngineCore/EngineCore.h>


class TestWindow : public UEngineGUIWindow
{
public:
	void OnGUI() override
	{
		ImGui::Button("WindowButton");
		ImGui::SameLine(); // ÇÑ°£ ¶ç±â
		ImGui::Text("test");

	}
};

ATitleGameMode::ATitleGameMode()
{
	FVector Size = UEngineCore::GetScreenScale();
	float UIYPos = -310.0f;
	{
		Logo = GetWorld()->SpawnActor<ALogo>();
		Logo->SetActorLocation({ 0.0f, Size.Half().hY()-55.0f, 0.0f});
	}
	{
		Background = GetWorld()->SpawnActor<ATitleUI>();
		Background->SetUISprite("TitleImage", 0);
		Background->SetUIScale3D({ 1920.0f, 480.0f, 1.0f });
		Background->SetActorLocation({ 0.0f, UIYPos, 0.0f });
	}
	{
		BackBuilding3 = GetWorld()->SpawnActor<ATitleUI>();
		BackBuilding3->SetUISprite("TitleImage", 5);
		BackBuilding3->SetUIScale3D({ 345.0f, 480.0f, 1.0f });
		BackBuilding3->SetActorLocation({ Size.Half().hX() + 230, UIYPos, 0.0f});
	}
	{
		BackBuilding1 = GetWorld()->SpawnActor<ATitleUI>();
		BackBuilding1->SetUISprite("TitleImage", 2);
		BackBuilding1->SetUIScale3D({ 1020.0f, 480.0f, 1.0f });
		BackBuilding1->SetActorLocation({ Size.Half().hX() + 80.0f, UIYPos, 0.0f});
	}
	{
		BackBuilding2 = GetWorld()->SpawnActor<ATitleUI>();
		BackBuilding2->SetUISprite("TitleImage", 3);
		BackBuilding2->SetUIScale3D({ 270.0f, 480.0f, 1.0f });
		BackBuilding2->SetActorLocation({ Size.Half().X*(-1.0f) + 102.0f, UIYPos, 0.0f});
	}
	{
		BuildingFrame = GetWorld()->SpawnActor<ATitleUI>();
		BuildingFrame->SetUISprite("TitleImage", 4);
		BuildingFrame->SetUIScale3D({ 153.0f, 480.0f, 1.0f });
		BuildingFrame->SetActorLocation({ Size.Half().hX()-20.0f, UIYPos, 0.0f });
	}
	{
		Building = GetWorld()-> SpawnActor<ATitleUI>();
		Building->SetUISprite("TitleImage", 1);
		Building->SetUIScale3D({ 1296.0f, 480.0f, 1.0f });
		Building->SetActorLocation({ -200.0f, UIYPos, 0.0f});
	}

	FVector StartLocation = { -700.0f, -285.0f, 0.0f };
	FVector InterLocation = { 300.0f, 0.0f };

	for (int i = 0; i < 3; i++)
	{
	
		std::shared_ptr<class ATitleUI> Plants = GetWorld()->SpawnActor<ATitleUI>();
		Plants->CreateAnimation("Idle", "plant_01_loop.png", 0, 6, 0.2f);
		Plants->ChangeAnimation("Idle");
		Plants->SetRelativeLocation(StartLocation + InterLocation * i);

	}


	// Camera
	std::shared_ptr<ACameraActor> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation({ 0.0f, 0.0f, -1000.0f, 1.0f });
	UEngineGUI::CreateGUIWindow<TestWindow>("TestWindow");

}

ATitleGameMode::~ATitleGameMode()
{
}

void ATitleGameMode::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

}

