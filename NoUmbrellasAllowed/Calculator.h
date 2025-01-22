#pragma once
#include <EngineCore/Actor.h>
#include "UI.h"



// ���� :
class ACalculator : public AUI
{
public:
	// constrcuter destructer
	ACalculator();
	~ACalculator();

	// delete Function
	ACalculator(const ACalculator& _Other) = delete;
	ACalculator(ACalculator&& _Other) noexcept = delete;
	ACalculator& operator=(const ACalculator& _Other) = delete;
	ACalculator& operator=(ACalculator&& _Other) noexcept = delete;

	

protected:

	void Tick(float _DeltaTime);
	void OnCollisionEnter(class UCollision* _This, class UCollision* _Other);
	void OnCollisionEnd(class UCollision* _This, class UCollision* _Other);
private:
	void ButtonClickCheck();

	std::shared_ptr<class USpriteRenderer> CalculatorRender;
	std::shared_ptr<class UCollision> CalculatorCollision;
	std::shared_ptr<class ACalculatorButton> Button;
	std::shared_ptr<class UFontRenderer> PriceText;

	std::string EntirePriceText = "0";
	std::string CurPriceText = "0";

	int EntirePrice = 0;
	int CurPrice = 0;

	bool IsEnter = false;
	int Acc = 0;
};

