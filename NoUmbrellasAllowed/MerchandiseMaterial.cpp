#include "PreCompile.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include "MerchandiseMaterial.h"
#include <EngineCore/CameraActor.h>
#include <EngineCore/EngineCamera.h>
#include <EngineCore/EngineTexture.h>

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

    std::shared_ptr<UEngineTexture> Texture = UEngineTexture::Find<UEngineTexture>("000.png");
    
    MatSize = Texture->GetTextureSize()*3.0f;
    ViewSize = MerchandiseMaterialRender->GetWorldScale3D();
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

    FVector ScreenScale = UEngineCore::GetScreenScale();
    FVector ScreenCenter = { ScreenScale.hX(), ScreenScale.hY() };

    FVector MouseInRenderSpace = {  MousePos.X - ScreenCenter.X, ScreenCenter.Y - MousePos.Y };

    MerchandiseMaterialRender->SpriteData.CuttingPos = { MouseInRenderSpace.X / MatSize.X + 0.5f,   MouseInRenderSpace.Y / MatSize.Y -0.22f};
    MerchandiseMaterialRender->SpriteData.CuttingSize = ViewSize / MatSize;

}

void AMerchandiseMaterial::SetMerchandiseMat(int _Index)
{

    MerchandiseMaterialRender->SetSprite("Material", _Index);

    if (_Index < 10)
    {
        std::shared_ptr<UEngineTexture> Texture = UEngineTexture::Find<UEngineTexture>("00" + std::to_string(_Index) + ".png");
        MatSize = Texture->GetTextureSize() * 3.0f;
        ViewSize = MerchandiseMaterialRender->GetWorldScale3D();
    }
    else
    {
        std::shared_ptr<UEngineTexture> Texture = UEngineTexture::Find<UEngineTexture>("0" + std::to_string(_Index) + ".png");
        MatSize = Texture->GetTextureSize() * 3.0f;
        ViewSize = MerchandiseMaterialRender->GetWorldScale3D();
    }
}
