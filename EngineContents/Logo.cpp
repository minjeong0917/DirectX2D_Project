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

	// -�� ���� ��� -> �������Ϳ��� cull��忡�� ���� -> Back���� ���������� �ݽð�������� �ٲ�� ȭ�鿡 ���� ����..! NONE���� �ϸ� �ݴ�� �������� ȭ�鿡 ��..!
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