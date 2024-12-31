#include "PreCompile.h"
#include "Bob.h"
#include <EngineBase/EngineDebug.h>
#include <EnginePlatform/EngineInput.h>

ABob::ABob()
{
}

ABob::~ABob()
{
}

void ABob::BeginPlay()
{
	APawn::BeginPlay();
}

void ABob::Tick(float _DeltaTime)
{
	APawn::Tick(_DeltaTime);


}

