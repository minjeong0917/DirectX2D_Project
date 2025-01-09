#include "PreCompile.h"

#include "BookSmall.h"

#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/Collision.h>

ABookSmall::ABookSmall()
{
    std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
    RootComponent = Default;

    BookSmallGroundRender = CreateDefaultSubObject<USpriteRenderer>();
    BookSmallGroundRender->SetSprite("BookSmall", 0);
    BookSmallGroundRender->SetAutoScaleRatio(3.0f);
    BookSmallGroundRender->SetWorldLocation({ -380.0f, -255.0f, -170.0f });
    BookSmallGroundRender->SetupAttachment(RootComponent);

    BookSmallRender = CreateDefaultSubObject<USpriteRenderer>();
    BookSmallRender->SetSprite("BookSmall", 1);
    BookSmallRender->SetAutoScaleRatio(3.0f);
    BookSmallRender->SetWorldLocation({ -380.0f, -255.0f, -170.0f });
    BookSmallRender->SetupAttachment(RootComponent);

    BookSmallCollision = CreateDefaultSubObject<UCollision>();
    BookSmallCollision->SetCollisionProfileName("BookSmall");
    BookSmallCollision->SetWorldLocation({ 0.0f, 0.5f, 0.0f });
    BookSmallCollision->SetupAttachment(BookSmallRender);

    BookSmallCollision->SetCollisionStay([this](UCollision* _This, UCollision* _Other)
        {
            this->OnCollisionStay(_This, _Other);
        });
    BookSmallCollision->SetCollisionEnd([this](UCollision* _This, UCollision* _Other)
        {
            this->OnCollisionEnd(_This, _Other);

        });

}

ABookSmall::~ABookSmall()
{
}

void ABookSmall::Tick(float _DeltaTime)
{
    AActor::Tick(_DeltaTime);
}

void ABookSmall::OnCollisionStay(UCollision* _This, UCollision* _Other)
{
    if (UEngineInput::IsDown(VK_LBUTTON))
    {
        IsSmallBookClick = true;
        BookSmallRender->SetActive(false);
    }
}
void ABookSmall::OnCollisionEnd(UCollision* _This, UCollision* _Other)
{

}

void ABookSmall::SetRenderActive(bool _IsActive)
{
    BookSmallRender->SetActive(_IsActive);
}
