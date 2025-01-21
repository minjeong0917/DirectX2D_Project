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
			BalloonXSize = 210.0f;
		}
		else if (_Index == 1)
		{
			PlayerConversation = "조금 손상된 상태네요.";
			BalloonXSize = 210.0f;
		}
		else if (_Index == 2)
		{
			PlayerConversation = "심하게 손상됐네요.";
			BalloonXSize = 210.0f;
		}
		else if (_Index == 3)
		{
			PlayerConversation = "무가치한 상태네요.";
			BalloonXSize = 210.0f;
		}
		else if (_Index == 4)
		{
			PlayerConversation = "지금은 손상이 많진 않지만 이건 잠재적 쓰레기예요.";
			BalloonXSize = 420.0f;
		}
		break;
	case ECardType::TEXTURE:
		break;
	default:
		break;
	}

}
