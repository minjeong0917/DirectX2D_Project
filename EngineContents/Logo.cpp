#include "PreCompile.h"
#include "Logo.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>

ALogo::ALogo()
{
	LogoRenderer = CreateDefaultSubObject<USpriteRenderer>();
	LogoRenderer->SetSprite("title_logo2.png");

	// -�� ���� ��� -> �������Ϳ��� cull��忡�� ���� -> Back���� ���������� �ݽð�������� �ٲ�� ȭ�鿡 ���� ����..! NONE���� �ϸ� �ݴ�� �������� ȭ�鿡 ��..!
	SetActorRelativeScale3D({ 700.0f, 250.0f, 1.0f });

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