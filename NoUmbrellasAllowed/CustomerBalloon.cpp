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
    CustomerText->SetFont("PF", 20.0f, TColor<unsigned char>(39, 37, 43, 255), FW1_LEFT);
    CustomerText->SetWorldLocation({ 0.0f, 310.0f, -820.0f });
    CustomerText->SetText("¾È³çÇÏ¼¼¿ä");
    CustomerText->SetupAttachment(RootComponent);
}

ACustomerBalloon::~ACustomerBalloon()
{
}

void ACustomerBalloon::Tick(float _DeltaTime)
{
    AActor::Tick(_DeltaTime);

    if (IsStartEffect == true)
    {
        static float Timer = 0.0f;
        Timer += _DeltaTime;

        static float SoundTimer = 0.0f;
        SoundTimer += _DeltaTime;


        if (Timer >= 0.01f && CurrentTextIndex < FullText.size())
        {
            Timer = 0.0f;
            CurrentDisplayedText += FullText[CurrentTextIndex];
            CustomerText->SetText(CurrentDisplayedText);
            CurrentTextIndex++;


        }
        if (SoundTimer > 0.1f)
        {
            SoundTimer = 0.0f;
            SoundPlayer = UEngineSound::Play("Blip_Neutral.wav");
        }
        if (CurrentTextIndex >= FullText.size())
        {
            IsStartEffect = false;
        }
    }

}
void ACustomerBalloon::SetCustomerBalloonAndText()
{
    BoxXScale = ConversationList::GetInst().GetCustomerBalloonXSize();
    BoxYScale = ConversationList::GetInst().GetCustomerBalloonYSize();
    FullText = ConversationList::GetInst().GetCustomerConversation();

    CustomerBaloonRender->SetScale3D({ BoxXScale, BoxYScale , 1.0f });
    CustomerText->SetWorldLocation({ 30.0f - BoxXScale / 2, 210.0f + BoxYScale , -820.0f });

    CurrentDisplayedText = " ";
    CustomerText->SetText(CurrentDisplayedText);
    CurrentDisplayedText = "";

    IsStartEffect = true;
    CurrentTextIndex = 0;
    //PlayerText->SetText(Text);
}