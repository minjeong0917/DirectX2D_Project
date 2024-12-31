#include "PreCompile.h"
#include "TitleGameMode.h"
#include "Logo.h"
#include "UI.h"
#include <EngineCore/CameraActor.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineGUIWindow.h>
#include <EngineCore/EngineGUI.h>
#include <EngineCore/imgui.h>
#include <EngineCore/EngineCore.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/CameraActor.h>



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
		Background = GetWorld()->SpawnActor<AUI>();
		Background->SetUISprite("TitleImage", 0);
		Background->SetUIScale3D({ 1920.0f, 480.0f, 1.0f });
		Background->SetActorLocation({ 0.0f, UIYPos, 0.0f });
	}

	// Lights
	{
		std::shared_ptr<class AUI> LightHalo = GetWorld()->SpawnActor<AUI>();
		LightHalo->CreateAnimation("Idle", "lamp_halo_loop.png", 3.0f, 0, 3, 0.2f);
		LightHalo->ChangeAnimation("Idle");
		LightHalo->SetRelativeLocation({ -480.0f, -150.0f, 0.0f });

		std::shared_ptr<class AUI> Light = GetWorld()->SpawnActor<AUI>();
		Light->SetUISprite("TitleImage", 2);
		Light->SetUIScale3D({ 213.0f, 201.0f, 1.0f });
		Light->SetActorLocation({ -480.0f, -150.0f, 0.0f });


	}
	{
		std::shared_ptr<class AUI> Light = GetWorld()->SpawnActor<AUI>();
		Light->SetUISprite("TitleImage", 3);
		Light->SetUIScale3D({ 213.0f, 201.0f, 1.0f });
		Light->SetActorLocation({ -297.0f, -150.0f, 0.0f });
	}
	{
		std::shared_ptr<class AUI> LightHalo = GetWorld()->SpawnActor<AUI>();
		LightHalo->CreateAnimation("Idle", "lamp_halo_loop.png", 3.0f, 0, 3, 0.2f);
		LightHalo->ChangeAnimation("Idle");
		LightHalo->SetRelativeLocation({ 233.0f, -150.0f, 0.0f });

		std::shared_ptr<class AUI> Light = GetWorld()->SpawnActor<AUI>();
		Light->SetUISprite("TitleImage", 2);
		Light->SetUIScale3D({ 213.0f, 201.0f, 1.0f });
		Light->SetActorLocation({ 233.0f, -150.0f, 0.0f });
	}

	// Window
	{
		std::shared_ptr<class AUI> WindowLight = GetWorld()->SpawnActor<AUI>();
		WindowLight->CreateAnimation("Idle", "window02_light_loop.png", 3.0f, 0, 6, 0.2f);
		WindowLight->ChangeAnimation("Idle");
		WindowLight->SetRelativeLocation({ -14.0f, -188.0f, 1.0f, 0.0f });
	}


	// plants
	{
		FVector StartLocation = { -700.0f, -275.0f, 0.0f };
		FVector InterLocation = { 350.0f, 0.0f };

		for (float i = 0; i < 3; i++)
		{

			std::shared_ptr<class AUI> Plants = GetWorld()->SpawnActor<AUI>();
			Plants->CreateAnimation("Idle", "plant_01_loop.png", 3.1f, 0, 6, 0.2f);
			Plants->ChangeAnimation("Idle");
			Plants->SetRelativeLocation(StartLocation + InterLocation * i + FVector(50.0, 0.0f,0.0f)*i);
		}

		std::shared_ptr<class AUI> Plants = GetWorld()->SpawnActor<AUI>();
		Plants->CreateAnimation("Idle", "plant_01_loop.png", 3.1f, 0, 6, 0.2f);
		Plants->ChangeAnimation("Idle");
		Plants->SetRelativeLocation({ 390.0f, -310.0f,0.0f });
	
	}
	{
		FVector StartLocation = { -100.0f, -275.0f, 0.0f };
		FVector InterLocation = { 250.0f, 0.0f };

		for (float i = 0; i < 2; i++)
		{

			std::shared_ptr<class AUI> Plants = GetWorld()->SpawnActor<AUI>();
			Plants->CreateAnimation("Idle", "plant_02_loop.png", 3.1f, 0, 4, 0.2f);
			Plants->ChangeAnimation("Idle");
			Plants->SetRelativeLocation(StartLocation + InterLocation * i);

		}

		std::shared_ptr<class AUI> Plants = GetWorld()->SpawnActor<AUI>();
		Plants->CreateAnimation("Idle", "plant_02_loop.png", 3.1f, 0, 4, 0.2f);
		Plants->ChangeAnimation("Idle");
		Plants->SetRelativeLocation({-632.0f, -310.0f,0.0f});
	}

	{
		std::shared_ptr<class AUI> Plants = GetWorld()->SpawnActor<AUI>();
		Plants->CreateAnimation("Idle", "plant_03_loop.png", 3.1f, 0, 6, 0.2f);
		Plants->ChangeAnimation("Idle");
		Plants->SetRelativeLocation({ 602.0f, -310.0f,0.0f });

		std::shared_ptr<class AUI> Plants2 = GetWorld()->SpawnActor<AUI>();
		Plants2->CreateAnimation("Idle", "plant_03_loop.png", 3.1f, 0, 6, 0.2f);
		Plants2->ChangeAnimation("Idle");
		Plants2->SetRelativeLocation({ -40.0f, -275.0f,0.0f });

	}


	// Door
	std::shared_ptr<class AUI> Door = GetWorld()->SpawnActor<AUI>();
	Door->CreateAnimation("Idle", "holoDoor_loop.png", 3.0f, 0, 4, 0.2f);
	Door->ChangeAnimation("Idle");
	Door->SetRelativeLocation({-566.0f, -258.0f, 1.0f, 0.0f});
	
	// fence
	std::shared_ptr<class AUI> Fence = GetWorld()->SpawnActor<AUI>();
	Fence->SetUISprite("TitleImage", 1);
	Fence->SetUIScale3D({ 1400.0f, 106.0f, 1.0f });
	Fence->SetActorLocation({ -10.0f, -311.0f, 0.0f });

	std::shared_ptr<class AUI> StairFence = GetWorld()->SpawnActor<AUI>();
	StairFence->SetUISprite("TitleImage", 4);
	StairFence->SetUIScale3D({ 279.0f, 123.0f, 1.0f });
	StairFence->SetActorLocation({ Size.hX() * (-1.0f) + 100, -311.0f, 0.0f});

	// Name
	{
		std::shared_ptr<class AUI> Name1 = GetWorld()->SpawnActor<AUI>();
		Name1->CreateAnimation("Idle", "name_01_loop.png", 3.1f, 0, 3, 0.2f);
		Name1->ChangeAnimation("Idle");
		Name1->SetRelativeLocation({ -566.0f, 76.0f, 1.0f, 0.0f });

		std::shared_ptr<class AUI> Name2 = GetWorld()->SpawnActor<AUI>();
		Name2->CreateAnimation("Idle", "name_02_loop.png", 3.1f, 0, 3, 0.2f);
		Name2->ChangeAnimation("Idle");
		Name2->SetRelativeLocation({ 323.0f, 76.0f, 1.0f, 0.0f });

		std::shared_ptr<class AUI> Name3 = GetWorld()->SpawnActor<AUI>();
		Name3->CreateAnimation("Idle", "name_home_loop.png", 3.2f, 0, 3, 0.2f);
		Name3->ChangeAnimation("Idle");
		Name3->SetRelativeLocation({ -205.0f, 76.0f, 1.0f, 0.0f });
	}




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
	if (UEngineInput::IsPress(VK_SPACE))
	{
		UEngineCore::OpenLevel("Shoplevel");
	}
	std::shared_ptr<class ACameraActor> Camera = GetWorld()->GetCamera(0);

	UEngineDebug::OutPutString(Camera->ScreenMousePosToWorldPos().ToString());

}

