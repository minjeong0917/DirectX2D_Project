#pragma once
#include <EngineCore/Actor.h>
#include "UI.h"



// Ό³Έν :
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
private:

	std::shared_ptr<class USpriteRenderer> CalculatorRender;

};

