#include "PreCompile.h"
#include "TitleGameMode.h"
#include "Logo.h"

ATitleGameMode::ATitleGameMode()
{
	GetWorld()->SpawnActor<ALogo>();
}

ATitleGameMode::~ATitleGameMode()
{
}

void ATitleGameMode::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

}