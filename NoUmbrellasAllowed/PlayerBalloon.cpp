#include "PreCompile.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include "PlayerBalloon.h"
#include "ConversationList.h"
#include <EngineCore/FontRenderer.h>

APlayerBalloon::APlayerBalloon()
{
    std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
    RootComponent = Default;

    PlayerBaloonRender = CreateDefaultSubObject<USpriteRenderer>();
    PlayerBaloonRender->SetSprite("Balloons", 0);
    PlayerBaloonRender->SetAutoScale(false);
    PlayerBaloonRender->SetScale3D({ 279.0f,117.0f,1.0f });
    PlayerBaloonRender->SetWorldLocation({ 0.0f, -500.0f, -810.0f });
    PlayerBaloonRender->SetupAttachment(RootComponent);

    PlayerText = CreateDefaultSubObject<UFontRenderer>();
    PlayerText->SetFont("PF", 20.0f, TColor<unsigned char>(39, 37, 43, 255), FW1_CENTER);
    PlayerText->SetWorldLocation({ 0.0f, -415.0f, -820.0f });
    PlayerText->SetupAttachment(RootComponent);
}

APlayerBalloon::~APlayerBalloon()
{
}

void APlayerBalloon::BeginPlay()
{
    AActor::BeginPlay();


}

void APlayerBalloon::SetPlayerBalloonAndText()
{
    BoxXScale = ConversationList::GetInst().GetPlayerBalloonXSize();
    Text = ConversationList::GetInst().GetPlayerConversation();

    PlayerBaloonRender->SetScale3D({ BoxXScale, 117.0f, 1.0f });
    PlayerText->SetText(Text);
}