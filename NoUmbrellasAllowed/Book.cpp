#include "PreCompile.h"

#include "Book.h"
#include "BookButton.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/Collision.h>

ABook::ABook()
{
    std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
    RootComponent = Default;

    BookMainRender = CreateDefaultSubObject<USpriteRenderer>();
    BookMainRender->SetSprite("BookMain", 0);
    //BookMainRender->SetAutoScaleRatio(3.0f);
    BookMainRender->SetWorldLocation({ 670.0f, -410.0f, -170.0f });
    BookMainRender->SetupAttachment(RootComponent);

    BookMainCollision = CreateDefaultSubObject<UCollision>();
    BookMainCollision->SetCollisionProfileName("BookMain");
    BookMainCollision->SetWorldLocation({ 0.0f, 0.5f, 0.0f });
    BookMainCollision->SetupAttachment(BookMainRender);

    BookMainCollision->SetCollisionEnter([this](UCollision* _This, UCollision* _Other)
        {
            this->OnCollisionEnter(_This, _Other);
        });
    BookMainCollision->SetCollisionEnd([this](UCollision* _This, UCollision* _Other)
        {
            this->OnCollisionEnd(_This, _Other);

        });


}

ABook::~ABook()
{
}

void ABook::Tick(float _DeltaTime)
{
    AActor::Tick(_DeltaTime);
}

void ABook::OnCollisionEnter(UCollision* _This, UCollision* _Other)
{
    IsEnter = true;
}
void ABook::OnCollisionEnd(UCollision* _This, UCollision* _Other)
{
    IsEnter = false;
}

