#include "PreCompile.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include "Customer.h"

ACustomer::ACustomer()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;
	CustomerRenderer = CreateDefaultSubObject<USpriteRenderer>();
	CustomerRenderer->SetupAttachment(RootComponent);

}

ACustomer::~ACustomer()
{
}

