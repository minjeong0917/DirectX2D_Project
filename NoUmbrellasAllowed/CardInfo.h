#pragma once
#include "ContentsEnums.h"
// Ό³Έν :
class CardInfo
{
public:
	// constrcuter destructer
	~CardInfo();

	// delete Function
	CardInfo(const CardInfo& _Other) = delete;
	CardInfo(CardInfo&& _Other) noexcept = delete;
	CardInfo& operator=(const CardInfo& _Other) = delete;
	CardInfo& operator=(CardInfo&& _Other) noexcept = delete;
	static CardInfo& GetInst()
	{
		static CardInfo Inst = CardInfo();
		return Inst;
	}

	void SetCardInfo();

	ECardType GetCardColor()
	{
		return CardColor;
	}

	int GetCardStep()
	{
		return CardStep;
	}
protected:

private:
	CardInfo();
	ECardType CardColor = ECardType::Blue;
	int CardStep = 0;
};

