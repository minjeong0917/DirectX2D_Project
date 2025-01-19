#pragma once
#include "ContentsEnums.h"
// Ό³Έν :

struct CardType
{
	std::string CardName;
	std::string CardExplanation;
	std::string CardPercentText;
	int CardPercent;
	float CardNameTextSize = 25.0f;
};

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

	void SetSelectedCardInfo();
	void CardTypeInfo();

	ECardColor GetCardColor()
	{
		return CardColor;
	}

	ECardType GetCardType()
	{
		return CardType;
	}

	void SetCardType(ECardType _CardType)
	{
		CardType = _CardType;
	}

	int GetCardStep()
	{
		return CardStep;
	}

	std::vector<struct CardType> GetAllCardType()
	{
		return AllCardType;
	}

protected:

private:
	CardInfo();
	ECardColor CardColor = ECardColor::Blue;
	ECardType CardType = ECardType::NONE;
	int CardStep = 0;
	float NameTextSize = 25.0f;
	std::vector<struct CardType> AllCardType;
};

