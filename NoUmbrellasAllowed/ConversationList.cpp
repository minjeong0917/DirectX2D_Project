#include "PreCompile.h"

#include "ConversationList.h"

ConversationList::ConversationList()
{
}

ConversationList::~ConversationList()
{
}

void ConversationList::SetPlayerConversation(ECardType _CardType, int _Index)
{
	switch (_CardType)
	{
	case ECardType::NONE:
		break;
	case ECardType::BASIC:
		break;
	case ECardType::CONDITION:
		if (_Index == 0)
		{
			PlayerConversation = "상태가 완벽하네요.";
			PlayerBalloonXSize = 210.0f;
		}
		else if (_Index == 1)
		{
			PlayerConversation = "조금 손상된 상태네요.";
			PlayerBalloonXSize = 210.0f;
		}
		else if (_Index == 2)
		{
			PlayerConversation = "심하게 손상됐네요.";
			PlayerBalloonXSize = 210.0f;
		}
		else if (_Index == 3)
		{
			PlayerConversation = "무가치한 상태네요.";
			PlayerBalloonXSize = 210.0f;
		}
		else if (_Index == 4)
		{
			PlayerConversation = "지금은 손상이 많진 않지만 이건 잠재적 쓰레기예요.";
			PlayerBalloonXSize = 420.0f;
		}
		break;
	case ECardType::TEXTURE:
		if (_Index == 0)
		{
			PlayerConversation = "알루미늄 합금 소재네요.";
			PlayerBalloonXSize = 260.0f;
		}
		else if (_Index == 1)
		{
			PlayerConversation = "써지컬스틸이네요.";
			PlayerBalloonXSize = 210.0f;
		}
		else if (_Index == 2)
		{
			PlayerConversation = "플래티늄 소재네요.";
			PlayerBalloonXSize = 210.0f;
		}
		else if (_Index == 3)
		{
			PlayerConversation = "스테인레스스틸 소재네요.";
			PlayerBalloonXSize = 260.0f;
		}
		else if (_Index == 4)
		{
			PlayerConversation = "탄소섬유네요.";
			PlayerBalloonXSize = 210.0f;
		}
		else if (_Index == 5)
		{
			PlayerConversation = "14k 옐로골드네요.";
			PlayerBalloonXSize = 220.0f;
		}
		else if (_Index == 6)
		{
			PlayerConversation = "18k 화이트골드네요.";
			PlayerBalloonXSize = 210.0f;
		}
		else if (_Index == 7)
		{
			PlayerConversation = "은이네요.";
			PlayerBalloonXSize = 140.0f;
		}
		else if (_Index == 8)
		{
			PlayerConversation = "소가죽이네요.";
			PlayerBalloonXSize = 130.0f;
		}
		else if (_Index == 9)
		{
			PlayerConversation = "벨벳 소재네요.";
			PlayerBalloonXSize = 180.0f;
		}
		else if (_Index == 10)
		{
			PlayerConversation = "24K 골드 소재네요.";
			PlayerBalloonXSize = 210.0f;
		}
		else if (_Index == 11)
		{
			PlayerConversation = "종이네요.";
			PlayerBalloonXSize = 140.0f;
		}
		else if (_Index == 12)
		{
			PlayerConversation = "캔버스 소재네요.";
			PlayerBalloonXSize = 200.0f;
		}
		else if (_Index == 13)
		{
			PlayerConversation = "유리네요.";
			PlayerBalloonXSize = 140.0f;
		}
		else if (_Index == 14)
		{
			PlayerConversation = "플라스틱이네요.";
			PlayerBalloonXSize = 200.0f;
		}
		else if (_Index == 15)
		{
			PlayerConversation = "베이스메탈 소재네요.";
			PlayerBalloonXSize = 210.0f;
		}
		else if (_Index == 16)
		{
			PlayerConversation = "PVC네요.";
			PlayerBalloonXSize = 140.0f;
		}
		else if (_Index == 17)
		{
			PlayerConversation = "실리콘 소재네요.";
			PlayerBalloonXSize = 210.0f;
		}
		else if (_Index == 18)
		{
			PlayerConversation = "인조가죽이네요.";
			PlayerBalloonXSize = 200.0f;
		}
		else if (_Index == 19)
		{
			PlayerConversation = "면 소재네요.";
			PlayerBalloonXSize = 140.0f;
		}
		else if (_Index == 20)
		{
			PlayerConversation = "돌이네요.";
			PlayerBalloonXSize = 140.0f;
		}
		else if (_Index == 21)
		{
			PlayerConversation = "목재네요.";
			PlayerBalloonXSize = 140.0f;
		}
		else if (_Index == 22)
		{
			PlayerConversation = "점토 소재네요.";
			PlayerBalloonXSize = 200.0f;
		}
		else if (_Index == 23)
		{
			PlayerConversation = "밀랍이네요.";
			PlayerBalloonXSize = 160.0f;
		}
		break;
	default:
		break;
	}

}
void ConversationList::SetPlayerOfferPriceConvo(int _Price, int _RandomConvo)
{
	switch (_RandomConvo)
	{
	case 0:
		PlayerConversation = std::to_string(_Price) + "V 드릴게요.";
		PlayerBalloonXSize = 170.0f;
		break;
	case 1:
		PlayerConversation = std::to_string(_Price) + "V쯤이 좋겠군요.";
		PlayerBalloonXSize = 190.0f;
		break;
	case 2:
		PlayerConversation = std::to_string(_Price) + "V면 될 것 같은데요.";
		PlayerBalloonXSize = 200.0f;
		break;
	case 3:
		PlayerConversation = std::to_string(_Price) + "V 어떠세요?";
		PlayerBalloonXSize = 200.0f;
		break;
	case 4:
		PlayerConversation = std::to_string(_Price) + "V는 괜찮나요?";
		PlayerBalloonXSize = 200.0f;
		break;
	case 5:
		PlayerConversation = std::to_string(_Price) + "V가 최선이네요.";
		PlayerBalloonXSize = 200.0f;
		break;
	default:
		break;
	}
}


