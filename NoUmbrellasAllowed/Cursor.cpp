#include "PreCompile.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include "Cursor.h"
#include <EngineCore/EngineCore.h>
#include <EngineCore/Collision.h>

ACursor::ACursor()
{
    std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
    RootComponent = Default;

    CursorRender = CreateDefaultSubObject<USpriteRenderer>();
    //CursorRender->SetSprite("Cursor", 0);
    CursorRender->SetAutoScaleRatio(2.0f);
    CursorRender->SetupAttachment(RootComponent);

    CursorCollision = CreateDefaultSubObject<UCollision>();
    CursorCollision->SetCollisionProfileName("Cursor");
    CursorCollision->SetScale3D({ 4.0f,4.0f,10000.0f });
    CursorCollision->SetRelativeLocation({ CursorCollision->GetTransformRef().WorldLocation.X - 10, CursorCollision->GetTransformRef().WorldLocation.Y + 35.0f, CursorCollision->GetTransformRef().WorldLocation.Z });
    CursorCollision->SetupAttachment(RootComponent);

    CursorCollision->SetCollisionEnter([this](UCollision* _This, UCollision* _Other)
        {
            this->OnCollisionEnter(_This, _Other);
        });
    CursorCollision->SetCollisionEnd([this](UCollision* _This, UCollision* _Other)
        {
            this->OnCollisionEnd(_This, _Other);

        });
}

ACursor::~ACursor()
{

}

void ACursor::Tick(float _DeltaTime)
{
    AActor::Tick(_DeltaTime);

    if (IsEnter == true)
    {
        //CursorRender->SetSprite("Cursor", 1);
    }
    if (IsEnter == false)
    {
        //CursorRender->SetSprite("Cursor", 0);
    }
}
void ACursor::OnCollisionEnter(UCollision* _This, UCollision* _Other)
{
    IsEnter = true;
}
void ACursor::OnCollisionEnd(UCollision* _This, UCollision* _Other)
{
    IsEnter = false;
}

void ACursor::SetRenderActive(bool _IsActive)
{
    CursorRender->SetActive(_IsActive);
}

