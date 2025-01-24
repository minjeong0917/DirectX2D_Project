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

void InvenInfo::SetSlotInfo(int _SlotNum, std::string _MerchandiseName, 
	int _TotalCardCount,
	std::string _SpriteName, 
	int _SpriteIndex, 
	int _BuyPrice, 
	int _CardPrice)
{
	AllSlotInfos[_SlotNum].BuyPrice = _BuyPrice;
	AllSlotInfos[_SlotNum].CardPrice = _CardPrice;
	AllSlotInfos[_SlotNum].SpriteName = _SpriteName;
	AllSlotInfos[_SlotNum].SpriteIndex = _SpriteIndex;
	AllSlotInfos[_SlotNum].MerchandiseName = _MerchandiseName;
	AllSlotInfos[_SlotNum].TotalCardCount = _TotalCardCount;

}
