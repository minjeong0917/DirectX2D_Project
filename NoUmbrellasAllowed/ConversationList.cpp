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
			PlayerConversation = "���°� �Ϻ��ϳ׿�.";
			BalloonXSize = 210.0f;
		}
		else if (_Index == 1)
		{
			PlayerConversation = "���� �ջ�� ���³׿�.";
			BalloonXSize = 210.0f;
		}
		else if (_Index == 2)
		{
			PlayerConversation = "���ϰ� �ջ�Ƴ׿�.";
			BalloonXSize = 210.0f;
		}
		else if (_Index == 3)
		{
			PlayerConversation = "����ġ�� ���³׿�.";
			BalloonXSize = 210.0f;
		}
		else if (_Index == 4)
		{
			PlayerConversation = "������ �ջ��� ���� ������ �̰� ������ �����⿹��.";
			BalloonXSize = 420.0f;
		}
		break;
	case ECardType::TEXTURE:
		break;
	default:
		break;
	}

}
