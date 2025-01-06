#include "PreCompile.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include "UI.h"

#include "Calculator.h"


ACalculator::ACalculator()
{
    std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
    RootComponent = Default;

    CalculatorRender = CreateDefaultSubObject<USpriteRenderer>();
    CalculatorRender->CreateAnimation("Calculator", "Entity", 0, 2, 0.2f);
    CalculatorRender->ChangeAnimation("Calculator");
    CalculatorRender->SetAutoScaleRatio(3.0f);
    CalculatorRender->SetWorldLocation({ 680.0f, -440.0f, 0.0f });
    CalculatorRender->SetupAttachment(RootComponent);


}

ACalculator::~ACalculator()
{
}

void ACalculator::Tick(float _DeltaTime)
{
    AUI::Tick(_DeltaTime);
}


