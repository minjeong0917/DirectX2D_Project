#include "PreCompile.h"
#include "CustomerBalloon.h"

#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include "ConversationList.h"
#include <EngineCore/FontRenderer.h>

ACustomerBalloon::ACustomerBalloon()
{
    std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
    RootComponent = Default;

    CustomerBaloonRender = CreateDefaultSubObject<USpriteRenderer>();
    CustomerBaloonRender->SetSprite("Balloons", 1);
    CustomerBaloonRender->SetAutoScale(false);
    CustomerBaloonRender->SetScale3D({ 279.0f,100.0f,1.0f });
    CustomerBaloonRender->SetWorldLocation({ 0.0f, 240.0f, -810.0f });
    CustomerBaloonRender->SetupAttachment(RootComponent);

    CustomerText = CreateDefaultSubObject<UFontRenderer>();
    CustomerText->SetFont("PF", 20.0f, TColor<unsigned char>(39, 37, 43, 255), FW1_CENTER);
    CustomerText->SetWorldLocation({ 0.0f, 310.0f, -820.0f });
    CustomerText->SetText("¾È³çÇÏ¼¼¿ä");
    CustomerText->SetupAttachment(RootComponent);
}

ACustomerBalloon::~ACustomerBalloon()
{
}

void ACustomerBalloon::SetCustomerBalloonAndText()
{
    BoxXScale = ConversationList::GetInst().GetCustomerBalloonXSize();
    BoxYScale = ConversationList::GetInst().GetCustomerBalloonYSize();
    Text = ConversationList::GetInst().GetCustomerConversation();

    CustomerBaloonRender->SetScale3D({ BoxXScale, BoxYScale , 1.0f });
    CustomerText->SetText(Text);
    CustomerText->SetWorldLocation({ 0.0f, 210.0f + BoxYScale , -820.0f });
}