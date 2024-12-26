#include "PreCompile.h"
#include "Logo.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>

ALogo::ALogo()
{
	LogoRenderer = CreateDefaultSubObject<USpriteRenderer>();
	LogoRenderer->SetSprite("plant_01_loop.png", 0);

	// -�� ���� ��� -> �������Ϳ��� cull��忡�� ���� -> Back���� ���������� �ݽð�������� �ٲ�� ȭ�鿡 ���� ����..! NONE���� �ϸ� �ݴ�� �������� ȭ�鿡 ��..!
	SetActorRelativeScale3D({ 230.0f, 400.0f, 1.0f });

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

}