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

    SelectdToolFrontRender = CreateDefaultSubObject<USpriteRenderer>();
    SelectdToolFrontRender->SetAutoScaleRatio(2.7f);
    SelectdToolFrontRender->SetupAttachment(RootComponent);

    SelectdToolAccessoriesRender = CreateDefaultSubObject<USpriteRenderer>();
    SelectdToolAccessoriesRender->SetAutoScaleRatio(2.7f);
    SelectdToolAccessoriesRender->SetupAttachment(RootComponent);


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
    SelectdToolFrontRender->SetWorldLocation({ MousePos.X + 8.0f, MousePos.Y - 40.0f, -164.0f });
    SelectdToolAccessoriesRender->SetWorldLocation({ MousePos.X + 8.0f, MousePos.Y - 28.0f, -162.0f });

}

void ASelectedTool::SetToolSprite(int _SpriteIndex)
{
    SelectdToolRender->SetSprite("SelectedTool", _SpriteIndex);
}

void ASelectedTool::SetToolAccessoriesSprite(int _SpriteIndex)
{
    SelectdToolAccessoriesRender->SetSprite("SelectedTool", _SpriteIndex);
    SelectdToolFrontRender->SetSprite("SelectedTool", _SpriteIndex + 1);

}

void ASelectedTool::SetToolAccRotation(float _Rotation, float _Speed)
{
    float CurrentRotation = SelectdToolAccessoriesRender->GetTransformRef().Rotation.Z;

    if (CurrentRotation + (_Rotation * _Speed) <= 52.0f && CurrentRotation + (_Rotation * _Speed) >= -52.0f)
    {
        SelectdToolAccessoriesRender->AddLocalRotation({ 0.0f, 0.0f, _Rotation * _Speed });
    }
    
}


float ASelectedTool::GetAccRotZ()
{
    return SelectdToolAccessoriesRender->GetTransformRef().Rotation.Z;
}

void ASelectedTool::SetToolFrontActive(bool _IsActive)
{
    SelectdToolFrontRender->SetActive(_IsActive);
    SelectdToolAccessoriesRender->SetActive(_IsActive);
}

