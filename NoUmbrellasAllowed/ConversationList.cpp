#include "PreCompile.h"

#include "ConversationList.h"

ConversationList::ConversationList()
{
}

ConversationList::~ConversationList()
{
}

void ConversationList::SetPlayerConverastion(ECardType _CardType, int _Index)
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
		break;
	default:
		break;
	}

}
