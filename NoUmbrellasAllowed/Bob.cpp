#include "PreCompile.h"
#include "Bob.h"
#include <EngineBase/EngineDebug.h>
#include <EnginePlatform/EngineInput.h>

#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/FontRenderer.h>

#include "PlayerInfo.h"

ABob::ABob()
{
    std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
    RootComponent = Default;

    GoldText = CreateDefaultSubObject<UFontRenderer>();
    GoldText->SetFont("DungGeunMo", 52.0f, TColor<unsigned char>(255, 255, 255, 255), FW1_RIGHT);
    GoldText->SetWorldLocation({ 820.0f,520.0f,-850.0f });
    GoldText->SetupAttachment(RootComponent);

}

ABob::~ABob()
{
}

void ABob::BeginPlay()
{
	APawn::BeginPlay();
}

void ABob::Tick(float _DeltaTime)
{
	APawn::Tick(_DeltaTime);

    int CurGold = PlayerInfo::GetInst().GetGold();
    GoldText->SetText(std::to_string(CurGold) + "V");
}