void ConversationList::SetPlayerNotDealConvo(int _RandomConvo)
{
	switch (_RandomConvo)
	{
	case 0:
		PlayerConversation = "안 사는 게 나을 것 같네요.";
		PlayerBalloonXSize = 200.0f;
		break;
	case 1:
		PlayerConversation = "그냥 안 살게요.";
		PlayerBalloonXSize = 200.0f;
		break;
	case 2:
		PlayerConversation = "죄송하지만, 여기서 그만 둘게요.";
		PlayerBalloonXSize = 200.0f;
		break;
	default:
		break;
	}
}

void ConversationList::SetCustomerDealConvo(int _Price, int _RandomConvo)
{
	switch (_RandomConvo)
	{
	case 0:
		CustomerConversation = std::to_string(_Price) + "V면 정말 괜찮네요!";
		CustomerBalloonXSize = 400.0f;
		CustomerBalloonYSize = 100.0f;
		break;
	case 1:
		CustomerConversation = "굳이 마다할 필요가 없죠! 좋아요.";
		CustomerBalloonXSize = 400.0f;
		CustomerBalloonYSize = 100.0f;
		break;
	case 2:
		CustomerConversation = "나야 좋죠!";
		CustomerBalloonXSize = 400.0f;
		CustomerBalloonYSize = 100.0f;
		break;
	case 3:
		CustomerConversation = std::to_string(_Price) + "V를 누가 마다하겠어요?";
		CustomerBalloonXSize = 400.0f;
		CustomerBalloonYSize = 100.0f;
		break;
	case 4:
		CustomerConversation = std::to_string(_Price) + "V라니. 생각보다 인심이 후하시네요.";
		CustomerBalloonXSize = 400.0f;
		CustomerBalloonYSize = 100.0f;
		break;
	case 5:
		CustomerConversation = std::to_string(_Price) + "V! 아싸!";
		CustomerBalloonXSize = 400.0f;
		CustomerBalloonYSize = 100.0f;
		break;
	case 6:
		CustomerConversation = std::to_string(_Price) + "V는 기대도 안 했는데!";
		CustomerBalloonXSize = 400.0f;
		CustomerBalloonYSize = 100.0f;
		break;
	
	default:
		break;
	}
}


