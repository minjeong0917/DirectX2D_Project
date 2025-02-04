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
		PlayerBalloonXSize = 200.0f;
		break;
	case 1:
		PlayerConversation = std::to_string(_Price) + "V쯤이 좋겠군요.";
		PlayerBalloonXSize = 225.0f;
		break;
	case 2:
		PlayerConversation = std::to_string(_Price) + "V면 될 것 같은데요.";
		PlayerBalloonXSize = 250.0f;
		break;
	case 3:
		PlayerConversation = std::to_string(_Price) + "V 어떠세요?";
		PlayerBalloonXSize = 200.0f;
		break;
	case 4:
		PlayerConversation = std::to_string(_Price) + "V는 괜찮나요?";
		PlayerBalloonXSize = 225.0f;
		break;
	case 5:
		PlayerConversation = std::to_string(_Price) + "V가 최선이네요.";
		PlayerBalloonXSize = 225.0f;
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
		PlayerBalloonXSize = 300.0f;
		break;
	case 1:
		PlayerConversation = "그냥 안 살게요.";
		PlayerBalloonXSize = 225.0f;
		break;
	case 2:
		PlayerConversation = "죄송하지만, 여기서 그만 둘게요.";
		PlayerBalloonXSize = 300.0f;
		break;
	default:
		break;
	}
}



