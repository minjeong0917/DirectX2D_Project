#include "PreCompile.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/Collision.h>

#include "UI.h"
#include "Calculator.h"
#include "CalculatorButton.h"

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
    CalculatorCollision->SetScale3D({330.0f,462.0f,0.0f});
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

    Button = GetWorld()->SpawnActor<AButton>();


}

ACalculator::~ACalculator()
{
}

void ACalculator::Tick(float _DeltaTime)
{
    AUI::Tick(_DeltaTime);


    if (IsEnter == true)
    {
        if (CalculatorRender->GetTransformRef().WorldLocation.Y < -440.0f)
        {
            Acc += 5;
            CalculatorRender->AddRelativeLocation({ 0.0f,1.0f * _DeltaTime * 20 * Acc,0.0f });
            Button->AddRelativeLocation({ 0.0f,1.0f * _DeltaTime * 20 * Acc,0.0f });
        }
    }
    if (IsEnter == false)
    {
        Acc = 0;
        if (CalculatorRender->GetTransformRef().WorldLocation.Y > -840.0f)
        {
            CalculatorRender->AddRelativeLocation({ 0.0f,-1.0f * _DeltaTime * 900, 0.0f });
            Button->AddRelativeLocation({ 0.0f,-1.0f * _DeltaTime * 900, 0.0f });
        }
    }
    CalculatorCollision->SetRelativeLocation({ CalculatorRender->GetTransformRef().WorldLocation.X, CalculatorRender->GetTransformRef().WorldLocation.Y + 231.0f });
}

void ACalculator::OnCollisionEnter(UCollision* _This, UCollision* _Other)
{
    IsEnter = true;
}
void ACalculator::OnCollisionEnd(UCollision* _This, UCollision* _Other)
{
    IsEnter = false;
}

