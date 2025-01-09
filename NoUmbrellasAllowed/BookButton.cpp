#include "PreCompile.h"

#include "Bookbutton.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/Collision.h>

ABookButton::ABookButton()
{
    std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
    RootComponent = Default;

    BackButtonRender = CreateDefaultSubObject<USpriteRenderer>();
    BackButtonRender->SetSprite("BookButton", 0);
    BackButtonRender->SetAutoScaleRatio(3.0f);
    BackButtonRender->SetWorldLocation({ 910.0f, 303.0f, -172.0f });
    BackButtonRender->SetupAttachment(RootComponent);
    AllBookButtonRenders.push_back(BackButtonRender);

    BackButtonCollision = CreateDefaultSubObject<UCollision>();
    BackButtonCollision->SetCollisionProfileName("BookButton_0");
    BackButtonCollision->SetWorldLocation({ 0.0f, 0.5f, 0.0f });
    BackButtonCollision->SetupAttachment(BackButtonRender);

    BackButtonCollision->SetCollisionStay([this](UCollision* _This, UCollision* _Other)
        {
            this->OnCollisionStay(_This, _Other);
        });
    BackButtonCollision->SetCollisionEnd([this](UCollision* _This, UCollision* _Other)
        {
            this->OnCollisionEnd(_This, _Other);

        });
}

ABookButton::~ABookButton()
{
}

void ABookButton::Tick(float _DeltaTime)
{
    AActor::Tick(_DeltaTime);
}

void ABookButton::OnCollisionStay(UCollision* _This, UCollision* _Other)
{
    if (UEngineInput::IsDown(VK_LBUTTON))
    {
        BackButtonRender->SetSprite("BookButton", 1);
        IsBack = true;
    }
}
void ABookButton::OnCollisionEnd(UCollision* _This, UCollision* _Other)
{
    IsBack = false;

}