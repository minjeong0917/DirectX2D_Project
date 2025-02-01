#include "PreCompile.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include "CalculatorButton.h"
#include <EngineCore/Collision.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/FontRenderer.h>

ACalculatorButton::ACalculatorButton()
{
    std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
    RootComponent = Default;

    FVector StartPos = { 580.0f,-582.0f,-151.0f };
    FVector IterPos = { 55.0f,-50.0f,0.0f };
    for (size_t i = 0; i < 10; i++)
    {
        ButtonRender = CreateDefaultSubObject<USpriteRenderer>();
        ButtonRender->SetSprite("Buttons", 0);
        ButtonRender->SetAutoScaleRatio(3.0f);

        NumButtonText = CreateDefaultSubObject<UFontRenderer>();
        NumButtonText->SetFont("OrangeKid", 45.0f, TColor<unsigned char>(182, 180, 172, 255), FW1_CENTER);
        NumButtonText->SetupAttachment(RootComponent);


        if (i < 9)
        {
            NumButtonText->SetText(std::to_string(i + 1));
        }
        else
        {
            NumButtonText->SetText(std::to_string(0));

        }

        ButtonCollision = CreateDefaultSubObject<UCollision>();
        ButtonCollision->SetCollisionProfileName("Button_" + std::to_string(i));

        if (i / 3 < 1)
        {
            ButtonRender->SetWorldLocation({ StartPos.X + (IterPos.X * i),StartPos.Y + IterPos.Y * (i / 3), -151.0f });
            NumButtonText->SetWorldLocation({ StartPos.X + (IterPos.X * i),StartPos.Y + IterPos.Y * (i / 3) + 55.0f, -155.0f });
        }
        else if (i / 3 >= 1.0f && i / 3 < 2.0f)
        {
            ButtonRender->SetWorldLocation({ StartPos.X + (IterPos.X * (i - 3)),StartPos.Y + IterPos.Y * (i / 3), -151.0f });
            NumButtonText->SetWorldLocation({ StartPos.X + (IterPos.X * (i - 3)),StartPos.Y + IterPos.Y * (i / 3) + 55.0f, -155.0f });


        }
        else if (i / 3 >= 2.0f && i / 3 < 3.0f)
        {
            ButtonRender->SetWorldLocation({ StartPos.X + (IterPos.X * (i - 6)),StartPos.Y + IterPos.Y * (i / 3), -151.0f });
            NumButtonText->SetWorldLocation({ StartPos.X + (IterPos.X * (i - 6)) ,StartPos.Y + IterPos.Y * (i / 3) + 55.0f, -155.0f });

        }
        else
        {
            ButtonRender->SetWorldLocation({ StartPos.X + (IterPos.X * (i - 8)),StartPos.Y + IterPos.Y * (i / 3), -151.0f });
            NumButtonText->SetWorldLocation({ StartPos.X + (IterPos.X * (i - 8)) ,StartPos.Y + IterPos.Y * (i / 3) + 55.0f, -155.0f });

        }
        ButtonCollision->SetRelativeLocation({ 0.0f,ButtonRender->GetTransformRef().Scale.hY(),0.0f });

        ButtonRender->SetupAttachment(RootComponent);
        ButtonCollision->SetupAttachment(ButtonRender);
        ButtonCollision->SetRelativeScale3D({ 0.8f,0.8f,0.0f });
        CollisionSet(ButtonCollision);

        AllCalculatorButtonRenders.push_back(ButtonRender);

    }

    // CE
    {
        CEButtonRender = CreateDefaultSubObject<USpriteRenderer>();
        CEButtonRender->SetSprite("Buttons", 2);
        CEButtonRender->SetAutoScaleRatio(3.0f);
        CEButtonRender->SetWorldLocation({ 748.0f, -630.0f, -151.0f });
        CEButtonRender->SetupAttachment(RootComponent);
        AllCalculatorButtonRenders.push_back(CEButtonRender);

        CEButtonText1 = CreateDefaultSubObject<UFontRenderer>();
        CEButtonText1->SetFont("DungGeunMo", 45.0f, TColor<unsigned char>(182, 180, 172, 255), FW1_CENTER);
        CEButtonText1->SetText("C");
        CEButtonText1->SetWorldLocation({ 748.0f, -540.0f, -155.0f });
        CEButtonText1->SetupAttachment(RootComponent);

        CEButtonText2 = CreateDefaultSubObject<UFontRenderer>();
        CEButtonText2->SetFont("DungGeunMo", 45.0f, TColor<unsigned char>(182, 180, 172, 255), FW1_CENTER);
        CEButtonText2->SetText("E");
        CEButtonText2->SetWorldLocation({ 748.0f, -575.0f, -155.0f });
        CEButtonText2->SetupAttachment(RootComponent);

        CEButtonCollision = CreateDefaultSubObject<UCollision>();
        CEButtonCollision->SetCollisionProfileName("Button_10");
        CEButtonCollision->SetRelativeLocation({ 0.0f,CEButtonRender->GetTransformRef().Scale.hY(),0.0f });
        CEButtonCollision->SetRelativeScale3D({ 0.8f,0.8f,0.0f });
        CEButtonCollision->SetupAttachment(CEButtonRender);

        CollisionSet(CEButtonCollision);

    }

    // Enter
    {
        EnterButtonRender = CreateDefaultSubObject<USpriteRenderer>();
        EnterButtonRender->SetSprite("Buttons", 5);
        EnterButtonRender->SetAutoScaleRatio(3.0f);
        EnterButtonRender->SetWorldLocation({ 720.0f, -730.0f, -151.0f });
        EnterButtonRender->SetupAttachment(RootComponent);
        AllCalculatorButtonRenders.push_back(EnterButtonRender);

        EnterButtonText = CreateDefaultSubObject<UFontRenderer>();
        EnterButtonText->SetFont("DungGeunMo", 30.0f, TColor<unsigned char>(182, 180, 172, 255), FW1_CENTER);
        EnterButtonText->SetText("제시");
        EnterButtonText->SetWorldLocation({ 740.0f, -687.0f, -155.0f });
        EnterButtonText->SetupAttachment(RootComponent);

        EnterButtonCollision = CreateDefaultSubObject<UCollision>();
        EnterButtonCollision->SetCollisionProfileName("Button_11");
        EnterButtonCollision->SetRelativeLocation({ 0.3f,EnterButtonRender->GetTransformRef().Scale.hY() + 0.2f,0.0f });
        EnterButtonCollision->SetRelativeScale3D({ 0.4f,0.5f,0.0f });
        EnterButtonCollision->SetupAttachment(EnterButtonRender);

        EnterButtonCollision2 = CreateDefaultSubObject<UCollision>();
        EnterButtonCollision2->SetCollisionProfileName("Button_11");
        EnterButtonCollision2->SetRelativeLocation({ 0.0f,0.2f,0.0f });
        EnterButtonCollision2->SetRelativeScale3D({ 1.0f,0.5f,0.0f });
        EnterButtonCollision2->SetupAttachment(EnterButtonRender);

        CollisionSet(EnterButtonCollision);
        CollisionSet(EnterButtonCollision2);
    }

    // 거래 포기
    {
        NotDealButtonRender = CreateDefaultSubObject<USpriteRenderer>();
        NotDealButtonRender->SetSprite("Buttons",6);
        NotDealButtonRender->SetAutoScaleRatio(3.0f);
        NotDealButtonRender->SetWorldLocation({ 605.0f, -815.0f, -151.0f });
        NotDealButtonRender->SetupAttachment(RootComponent);
        AllCalculatorButtonRenders.push_back(NotDealButtonRender);

        NotDealButtonText = CreateDefaultSubObject<UFontRenderer>();
        NotDealButtonText->SetFont("DungGeunMo", 26.0f, TColor<unsigned char>(182, 178, 142, 255), FW1_CENTER);
        NotDealButtonText->SetText("거래 포기");
        NotDealButtonText->SetWorldLocation({ 605.0f, -773.0f, -155.0f });
        NotDealButtonText->SetupAttachment(RootComponent);

        NotDealButtonCollision = CreateDefaultSubObject<UCollision>();
        NotDealButtonCollision->SetCollisionProfileName("Button_12");
        NotDealButtonCollision->SetRelativeLocation({ 0.0f,NotDealButtonRender->GetTransformRef().Scale.hY(),0.0f });
        NotDealButtonCollision->SetRelativeScale3D({ 1.0f,0.8f,0.0f });
        NotDealButtonCollision->SetupAttachment(NotDealButtonRender);

        CollisionSet(NotDealButtonCollision);

    }
    // 거래 수락
    {
        DealButtonRender = CreateDefaultSubObject<USpriteRenderer>();
        DealButtonRender->SetSprite("Buttons", 6);
        DealButtonRender->SetAutoScaleRatio(3.0f);
        DealButtonRender->SetRotation({ 0.0f, 180.f, 0.0f });
        DealButtonRender->SetWorldLocation({ 760.0f, -815.0f, -151.0f });
        DealButtonRender->SetupAttachment(RootComponent);
        AllCalculatorButtonRenders.push_back(DealButtonRender);

        NotDealButtonText = CreateDefaultSubObject<UFontRenderer>();
        NotDealButtonText->SetFont("DungGeunMo", 26.0f, TColor<unsigned char>(182, 178, 142, 255), FW1_CENTER);
        NotDealButtonText->SetText("거래 수락");
        NotDealButtonText->SetWorldLocation({ 760.0f, -773.0f, -155.0f });
        NotDealButtonText->SetupAttachment(RootComponent);


        DealButtonCollision = CreateDefaultSubObject<UCollision>();
        DealButtonCollision->SetCollisionProfileName("Button_13");
        DealButtonCollision->SetRelativeLocation({ 0.0f,DealButtonRender->GetTransformRef().Scale.hY(),0.0f });
        DealButtonCollision->SetRelativeScale3D({ 1.0f,0.8f,0.0f });
        DealButtonCollision->SetupAttachment(DealButtonRender);

        CollisionSet(DealButtonCollision);

    }
}

