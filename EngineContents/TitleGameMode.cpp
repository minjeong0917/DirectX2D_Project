#include "PreCompile.h"
#include "TitleGameMode.h"
#include "Logo.h"
#include <EngineCore/CameraActor.h>
#include <EngineCore/SpriteRenderer.h>

ATitleGameMode::ATitleGameMode()
{

	{
		Logo = GetWorld()->SpawnActor<ALogo>();
		Logo->SetActorLocation({ 300.0f, 0.0f, 0.0f });
		Logo->GetRenderer()->SetSpriteData(4);
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

	static float Time = 1.0f;
	static int Index = 0;

	Logo->GetRenderer()->SetSpriteData(Index);

	Time -= _DeltaTime * 5 ;

	if (0.0f >= Time)
	{
		
		++Index;
		if (Index > 6)
		{
			Index = 0;

		}
		Time = 1.0f;
	}

}