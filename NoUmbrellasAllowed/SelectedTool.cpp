#include "PreCompile.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/Collision.h>

#include "SelectedTool.h"
#include <EngineCore/CameraActor.h>
#include <EngineCore/EngineCamera.h>

ASelectedTool::ASelectedTool()
{
    std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
    RootComponent = Default;

    SelectdToolRender = CreateDefaultSubObject<USpriteRenderer>();
    SelectdToolRender->SetAutoScaleRatio(2.7f);
    SelectdToolRender->SetupAttachment(RootComponent);

    SelectdToolCollision = CreateDefaultSubObject<UCollision>();
    SelectdToolCollision->SetCollisionProfileName("SelectedTool");
    
    SelectdToolCollision->SetWorldLocation({ 0.0f, 0.5f,0.0f });

    SelectdToolCollision->SetupAttachment(SelectdToolRender);
}

ASelectedTool::~ASelectedTool()
{
}

void ASelectedTool::Tick(float _DeltaTime)
{
    AActor::Tick(_DeltaTime);
    std::shared_ptr<class ACameraActor> Camera = GetWorld()->GetCamera(0);
    FVector MousePos = Camera->ScreenMousePosToWorldPos();

    SelectdToolRender->SetWorldLocation({ MousePos.X + 8.0f, MousePos.Y - 40.0f, -160.0f });

}

void ASelectedTool::SetToolSprite(int _SpriteIndex)
{
    SelectdToolRender->SetSprite("SelectedTool", _SpriteIndex);
}
