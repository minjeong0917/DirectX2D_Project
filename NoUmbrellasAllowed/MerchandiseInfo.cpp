#include "PreCompile.h"
#include "MerchandiseInfo.h"

MerchandiseInfo::MerchandiseInfo()
{

}

MerchandiseInfo::~MerchandiseInfo()
{

}

void MerchandiseInfo::SetMerchandiseInfo(bool _IsFake, EMerchandiseType _MerchandiseType, int _Index)
{
	MerchandiseType = _MerchandiseType;

	switch (MerchandiseType)
	{
	case EMerchandiseType::NONE:
		break;
	case EMerchandiseType::BAG:
		if (_Index == 0)
		{
			AllBasicCard.resize(3);
			AllBasicCard[0].CardType = ECardType::CONDITION;
			AllBasicCard[0].CardColor = ECardColor::Blue;
			AllBasicCard[0].CardName = 0;

			AllBasicCard[1].CardType = ECardType::TEXTURE;
			AllBasicCard[1].CardColor = ECardColor::Green;
			AllBasicCard[1].CardName = 0;

			AllBasicCard[2].CardType = ECardType::TEXTURE;
			AllBasicCard[2].CardColor = ECardColor::Gray;
			AllBasicCard[2].CardName = 0;

			if (_IsFake == false)
			{


			}
			else if (_IsFake == true)
			{

			}
		}



		break;
	case EMerchandiseType::UMBRELLA:
		break;
	default:
		break;
	}


}
