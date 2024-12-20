#include "PreCompile.h"
#include "TitleGameMode.h"
#include "Logo.h"
#include <EngineCore/CameraActor.h>

ATitleGameMode::ATitleGameMode()
{
	GetWorld()->SpawnActor<ALogo>();

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