ACalculatorButton::~ACalculatorButton()
{

}

void ACalculatorButton::Tick(float _DeltaTime)
{
    AUI::Tick(_DeltaTime);

    if (IsMerchandiseActive == true && MerchandiseActive == 0)
    {
        EnterButtonRender->SetSprite("Buttons", 4);
        MerchandiseActive += 1;
    }
    else if (IsMerchandiseActive == false)
    {
        EnterButtonRender->SetSprite("Buttons", 5);

        MerchandiseActive = 0;
    }
}
void ACalculatorButton::OnCollisionEnter(UCollision* _This, UCollision* _Other)
{

    IsEnter = true;

}

void ACalculatorButton::OnCollisionStay(class UCollision* _This, class UCollision* _Other)
{
    std::string ProfileName = _This->GetCollisionProfileName();
    int Index = std::stoi(ProfileName.substr(7));
    CurButtonIndex = Index;

    if (UEngineInput::IsPress(VK_LBUTTON) && ProfileName != "NONE")
    {

        if (Index < 10)
        {
            AllCalculatorButtonRenders[Index]->SetSprite("Buttons", 1);
        }
        else if (Index == 10)
        {
            AllCalculatorButtonRenders[Index]->SetSprite("Buttons", 3);
        }
        else if (Index == 11)
        {
            AllCalculatorButtonRenders[Index]->SetSprite("Buttons", 5);
        }
        else if (Index == 12)
        {
            AllCalculatorButtonRenders[Index]->SetSprite("Buttons", 7);
        }
        else if (Index == 13)
        {
            AllCalculatorButtonRenders[Index]->SetSprite("Buttons", 7);
            AllCalculatorButtonRenders[Index]->SetRotation({0.0f, 180.f, 0.0f});
        }
    }
    else if (UEngineInput::IsUp(VK_LBUTTON))
    {
        IsEnter = true;


        if (Index < 10)
        {
            AllCalculatorButtonRenders[Index]->SetSprite("Buttons", 0);
        }
        else if (Index == 10)
        {
            AllCalculatorButtonRenders[Index]->SetSprite("Buttons", 2);
        }
        else if (Index == 11 && IsMerchandiseActive == true)
        {
            AllCalculatorButtonRenders[Index]->SetSprite("Buttons", 4);
        }
        else if (Index == 12 || Index == 13)
        {
            AllCalculatorButtonRenders[Index]->SetSprite("Buttons", 6);
        }
    }
}



