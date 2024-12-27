#include "PreCompile.h"
#include "Logo.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/DefaultSceneComponent.h>

ALogo::ALogo()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;


	LogoRenderer = CreateDefaultSubObject<USpriteRenderer>();
	LogoRenderer->SetSprite("plant_01_loop.png", 0);
	LogoRenderer->SetRelativeScale3D({ 230.0f, 400.0f, 1.0f });

	LogoRenderer->SetupAttachment(RootComponent);



	Child = CreateDefaultSubObject<USpriteRenderer>();

	Child->SetSprite("plant_01_loop.png", 2);
	Child->SetRelativeLocation({ 100.0f, 0.0f, 0.0f });
	Child->SetScale3D({ 50.0f, 50.0f, 1.0f });
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
		AddRelativeLocation(FVector{ -100.0f * _DeltaTime, 0.0f, 0.0f });
	}
	if (UEngineInput::IsPress('D'))
	{
		AddRelativeLocation(FVector{ 100.0f * _DeltaTime, 0.0f, 0.0f });
	}

	if (UEngineInput::IsPress('W'))
	{
		AddRelativeLocation(FVector{ 0.0f, 100.0f * _DeltaTime, 0.0f });
	}

	if (UEngineInput::IsPress('S'))
	{
		AddRelativeLocation(FVector{ 0.0f, -100.0f * _DeltaTime, 0.0f });
	}

	if (UEngineInput::IsPress('Q'))
	{
		AddActorRotation(FVector{ 0.0f, 0.0f , 360.0f * _DeltaTime });
	}

	if (UEngineInput::IsPress('E'))
	{
		// �� 1������ ó���Ǵ� �ɷ� 
		Child->AddRelativeLocation(FVector{ 100.0f * _DeltaTime, 0.0f , 0.0f });
	}

	if (UEngineInput::IsPress('R'))
	{
		Child->SetLocation(FVector{ 100.0f, 0.0f , 0.0f });
	}

	// AddActorLocation(FVector{ 100.0f * _DeltaTime, 0.0f, 0.0f});
}