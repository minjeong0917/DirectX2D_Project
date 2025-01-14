#pragma once
#include "ContentsEnums.h"
// ���� :
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

	ECardColor GetCardColor()
	{
		return CardColor;
	}

	ECardType GetCardType()
	{
		return CardType;
	}

	int GetCardStep()
	{
		return CardStep;
	}
protected:

private:
	CardInfo();
	ECardColor CardColor = ECardColor::Blue;
	ECardType CardType = ECardType::NONE;
	int CardStep = 0;
};

