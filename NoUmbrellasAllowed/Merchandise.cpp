#include "PreCompile.h"

#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/Collision.h>

#include "Merchandise.h"

AMerchandise::AMerchandise()
{
    std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
    RootComponent = Default;

    MerchandiseRender = CreateDefaultSubObject<USpriteRenderer>();
    MerchandiseRender->SetSprite("Bag", 0);
    MerchandiseRender->SetAutoScaleRatio(3.0f);
    MerchandiseRender->SetWorldLocation({ 0.0f, -260.0f, -150.0f });
    MerchandiseRender->SetupAttachment(RootComponent);

    MerchandiseCollision = CreateDefaultSubObject<UCollision>();
    MerchandiseCollision->SetCollisionProfileName("Merchandise");
    MerchandiseCollision->SetScale3D({ 1.2f,1.2f,0.0f });
    MerchandiseCollision->SetRelativeLocation({ 0.0f, 0.5f,0.0f });
    MerchandiseCollision->SetupAttachment(MerchandiseRender);

    MerchandiseCollision->SetCollisionEnter([this](UCollision* _This, UCollision* _Other)
        {
            this->OnCollisionEnter(_This, _Other);
        });
    MerchandiseCollision->SetCollisionEnd([this](UCollision* _This, UCollision* _Other)
        {
            this->OnCollisionEnd(_This, _Other);

        });

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

    if (IsApear == true && MerchandiseRender->ColorData.PlusColor.W <= 0.0f)
    {
        PlusAlpha(_DeltaTime);
    }
    else
    {
        Acc = 1.0f;
    }

}

void AMerchandise::PlusAlpha(float _DeltaTime)
{
    Acc += 0.01f;
    MerchandiseRender->ColorData.PlusColor.W += _DeltaTime * Speed * Acc;
}

void AMerchandise::OnCollisionEnter(UCollision* _This, UCollision* _Other)
{
    IsEnter = true;
}
void AMerchandise::OnCollisionEnd(UCollision* _This, UCollision* _Other)
{
    IsEnter = false;
}

