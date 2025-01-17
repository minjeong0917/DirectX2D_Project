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

			AllBasicCard[0].CardType = ECardType::TEXTURE;
			AllBasicCard[0].CardColor = ECardColor::Gray;
			AllBasicCard[0].CardNameNum = 0;

			AllBasicCard[1].CardType = ECardType::TEXTURE;
			AllBasicCard[1].CardColor = ECardColor::Green;
			AllBasicCard[1].CardNameNum = 2;

			AllBasicCard[2].CardType = ECardType::CONDITION;
			AllBasicCard[2].CardColor = ECardColor::Blue;
			AllBasicCard[2].CardNameNum = 3; // 완벽한 상태


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
