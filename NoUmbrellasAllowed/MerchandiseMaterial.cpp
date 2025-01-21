#include "PreCompile.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include "MerchandiseMaterial.h"

AMerchandiseMaterial::AMerchandiseMaterial()
{
    std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
    RootComponent = Default;

    MerchandiseMaterialRender = CreateDefaultSubObject<USpriteRenderer>();
    MerchandiseMaterialRender->SetSprite("Material", 0);
    MerchandiseMaterialRender->SetAutoScaleRatio(3.0f);
    MerchandiseMaterialRender->SetWorldLocation({ 0.0f, -320.0f, -155.0f });
    MerchandiseMaterialRender->SetupAttachment(RootComponent);
}

AMerchandiseMaterial::~AMerchandiseMaterial()
{
}

