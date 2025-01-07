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
    CursorRender->SetSprite("Cursor", 0);
    CursorRender->SetAutoScaleRatio(2.0f);
    CursorRender->SetupAttachment(RootComponent);

    CursorCollision = CreateDefaultSubObject<UCollision>();
    CursorCollision->SetCollisionProfileName("Cursor");
    CursorCollision->SetScale3D({ 20.0f,20.0f,0.0f });
    CursorCollision->SetRelativeLocation({ CursorCollision->GetTransformRef().WorldLocation.X, CursorCollision->GetTransformRef().WorldLocation.Y + 30.0f });
    CursorCollision->SetupAttachment(RootComponent);
}

ACursor::~ACursor()
{
}

void ACursor::Tick(float _DeltaTime)
{
    AActor::Tick(_DeltaTime);


}


