#include "PreCompile.h"

#include "InvenInfo.h"
#include "MerchandiseInfo.h"
InvenInfo::InvenInfo()
{
	AllSlotInfos.resize(10);

}

InvenInfo::~InvenInfo()
{
}

void InvenInfo::SetSlotInfo(
	int _SlotNum, 
	std::string _MerchandiseName, 
	int _TotalCardCount,
	std::string _SpriteName, 
	int _SpriteIndex, 
	int _BuyPrice, 
	int _CardPrice,
	FVector _Scale)
{
	AllSlotInfos[_SlotNum].BuyPrice = _BuyPrice;
	AllSlotInfos[_SlotNum].CardPrice = _CardPrice;
	AllSlotInfos[_SlotNum].SpriteName = _SpriteName;
	AllSlotInfos[_SlotNum].SpriteIndex = _SpriteIndex;
	AllSlotInfos[_SlotNum].MerchandiseName = _MerchandiseName;
	AllSlotInfos[_SlotNum].TotalCardCount = _TotalCardCount;
	AllSlotInfos[_SlotNum].Scale = _Scale;

}


void InvenInfo::SetCardInfo(int _SlotNum, int _CardCount, ECardColor _Color, int CardStep, ECardType _CardType, int CardNum)
{
	// �ʿ��� ī�� ������ŭ ���� ũ�� ����
	if (_CardCount >= AllSlotInfos[_SlotNum].Cards.size())
	{
		AllSlotInfos[_SlotNum].Cards.resize(_CardCount + 1);
	}

	// ī�� ���� ����
	AllSlotInfos[_SlotNum].Cards[_CardCount].CardColor = _Color;
	AllSlotInfos[_SlotNum].Cards[_CardCount].CardStep = CardStep;
	AllSlotInfos[_SlotNum].Cards[_CardCount].CardType = _CardType;
	AllSlotInfos[_SlotNum].Cards[_CardCount].CardNum = CardNum;
}