void ConversationList::SetCustomerGoodDealConvo(int _Price, int _RandomConvo)
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
		CustomerBalloonXSize = 200.0f;
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
		CustomerBalloonXSize = 200.0f;
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
void ConversationList::SetCustomerGoodDealConvo2(int _RandomConvo)
{
	switch (_RandomConvo)
	{
	case 0:
		CustomerConversation = "처음부터 그렇게 해주지. 어쨌든 사주니 다행이네요!";
		CustomerBalloonXSize = 400.0f;
		CustomerBalloonYSize = 100.0f;
		break;
	case 1:
		CustomerConversation = "솔직히 좀 긴장했는데, 걱정할 게 없었네요.";
		CustomerBalloonXSize = 200.0f;
		CustomerBalloonYSize = 100.0f;
		break;
	case 2:
		CustomerConversation = "괜히 쫄았네요. 이렇게 쉽게 풀릴 거였으면!";
		CustomerBalloonXSize = 400.0f;
		CustomerBalloonYSize = 100.0f;
		break;
	case 3:
		CustomerConversation = "생각보다 거래가 쉬웠네요. 괜히 쫄았나 봐요, 내가!";
		CustomerBalloonXSize = 400.0f;
		CustomerBalloonYSize = 100.0f;
		break;
	case 4:
		CustomerConversation = "둘다 만족할 만한 가격이네요.";
		CustomerBalloonXSize = 200.0f;
		CustomerBalloonYSize = 100.0f;
		break;
	case 5:
		CustomerConversation = "그 정도면 우리 둘다 만족하겠네요.";
		CustomerBalloonXSize = 400.0f;
		CustomerBalloonYSize = 100.0f;
		break;

	default:
		break;
	}
}
void ConversationList::SetCustomerOfferPriceConvo(int _Price, int _RandomConvo)
{
	switch (_RandomConvo)
	{
	case 0:
		CustomerConversation = "적당히 서로 양보해서" + std::to_string(_Price) + "V로 가죠.";
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
		CustomerBalloonXSize = 200.0f;
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
		CustomerBalloonXSize = 200.0f;
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

void ConversationList::SetCustomerRefuseConvo(int _Price, int _RandomConvo)
{
	switch (_RandomConvo)
	{
	case 0:
		CustomerConversation = std::to_string(_Price) + "V? 어이가 없어서 말이 안 나오네요.";
		CustomerBalloonXSize = 400.0f;
		CustomerBalloonYSize = 100.0f;
		break;
	case 1:
		CustomerConversation = "말도 안 되는 소리. 그 돈 받곤 못 팔아요.";
		CustomerBalloonXSize = 400.0f;
		CustomerBalloonYSize = 100.0f;
		break;
	case 2:
		CustomerConversation = "뭐라고요?" + std::to_string(_Price) + "V ? 웃기지도 않네요.";
		CustomerBalloonXSize = 200.0f;
		CustomerBalloonYSize = 100.0f;
		break;
	case 3:
		CustomerConversation = std::to_string(_Price) + "V? 장난해요?";
		CustomerBalloonXSize = 400.0f;
		CustomerBalloonYSize = 100.0f;
		break;
	case 4:
		CustomerConversation = std::to_string(_Price) + "V은 너무 적은데요.";
		CustomerBalloonXSize = 400.0f;
		CustomerBalloonYSize = 100.0f;
		break;
	case 5:
		CustomerConversation = std::to_string(_Price) + "V은 심하네요.";
		CustomerBalloonXSize = 200.0f;
		CustomerBalloonYSize = 100.0f;
		break;
	case 6:
		CustomerConversation = std::to_string(_Price) + "V는 좀 적네요.";
		CustomerBalloonXSize = 400.0f;
		CustomerBalloonYSize = 100.0f;
		break;

	default:
		break;
	}
}

void ConversationList::SetCustomerNotDealConvo(int _Price, int _RandomConvo)
{
	switch (_RandomConvo)
	{
	case 0:
		CustomerConversation = "여기에 온 것 자체가 시간 낭비였네요.";
		CustomerBalloonXSize = 400.0f;
		CustomerBalloonYSize = 100.0f;
		break;
	case 1:
		CustomerConversation = "못해 먹겠네요. 안 팔고 말지, 그냥.";
		CustomerBalloonXSize = 400.0f;
		CustomerBalloonYSize = 100.0f;
		break;
	case 2:
		CustomerConversation = "짜증나서 못 해먹겠네요. 그냥 안 팔게요.";
		CustomerBalloonXSize = 200.0f;
		CustomerBalloonYSize = 100.0f;
		break;
	case 3:
		CustomerConversation = "어휴, 속 터져. 이제 그만 할래요.";
		CustomerBalloonXSize = 400.0f;
		CustomerBalloonYSize = 100.0f;
		break;
	case 4:
		CustomerConversation = "괜한 기대를 한 내 잘못이죠.";
		CustomerBalloonXSize = 400.0f;
		CustomerBalloonYSize = 100.0f;
		break;
	case 5:
		CustomerConversation = "처음부터 못 산다고 말을 하지 그랬어요.";
		CustomerBalloonXSize = 200.0f;
		CustomerBalloonYSize = 100.0f;
		break;
	case 6:
		CustomerConversation = "별 도움 안 되는 중고상점이네요.";
		CustomerBalloonXSize = 400.0f;
		CustomerBalloonYSize = 100.0f;
		break;
	case 7:
		CustomerConversation = "픽시보다도 융통성 없는 인간을 만나다니!";
		CustomerBalloonXSize = 400.0f;
		CustomerBalloonYSize = 100.0f;
		break;
	case 8:
		CustomerConversation = "지치네요. 그만 해요.";
		CustomerBalloonXSize = 400.0f;
		CustomerBalloonYSize = 100.0f;
		break;
	case 9:
		CustomerConversation = "싫으면 그냥 거절하지, 왜 사람 열을 올려요? 관둬요!";
		CustomerBalloonXSize = 400.0f;
		CustomerBalloonYSize = 100.0f;
		break;
	default:
		break;
	}
}

void ConversationList::SetCustomerPlayerNotDealConvo( int _RandomConvo)
{
	switch (_RandomConvo)
	{
	case 0:
		CustomerConversation = "좀 빨리 포기하시는 감이 있지만... 알겠어요.";
		CustomerBalloonXSize = 400.0f;
		CustomerBalloonYSize = 100.0f;
		break;
	case 1:
		CustomerConversation = "거절당할 거라곤 생각 못했는데. 좀 슬프네요.";
		CustomerBalloonXSize = 400.0f;
		CustomerBalloonYSize = 100.0f;
		break;
	case 2:
		CustomerConversation = "아, 안 사겠다구요? ...어쩔 수 없죠.";
		CustomerBalloonXSize = 200.0f;
		CustomerBalloonYSize = 100.0f;
		break;
	case 3:
		CustomerConversation = "좀 더 얘기해볼 수 있는데...";
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
