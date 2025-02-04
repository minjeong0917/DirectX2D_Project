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

	bool GetIsPushEnter()
	{
		return IsPushEnter;
	}
	bool GetIsPushDeal()
	{
		return IsPushDeal;
	}
	bool GetIsPushNotDeal()
	{
		return IsPushNotDeal;
	}


	void SetIsPushEnter(bool _IsPush)
	{
		IsPushEnter = _IsPush;
	}
	void SetIsPushDeal(bool _IsPush)
	{
		IsPushDeal = _IsPush;
	}
	void SetIsPushNotDeal(bool _IsPush)
	{
		IsPushNotDeal = _IsPush;
	}
	void SetClear();

	int GetEntirePrice()
	{
		return EntirePrice;
	}

	int GetDealPrice()
	{
		return DealPrice;
	}
	void SetDealPrice(int _DealPrice)
	{
		DealPrice = _DealPrice;
	}

	void ButtonClickCheck();

	void SetIsMerchandiseActive(bool _IsMerchandiseActive)
	{
		IsMerchandiseActive = _IsMerchandiseActive;
	}

protected:

	void Tick(float _DeltaTime);
	void OnCollisionEnter(class UCollision* _This, class UCollision* _Other);
	void OnCollisionEnd(class UCollision* _This, class UCollision* _Other);
private:

	std::shared_ptr<class USpriteRenderer> CalculatorRender;
	std::shared_ptr<class UCollision> CalculatorCollision;
	std::shared_ptr<class ACalculatorButton> Button;
	std::shared_ptr<class UFontRenderer> PriceText;

	std::string EntirePriceText = "0";
	std::string CurPriceText = "0";

	int EntirePrice = 0;
	int CurPrice = 0;
	int DealPrice = 0;

	bool IsPushEnter = false;
	bool IsPushDeal = false;
	bool IsPushNotDeal = false;

	bool IsMerchandiseActive = false;


	bool IsEnter = false;
	int Acc = 0;
};

