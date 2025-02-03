#include "PreCompile.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/Collision.h>
#include <EnginePlatform/EngineInput.h>
#include "UI.h"
#include "Calculator.h"
#include "CalculatorButton.h"
#include <EngineCore/FontRenderer.h>
#include "PlayerInfo.h"

ACalculator::ACalculator()
{
    std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
    RootComponent = Default;

    CalculatorRender = CreateDefaultSubObject<USpriteRenderer>();
    CalculatorRender->CreateAnimation("Calculator", "Entity", 0, 2, 0.2f);
    CalculatorRender->ChangeAnimation("Calculator");
    CalculatorRender->SetAutoScaleRatio(3.0f);
    CalculatorRender->SetWorldLocation({ 680.0f, -840.0f, -150.0f });
    CalculatorRender->SetupAttachment(RootComponent);

    CalculatorCollision = CreateDefaultSubObject<UCollision>();
    CalculatorCollision->SetCollisionProfileName("Calculator");
    CalculatorCollision->SetScale3D({ 330.0f,462.0f,0.0f });
    CalculatorCollision->SetRelativeLocation({ CalculatorRender->GetTransformRef().WorldLocation.X, CalculatorRender->GetTransformRef().WorldLocation.Y + 231.0f , CalculatorRender->GetTransformRef().WorldLocation.Z, });
    CalculatorCollision->SetupAttachment(RootComponent);

    CalculatorCollision->SetCollisionEnter([this](UCollision* _This, UCollision* _Other)
        {
            this->OnCollisionEnter(_This, _Other);
        });
    CalculatorCollision->SetCollisionEnd([this](UCollision* _This, UCollision* _Other)
        {
            this->OnCollisionEnd(_This, _Other);

        });

    Button = GetWorld()->SpawnActor<ACalculatorButton>();

    PriceText = CreateDefaultSubObject<UFontRenderer>();
    PriceText->SetFont("OrangeKid", 64.0f, TColor<unsigned char>(220, 225, 131, 255), FW1_RIGHT);
    PriceText->SetText("0");
    PriceText->SetWorldLocation({ 793.0f, -403.0f, -155.0f });
    PriceText->SetupAttachment(RootComponent);

}

ACalculator::~ACalculator()
{
}

void ACalculator::Tick(float _DeltaTime)
{
    AUI::Tick(_DeltaTime);
    ButtonClickCheck();

    if (IsMerchandiseActive == true)
    {
        Button->SetIsMerchandiseActive(true);
    }
    else if (IsMerchandiseActive == false)
    {
        Button->SetIsMerchandiseActive(false);

    }

    if (IsEnter == true)
    {
        if (CalculatorRender->GetTransformRef().WorldLocation.Y < -440.0f)
        {
            Acc += 5;
            CalculatorRender->AddRelativeLocation({ 0.0f,1.0f * _DeltaTime * 20 * Acc,0.0f });
            PriceText->AddRelativeLocation({ 0.0f,1.0f * _DeltaTime * 20 * Acc,0.0f });
            Button->AddRelativeLocation({ 0.0f,1.0f * _DeltaTime * 20 * Acc,0.0f });
        }
    }
    if (IsEnter == false)
    {
        Acc = 0;
        if (CalculatorRender->GetTransformRef().WorldLocation.Y > -840.0f)
        {
            CalculatorRender->AddRelativeLocation({ 0.0f,-1.0f * _DeltaTime * 900, 0.0f });
            PriceText->AddRelativeLocation({ 0.0f,-1.0f * _DeltaTime * 900, 0.0f });

            Button->AddRelativeLocation({ 0.0f,-1.0f * _DeltaTime * 900, 0.0f });
        }
    }
    CalculatorCollision->SetRelativeLocation({ CalculatorRender->GetTransformRef().WorldLocation.X, CalculatorRender->GetTransformRef().WorldLocation.Y + 231.0f });
}

void ACalculator::SetClear()
{
    PriceText->SetText("0");
    CurPriceText = "0";
    CurPrice = 0;
    EntirePriceText = "0";
    EntirePrice = 0;
}


void ACalculator::ButtonClickCheck()
{
    if (UEngineInput::IsUp(VK_LBUTTON) && Button->GetButtonIsEnter() == true)
    {
        int CurNum = Button->GetCurButtonIndex();
        if (CurNum < 10) // num 
        {
            if (CurNum < 9) // 1 ~ 9
            {
                CurPriceText = std::to_string(CurNum + 1);
                CurPrice = CurNum + 1;
            }
            else if (CurNum == 9) // 0
            {
                CurPriceText = std::to_string(0);
                CurPrice = 0;
            }

            if (EntirePriceText == "0")
            {
                EntirePriceText = CurPriceText;
                EntirePrice = CurPrice;
            }
            else
            {
                EntirePriceText = EntirePriceText + CurPriceText;

                if (CurPrice >= 0 && CurPrice <= 9)
                {
                    if (EntirePrice == 0)
                    {
                        EntirePrice = CurPrice;
                    }
                    else
                    {
                        EntirePrice = EntirePrice * 10 + CurPrice;
                    }
                }
            }
        }
        else if (CurNum == 10) // CE
        {
            EntirePriceText = "0";
            EntirePrice = 0;
        }
        else if (CurNum == 11) // Enter
        {
            if (IsMerchandiseActive == true)
            {
                //int CurGold = PlayerInfo::GetInst().GetGold();
                IsPushEnter = true;
                EntirePriceText = "0";
                DealPrice = EntirePrice;
                EntirePrice = 0;
            }
    

        }
        else if (CurNum == 12) // 거래 포기
        {
            if (IsMerchandiseActive == true)
            {

                IsPushNotDeal = true;

            }


        }
        else if (CurNum == 13) // 거래수락
        {
            if (IsMerchandiseActive == true)
            {
                int CurGold = PlayerInfo::GetInst().GetGold();
                IsPushDeal = true;

                PlayerInfo::GetInst().SetGold(CurGold - DealPrice);

            }

        }
        PriceText->SetText(EntirePriceText);
        UEngineDebug::OutPutString(std::to_string(EntirePrice));
    }

}


void ACalculator::OnCollisionEnter(UCollision* _This, UCollision* _Other)
{
    IsEnter = true;
}
void ACalculator::OnCollisionEnd(UCollision* _This, UCollision* _Other)
{
    IsEnter = false;
    IsPushEnter = false;
    IsPushDeal = false;
    IsPushNotDeal = false;

}

