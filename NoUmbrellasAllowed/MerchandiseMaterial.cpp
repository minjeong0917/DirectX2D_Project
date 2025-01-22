#include "PreCompile.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include "MerchandiseMaterial.h"
#include <EngineCore/CameraActor.h>
#include <EngineCore/EngineCamera.h>
AMerchandiseMaterial::AMerchandiseMaterial()
{
    std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
    RootComponent = Default;

    MerchandiseMaterialRender = CreateDefaultSubObject<USpriteRenderer>();
    MerchandiseMaterialRender->SetSprite("Material", 0);
    //MerchandiseMaterialRender->SetAutoScaleRatio(3.0f);
    MerchandiseMaterialRender->SetAutoScale(false);
    MerchandiseMaterialRender->SetScale3D({ 90.0f, 108.0f, 1.0f });
    MerchandiseMaterialRender->SetWorldLocation({ 0.0f, -315.0f, -155.0f });
    MerchandiseMaterialRender->SetupAttachment(RootComponent);
}

AMerchandiseMaterial::~AMerchandiseMaterial()
{


}

void AMerchandiseMaterial::Tick(float _DeltaTime)
{
    AActor::Tick(_DeltaTime);

    std::shared_ptr<class ACameraActor> Camera = GetWorld()->GetCamera(0);
    FVector MousePos = Camera->ScreenMousePosToWorldPos();

    MerchandiseMaterialRender->SetWorldLocation({ MousePos.X + 8.0f, MousePos.Y - 18.0f, -155.0f });

}
