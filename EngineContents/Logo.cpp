#include "PreCompile.h"
#include "Logo.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>

ALogo::ALogo()
{
	LogoRenderer = CreateDefaultSubObject<USpriteRenderer>();

	// -�� ���� ��� -> �������Ϳ��� cull��忡�� ���� -> Back���� ���������� �ݽð�������� �ٲ�� ȭ�鿡 ���� ����..! NONE���� �ϸ� �ݴ�� �������� ȭ�鿡 ��..!
	SetActorRelativeScale3D({ 100.0f, 100.0f, 1.0f });
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
	AddActorLocation(FVector{ 0.1f, 0.0f, 0.0f });

}