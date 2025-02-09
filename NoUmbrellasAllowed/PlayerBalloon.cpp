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
    PlayerText->SetFont("PF", 20.0f, TColor<unsigned char>(39, 37, 43, 255), FW1_LEFT);
    PlayerText->SetWorldLocation({ 0.0f, -415.0f, -820.0f });
    PlayerText->SetText(" ");
    PlayerText->SetupAttachment(RootComponent);
}

APlayerBalloon::~APlayerBalloon()
{
}

void APlayerBalloon::BeginPlay()
{
    AActor::BeginPlay();


}
void APlayerBalloon::Tick(float _DeltaTime)
{
    AActor::Tick(_DeltaTime);

    if (IsStartEffect == true)
    {
        static float Timer = 0.0f;
        Timer += _DeltaTime;

        static float SoundTimer = 0.0f;
        SoundTimer += _DeltaTime;

        if (Timer >= 0.03f && CurrentTextIndex < FullText.size())
        {
            Timer = 0.0f; 
            CurrentDisplayedText += FullText[CurrentTextIndex]; 
            PlayerText->SetText(CurrentDisplayedText);
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
void APlayerBalloon::SetPlayerBalloonAndText()
{
    BoxXScale = ConversationList::GetInst().GetPlayerBalloonXSize();
    FullText = ConversationList::GetInst().GetPlayerConversation();

    PlayerBaloonRender->SetScale3D({ BoxXScale, 117.0f, 1.0f });
    PlayerText->SetWorldLocation({ 30.0f - BoxXScale/2, -415.0f, -820.0f });

    CurrentDisplayedText = " ";
    PlayerText->SetText(CurrentDisplayedText);
    CurrentDisplayedText = "";

    IsStartEffect = true;
    CurrentTextIndex = 0;
    //PlayerText->SetText(Text);
}