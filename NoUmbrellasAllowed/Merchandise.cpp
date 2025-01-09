#include "PreCompile.h"

#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EnginePlatform/EngineInput.h>

#include "Merchandise.h"

AMerchandise::AMerchandise()
{
    std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
    RootComponent = Default;

    MerchandiseRender = CreateDefaultSubObject<USpriteRenderer>();
    MerchandiseRender->SetSprite("Merchandise", 0);
    MerchandiseRender->SetAutoScaleRatio(3.0f);
    MerchandiseRender->SetWorldLocation({ 0.0f, -260.0f, -150.0f });
    MerchandiseRender->SetupAttachment(RootComponent);

}

AMerchandise::~AMerchandise()
{
}

void AMerchandise::BeginPlay()
{
    AActor::BeginPlay();

    MerchandiseRender->ColorData.PlusColor.W -= 1.0f;
}

void AMerchandise::Tick(float _DeltaTime)
{
    AActor::Tick(_DeltaTime);


}

void AMerchandise::PlusAlpha(float _DeltaTime, float _Speed)
{
    MerchandiseRender->ColorData.PlusColor.W += _DeltaTime * _Speed;
}
