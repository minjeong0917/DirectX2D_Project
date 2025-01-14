#include "PreCompile.h"

#include "CardInfo.h"
#include "BookPageInfo.h"

CardInfo::CardInfo()
{
}

CardInfo::~CardInfo()
{
}

void CardInfo::SetCardInfo()
{
	if (BookPageInfo::GetInst().GetCurPage() == 7)
	{
		CardColor = ECardType::Blue;
		CardStep = 0;
	}
}