void ConversationList::SetCustomerCardConversation(ECardType _CardType, bool _IsPriceUp, int _RandomConversation)
{
	switch (_CardType)
	{
	case ECardType::NONE:
		break;
	case ECardType::BASIC:
		break;
	case ECardType::CONDITION:
		if (_IsPriceUp == true)
		{
			switch (_RandomConversation)
			{
			case 0:
				CustomerConversation = "돈을 더 받을 수 있다는 얘기군요!";
				CustomerBalloonXSize = 400.0f;
				CustomerBalloonYSize = 100.0f;

				break;
			case 1:
				CustomerConversation = "내가 괜히 저평가하고 있었나봐요. 사실대로 \n알려줘서 고마워요!";
				CustomerBalloonXSize = 400.0f;
				CustomerBalloonYSize = 120.0f;

				break;
			case 2:
				CustomerConversation = "사실 그쯤일 줄 알았어요.";
				CustomerBalloonXSize = 250.0f;
				CustomerBalloonYSize = 100.0f;

				break;
			default:
				break;
			}
		}
		else if (_IsPriceUp == false)
		{
			switch (_RandomConversation)
			{
			case 0:
				CustomerConversation = "이 정도면 그냥 넘어갈 법도 한데... 알았어요.";
				CustomerBalloonXSize = 400.0f;
				CustomerBalloonYSize = 100.0f;

				break;
			case 1:
				CustomerConversation = "어, 내가 틀렸나 보네요.";
				CustomerBalloonXSize = 250.0f;
				CustomerBalloonYSize = 100.0f;

				break;
			case 2:
				CustomerConversation = "깐깐하시네요. 알겠어요.";
				CustomerBalloonXSize = 250.0f;
				CustomerBalloonYSize = 100.0f;

				break;
			default:
				break;
			}

		}

		break;

	case ECardType::TEXTURE:
		if (_IsPriceUp == true)
		{
			switch (_RandomConversation)
			{
			case 0:
				CustomerConversation = "어쩐지 나도 긴가민가했어요.";
				CustomerBalloonXSize = 400.0f;
				CustomerBalloonYSize = 100.0f;

				break;
			case 1:
				CustomerConversation = "내가 괜히 저평가하고 있었나봐요. 사실대로\n알려줘서 고마워요!";
				CustomerBalloonXSize = 400.0f;
				CustomerBalloonYSize = 120.0f;

				break;
			case 2:
				CustomerConversation = "내가 실수했나 봐요.";
				CustomerBalloonXSize = 250.0f;
				CustomerBalloonYSize = 100.0f;

				break;
			default:
				break;
			}
		}
		else if (_IsPriceUp == false)
		{
			switch (_RandomConversation)
			{
			case 0:
				CustomerConversation = "어쩐지 재질이 좀 찝찝하긴 했는데... 알겠어요.";
				CustomerBalloonXSize = 420.0f;
				CustomerBalloonYSize = 100.0f;

				break;
			case 1:
				CustomerConversation = "어, 내가 틀렸나 보네요.";
				CustomerBalloonXSize = 250.0f;
				CustomerBalloonYSize = 100.0f;

				break;
			case 2:
				CustomerConversation = "뭐, 난 전문가가 아니잖아요.";
				CustomerBalloonXSize = 250.0f;
				CustomerBalloonYSize = 100.0f;

				break;
			default:
				break;
			}

		}
		break;
	default:
		break;
	}

}
