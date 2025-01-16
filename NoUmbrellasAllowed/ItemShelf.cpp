#include "PreCompile.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/Collision.h>
#include "ItemShelf.h"
#include "Tools.h"
#include <EnginePlatform/EngineInput.h>
AItemShelf::AItemShelf()
{
    std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
    RootComponent = Default;

    ItemShelfRender = CreateDefaultSubObject<USpriteRenderer>();
    ItemShelfRender->SetSprite("ItemShelf", 1);
    ItemShelfRender->SetAutoScaleRatio(3.0f);
    ItemShelfRender->SetWorldLocation({ 0.0f, -580.0f, -152.0f });
    ItemShelfRender->SetupAttachment(RootComponent);

    ItemShelfCollision = CreateDefaultSubObject<UCollision>();
    ItemShelfCollision->SetCollisionProfileName("ItemShelf");
    ItemShelfCollision->SetScale3D({ 500.0f,80.0f,0.0f });
    ItemShelfCollision->SetRelativeLocation({0.0f, -415.0f, -152.0f});
    ItemShelfCollision->SetupAttachment(RootComponent);

    ItemShelfCollision->SetCollisionEnter([this](UCollision* _This, UCollision* _Other)
        {
            this->OnCollisionEnter(_This, _Other);
        });
    ItemShelfCollision->SetCollisionEnd([this](UCollision* _This, UCollision* _Other)
        {
            this->OnCollisionEnd(_This, _Other);

        });

    Tools = GetWorld()->SpawnActor<ATools>();

}

AItemShelf::~AItemShelf()
{
}

void AItemShelf::Tick(float _DeltaTime)
{
    AActor::Tick(_DeltaTime);

    if (IsEnter == true)
    {
        if (ItemShelfRender->GetTransformRef().WorldLocation.Y <= -490.0f)
        {
            ItemShelfRender->AddRelativeLocation({ 0.0f, 500.0f * _DeltaTime, 0.0f });
            Tools->AddRelativeLocation({ 0.0f, 500.0f * _DeltaTime, 0.0f });
        }
    }

    if (IsEnter == false)
    {
        if (ItemShelfRender->GetTransformRef().WorldLocation.Y > -600.0f)
        {
            ItemShelfRender->AddRelativeLocation({ 0.0f, -500.0f * _DeltaTime, 0.0f });
            Tools->AddRelativeLocation({ 0.0f, -500.0f * _DeltaTime, 0.0f });
        }
    }
    
}

void AItemShelf::OnCollisionEnter(UCollision* _This, UCollision* _Other)
{
    IsEnter = true;
}
void AItemShelf::OnCollisionEnd(UCollision* _This, UCollision* _Other)
{
    IsEnter = false;
}

bool AItemShelf::GetIsToolsClick()
{
    if (Tools == nullptr)
    {
        return false;
    }

    return Tools->GetIsToolClick();
}

bool AItemShelf::IsSelectedToolActive()
{
    return Tools->IsSelectedToolActive();
}
