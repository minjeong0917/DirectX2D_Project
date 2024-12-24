#include "PreCompile.h"
#include "Logo.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>

ALogo::ALogo()
{
	LogoRenderer = CreateDefaultSubObject<USpriteRenderer>();
	LogoRenderer->SetSprite("title_logo2.png");

	// -를 넣을 경우 -> 레지스터에서 cull모드에서 영향 -> Back으로 설정했으면 반시계방향으로 바뀌어 화면에 뜨지 않음..! NONE으로 하면 반대로 뒤집혀서 화면에 뜸..!
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