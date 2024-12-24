#include "PreCompile.h"
#include "TitleGameMode.h"
#include "Logo.h"
#include <EngineCore/CameraActor.h>
#include <EngineCore/SpriteRenderer.h>

ATitleGameMode::ATitleGameMode()
{

	{
		std::shared_ptr<ALogo> TitleLogo = GetWorld()->SpawnActor<ALogo>();





		TitleLogo->SetActorLocation({ -350.0f, 0.0f, 0.0f });
	}

	{
		std::shared_ptr<ALogo> Logo = GetWorld()->SpawnActor<ALogo>();
		Logo->SetActorLocation({ 350.0f, 0.0f, 0.0f });
		Logo->GetRenderer()->SetSpriteData({ 0.3f, 0.3f }, { 0.4f, 0.4f });
	}

	std::shared_ptr<ACameraActor> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation({ 0.0f, 0.0f, -1000.0f, 1.0f });
}

ATitleGameMode::~ATitleGameMode()
{
}

void ATitleGameMode::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

}