#include "PreCompile.h"

#include "CardInfo.h"
#include "BookPageInfo.h"

CardInfo::CardInfo()
{


}

CardInfo::~CardInfo()
{
}

void CardInfo::SetSelectedCardInfo()
{
	if (BookPageInfo::GetInst().GetCurPage() == 7)
	{
		CardType = ECardType::CONDITION;
		CardColor = ECardColor::Blue;
		CardStep = 0;

	}
	CardTypeInfo();
}


void CardInfo::CardTypeInfo()
{
	switch (CardType)
	{
	case ECardType::NONE:
		break;
	case ECardType::CONDITION:

		AllCardType.resize(5);

		AllCardType[0].CardName = "완벽한 상태";
		AllCardType[0].CardExplanation = "가격을 10% 올립니다";
		AllCardType[0].CardPercent = 10;

		AllCardType[1].CardName = "조금 손상";
		AllCardType[1].CardExplanation = "가격을 20% 내립니다";
		AllCardType[1].CardPercent = -20;

		AllCardType[2].CardName = "심한 손상";
		AllCardType[2].CardExplanation = "가격을 60% 내립니다";
		AllCardType[2].CardPercent = -60;

		AllCardType[3].CardName = "가치 상실";
		AllCardType[3].CardExplanation = "가격을 90% 내립니다";
		AllCardType[3].CardPercent = -90;

		AllCardType[4].CardName = "잠재적 쓰레기";
		AllCardType[4].CardExplanation = "심한손상일때와 가치상실일때 사용 불가능..?";
		AllCardType[4].CardPercent = -25;

		break;
	case ECardType::TEXTURE:
		break;
	default:
		break;
	}
}
