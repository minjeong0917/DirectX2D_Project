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

		AllCardType[0].CardName = "�Ϻ��� ����";
		AllCardType[0].CardExplanation = "������ 10% �ø��ϴ�";
		AllCardType[0].CardPercent = 10;

		AllCardType[1].CardName = "���� �ջ�";
		AllCardType[1].CardExplanation = "������ 20% �����ϴ�";
		AllCardType[1].CardPercent = -20;

		AllCardType[2].CardName = "���� �ջ�";
		AllCardType[2].CardExplanation = "������ 60% �����ϴ�";
		AllCardType[2].CardPercent = -60;

		AllCardType[3].CardName = "��ġ ���";
		AllCardType[3].CardExplanation = "������ 90% �����ϴ�";
		AllCardType[3].CardPercent = -90;

		AllCardType[4].CardName = "������ ������";
		AllCardType[4].CardExplanation = "���Ѽջ��϶��� ��ġ����϶� ��� �Ұ���..?";
		AllCardType[4].CardPercent = -25;

		break;
	case ECardType::TEXTURE:
		break;
	default:
		break;
	}
}
