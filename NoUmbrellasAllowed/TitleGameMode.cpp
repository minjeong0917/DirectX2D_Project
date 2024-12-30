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

	// Lights
	{
		std::shared_ptr<class ATitleUI> LightHalo = GetWorld()->SpawnActor<ATitleUI>();
		LightHalo->CreateAnimation("Idle", "lamp_halo_loop.png", 3.0f, 0, 3, 0.2f);
		LightHalo->ChangeAnimation("Idle");
		LightHalo->SetRelativeLocation({ -496.0f, -150.0f, 0.0f });

		std::shared_ptr<class ATitleUI> Light = GetWorld()->SpawnActor<ATitleUI>();
		Light->SetUISprite("TitleImage", 6);
		Light->SetUIScale3D({ 213.0f, 201.0f, 1.0f });
		Light->SetActorLocation({ -496.0f, -150.0f, 0.0f });


	}
	{
		std::shared_ptr<class ATitleUI> Light = GetWorld()->SpawnActor<ATitleUI>();
		Light->SetUISprite("TitleImage", 7);
		Light->SetUIScale3D({ 213.0f, 201.0f, 1.0f });
		Light->SetActorLocation({ -313.0f, -150.0f, 0.0f });
	}
	{
		std::shared_ptr<class ATitleUI> LightHalo = GetWorld()->SpawnActor<ATitleUI>();
		LightHalo->CreateAnimation("Idle", "lamp_halo_loop.png", 3.0f, 0, 3, 0.2f);
		LightHalo->ChangeAnimation("Idle");
		LightHalo->SetRelativeLocation({ 221.0f, -150.0f, 0.0f });

		std::shared_ptr<class ATitleUI> Light = GetWorld()->SpawnActor<ATitleUI>();
		Light->SetUISprite("TitleImage", 6);
		Light->SetUIScale3D({ 213.0f, 201.0f, 1.0f });
		Light->SetActorLocation({ 221.0f, -150.0f, 0.0f });
	}

	// Window
	{
		std::shared_ptr<class ATitleUI> WindowLight = GetWorld()->SpawnActor<ATitleUI>();
		WindowLight->CreateAnimation("Idle", "window02_light_loop.png", 3.0f, 0, 6, 0.2f);
		WindowLight->ChangeAnimation("Idle");
		WindowLight->SetRelativeLocation({ -30.0f, -188.0f, 1.0f, 0.0f });
	}


	std::shared_ptr<class ATitleUI> Wood = GetWorld()->SpawnActor<ATitleUI>();
	Wood->SetUISprite("TitleImage", 10);
	Wood->SetUIScale3D({ 1290.0f, 195.0f, 1.0f });
	Wood->SetActorLocation({ -100.0f, -311.0f, 0.0f });


	// plants
	{
		FVector StartLocation = { -700.0f, -285.0f, 0.0f };
		FVector InterLocation = { 350.0f, 0.0f };

		for (float i = 0; i < 3; i++)
		{

			std::shared_ptr<class ATitleUI> Plants = GetWorld()->SpawnActor<ATitleUI>();
			Plants->CreateAnimation("Idle", "plant_01_loop.png", 3.1f, 0, 6, 0.2f);
			Plants->ChangeAnimation("Idle");
			Plants->SetRelativeLocation(StartLocation + InterLocation * i);

		}
	}

	// Door
	std::shared_ptr<class ATitleUI> Door = GetWorld()->SpawnActor<ATitleUI>();
	Door->CreateAnimation("Idle", "holoDoor_loop.png", 3.0f, 0, 4, 0.2f);
	Door->ChangeAnimation("Idle");
	Door->SetRelativeLocation({-582.0f, -258.0f, 1.0f, 0.0f});
	
	// fence
	std::shared_ptr<class ATitleUI> Fence = GetWorld()->SpawnActor<ATitleUI>();
	Fence->SetUISprite("TitleImage", 9);
	Fence->SetUIScale3D({ 1280.0f, 106.0f, 1.0f });
	Fence->SetActorLocation({ -100.0f, -311.0f, 0.0f });


	// Camera
	std::shared_ptr<ACameraActor> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation({ 0.0f, 0.0f, -1000.0f, 1.0f });
	UEngineGUI::CreateGUIWindow<TestWindow>("TestWindow");

}

ATitleGameMode::~ATitleGameMode()
{
}
void ATitleGameMode::BeginPlay()
{
	AActor::BeginPlay();

}

void ATitleGameMode::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

}