void ACalculatorButton::OnCollisionEnd(UCollision* _This, UCollision* _Other)
{

    IsEnter = false;


    std::string EndProfileName = _This->GetCollisionProfileName();

    int Index = std::stoi(EndProfileName.substr(7));
    if (Index < 10)
    {
        AllCalculatorButtonRenders[Index]->SetSprite("Buttons", 0);
    }
    else if (Index == 10)
    {
        AllCalculatorButtonRenders[Index]->SetSprite("Buttons", 2);
    }
    else if (Index == 11 && IsMerchandiseActive == true)
    {
        AllCalculatorButtonRenders[Index]->SetSprite("Buttons", 4);
    }
    else if (Index == 12 || Index == 13)
    {
        AllCalculatorButtonRenders[Index]->SetSprite("Buttons", 6);
    }
}

void ACalculatorButton::CollisionSet(std::shared_ptr<class UCollision> _Collision)
{
    _Collision->SetCollisionEnter([this](UCollision* _This, UCollision* _Other)
        {
            this->OnCollisionEnter(_This, _Other);

        });
    _Collision->SetCollisionStay([this](UCollision* _This, UCollision* _Other)
        {
            this->OnCollisionStay(_This, _Other);

        });
    _Collision->SetCollisionEnd([this](UCollision* _This, UCollision* _Other)
        {
            this->OnCollisionEnd(_This, _Other);

        });
}