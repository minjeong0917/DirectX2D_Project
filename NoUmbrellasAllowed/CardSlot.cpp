#include "PreCompile.h"

#include "CardSlot.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/Collision.h>
#include <EngineCore/FontRenderer.h>

ACardSlot::ACardSlot()
{
    std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
    RootComponent = Default;
    for (int i = 0; i < 6; i++)
    {
        CardSlotRender = CreateDefaultSubObject<USpriteRenderer>();
        CardSlotRender->SetSprite("CardCase", i);
        CardSlotRender->SetAutoScaleRatio(3.0f);
        AllCardSlotRender.push_back(CardSlotRender);
        AllCardSlotRender[i]->SetWorldLocation({-730.0f, -260.0f, -151.0f + i * (-2.0f)});
        CardSlotRender->SetupAttachment(RootComponent);
    }
    
    CardSlotCollision = CreateDefaultSubObject<UCollision>();
    CardSlotCollision->SetCollisionProfileName("CardSlot");
    CardSlotCollision->SetRelativeLocation({ 0.0f, 0.5f,0.0f });
    CardSlotCollision->SetupAttachment(AllCardSlotRender[0]);

    CardSlotCollision->SetCollisionEnter([this](UCollision* _This, UCollision* _Other)
        {
            this->OnCollisionEnter(_This, _Other);
        });
    CardSlotCollision->SetCollisionEnd([this](UCollision* _This, UCollision* _Other)
        {
            this->OnCollisionEnd(_This, _Other);

        });



    UpDownRender = CreateDefaultSubObject<USpriteRenderer>();
    UpDownRender->SetSprite("CardCase", 7);
    UpDownRender->SetAutoScaleRatio(3.0f);
    UpDownRender->SetWorldLocation({ -768.0f, -223.0f, -180.0f });
    UpDownRender->SetupAttachment(RootComponent);

    UpDownText = CreateDefaultSubObject<UFontRenderer>();
    UpDownText->SetFont("DungGeunMo", 32.0f, TColor<unsigned char>(96, 234, 53, 255), FW1_LEFT);
    UpDownText->SetWorldLocation({ -783.0f,-175.0f,-180.0f });
    UpDownText->SetText("180V");
    UpDownText->SetupAttachment(RootComponent);

    CardSlotInfoRender = CreateDefaultSubObject<USpriteRenderer>();
    CardSlotInfoRender->SetSprite("CardCase", 6);
    CardSlotInfoRender->SetAutoScaleRatio(3.0f);
    CardSlotInfoRender->SetWorldLocation({ -730.0f, -100.0f, -145.0f });
    CardSlotInfoRender->SetupAttachment(RootComponent);

    MerchandiseNameText = CreateDefaultSubObject<UFontRenderer>();
    MerchandiseNameText->SetFont("DungGeunMo", 26.0f, TColor<unsigned char>(245, 222, 96, 255), FW1_CENTER);
    MerchandiseNameText->SetWorldLocation({ 0.0f, 0.9f,-0.01f });
    MerchandiseNameText->SetText("180V");
    MerchandiseNameText->SetupAttachment(CardSlotInfoRender);
}

ACardSlot::~ACardSlot()
{
}

void ACardSlot::Tick(float _DeltaTime)
{
    AActor::Tick(_DeltaTime);

    if (IsActive == true)
    {
        if (CardSlotInfoRender->GetTransformRef().WorldLocation.Y < 7.0f)
        {
            CardSlotInfoRender->AddWorldLocation({ 0.0f, 100.0f * _DeltaTime , 0.0f });
        }
    }
}
void ACardSlot::SetMerchandiseNameText(std::string _Name)
{
    MerchandiseNameText->SetText(_Name);
}
void ACardSlot::SetUpDownText(int _Price)
{
    std::string PriceText = std::to_string(_Price);
    UpDownText->SetText(PriceText + "V");
    if (_Price >= 0)
    {
        UpDownRender->SetSprite("CardCase", 7);
        UpDownText->SetFont("DungGeunMo", 32.0f, TColor<unsigned char>(96, 234, 53, 255), FW1_LEFT);


    }
    else if (_Price < 0)
    {
        UpDownRender->SetSprite("CardCase", 8);
        UpDownText->SetFont("DungGeunMo", 32.0f, TColor<unsigned char>(251, 100, 57, 255), FW1_LEFT);

    }
}

void ACardSlot::SetUpDownActive(bool _IsActive)
{
    IsUpdownActive = _IsActive;
    UpDownRender->SetActive(_IsActive);
    UpDownText->SetActive(_IsActive);
}
void ACardSlot::SetNameTextActive(bool _IsActive)
{

    MerchandiseNameText->SetActive(_IsActive);
}

void ACardSlot::OnCollisionEnter(UCollision* _This, UCollision* _Other)
{
    IsEnter = true;
}

void ACardSlot::OnCollisionEnd(UCollision* _This, UCollision* _Other)
{
    IsEnter = false;
}

