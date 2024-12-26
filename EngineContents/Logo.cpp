#include "PreCompile.h"
#include "Logo.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>

ALogo::ALogo()
{
	LogoRenderer = CreateDefaultSubObject<USpriteRenderer>();
	LogoRenderer->SetSprite("plant_01_loop.png", 0);
	LogoRenderer->SetRelativeScale3D({ 230.0f, 400.0f, 1.0f });

	RootComponent = LogoRenderer;


	std::shared_ptr<class USpriteRenderer> Child = CreateDefaultSubObject<USpriteRenderer>();
	Child->SetSprite("plant_01_loop.png", 2);
	Child->SetLocation({ 2.0f, 0.0f, 0.0f });
	Child->SetupAttachment(RootComponent);

	// -를 넣을 경우 -> 레지스터에서 cull모드에서 영향 -> Back으로 설정했으면 반시계방향으로 바뀌어 화면에 뜨지 않음..! NONE으로 하면 반대로 뒤집혀서 화면에 뜸..!
	//SetActorRelativeScale3D({ 230.0f, 400.0f, 1.0f });

}

ALogo::~ALogo()
{
}

void ALogo::BeginPlay()
{
	AActor::BeginPlay();
}

void ALogo::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	if (UEngineInput::IsPress('A'))
	{
		AddActorLocation(FVector{ -100.0f * _DeltaTime, 0.0f, 0.0f });
	}
	if (UEngineInput::IsPress('D'))
	{
		AddActorLocation(FVector{ 100.0f * _DeltaTime, 0.0f, 0.0f });
	}

	if (UEngineInput::IsPress('W'))
	{
		AddActorLocation(FVector{ 0.0f, 100.0f * _DeltaTime, 0.0f });
	}

	if (UEngineInput::IsPress('S'))
	{
		AddActorLocation(FVector{ 0.0f, -100.0f * _DeltaTime, 0.0f });
	}

	if (UEngineInput::IsPress('Q'))
	{
		AddActorRotation(FVector{ 0.0f, 0.0f , 360.0f * _DeltaTime });
	}

}