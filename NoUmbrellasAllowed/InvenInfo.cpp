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

void InvenInfo::SetSlotInfo(int _SlotNum, int _BuyPrice, int _CardPrice)
{
	AllSlotInfos[_SlotNum].BuyPrice = _BuyPrice;
	AllSlotInfos[_SlotNum].CardPrice = _CardPrice;;

}
