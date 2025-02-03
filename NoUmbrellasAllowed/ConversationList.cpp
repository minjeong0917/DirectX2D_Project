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
			PlayerConversation = "���°� �Ϻ��ϳ׿�.";
			PlayerBalloonXSize = 210.0f;
		}
		else if (_Index == 1)
		{
			PlayerConversation = "���� �ջ�� ���³׿�.";
			PlayerBalloonXSize = 210.0f;
		}
		else if (_Index == 2)
		{
			PlayerConversation = "���ϰ� �ջ�Ƴ׿�.";
			PlayerBalloonXSize = 210.0f;
		}
		else if (_Index == 3)
		{
			PlayerConversation = "����ġ�� ���³׿�.";
			PlayerBalloonXSize = 210.0f;
		}
		else if (_Index == 4)
		{
			PlayerConversation = "������ �ջ��� ���� ������ �̰� ������ �����⿹��.";
			PlayerBalloonXSize = 420.0f;
		}
		break;
	case ECardType::TEXTURE:
		if (_Index == 0)
		{
			PlayerConversation = "�˷�̴� �ձ� ����׿�.";
			PlayerBalloonXSize = 260.0f;
		}
		else if (_Index == 1)
		{
			PlayerConversation = "�����ý�ƿ�̳׿�.";
			PlayerBalloonXSize = 210.0f;
		}
		else if (_Index == 2)
		{
			PlayerConversation = "�÷�Ƽ�� ����׿�.";
			PlayerBalloonXSize = 210.0f;
		}
		else if (_Index == 3)
		{
			PlayerConversation = "�����η�����ƿ ����׿�.";
			PlayerBalloonXSize = 260.0f;
		}
		else if (_Index == 4)
		{
			PlayerConversation = "ź�Ҽ����׿�.";
			PlayerBalloonXSize = 210.0f;
		}
		else if (_Index == 5)
		{
			PlayerConversation = "14k ���ΰ��׿�.";
			PlayerBalloonXSize = 220.0f;
		}
		else if (_Index == 6)
		{
			PlayerConversation = "18k ȭ��Ʈ���׿�.";
			PlayerBalloonXSize = 210.0f;
		}
		else if (_Index == 7)
		{
			PlayerConversation = "���̳׿�.";
			PlayerBalloonXSize = 140.0f;
		}
		else if (_Index == 8)
		{
			PlayerConversation = "�Ұ����̳׿�.";
			PlayerBalloonXSize = 130.0f;
		}
		else if (_Index == 9)
		{
			PlayerConversation = "���� ����׿�.";
			PlayerBalloonXSize = 180.0f;
		}
		else if (_Index == 10)
		{
			PlayerConversation = "24K ��� ����׿�.";
			PlayerBalloonXSize = 210.0f;
		}
		else if (_Index == 11)
		{
			PlayerConversation = "���̳׿�.";
			PlayerBalloonXSize = 140.0f;
		}
		else if (_Index == 12)
		{
			PlayerConversation = "ĵ���� ����׿�.";
			PlayerBalloonXSize = 200.0f;
		}
		else if (_Index == 13)
		{
			PlayerConversation = "�����׿�.";
			PlayerBalloonXSize = 140.0f;
		}
		else if (_Index == 14)
		{
			PlayerConversation = "�ö�ƽ�̳׿�.";
			PlayerBalloonXSize = 200.0f;
		}
		else if (_Index == 15)
		{
			PlayerConversation = "���̽���Ż ����׿�.";
			PlayerBalloonXSize = 210.0f;
		}
		else if (_Index == 16)
		{
			PlayerConversation = "PVC�׿�.";
			PlayerBalloonXSize = 140.0f;
		}
		else if (_Index == 17)
		{
			PlayerConversation = "�Ǹ��� ����׿�.";
			PlayerBalloonXSize = 210.0f;
		}
		else if (_Index == 18)
		{
			PlayerConversation = "���������̳׿�.";
			PlayerBalloonXSize = 200.0f;
		}
		else if (_Index == 19)
		{
			PlayerConversation = "�� ����׿�.";
			PlayerBalloonXSize = 140.0f;
		}
		else if (_Index == 20)
		{
			PlayerConversation = "���̳׿�.";
			PlayerBalloonXSize = 140.0f;
		}
		else if (_Index == 21)
		{
			PlayerConversation = "����׿�.";
			PlayerBalloonXSize = 140.0f;
		}
		else if (_Index == 22)
		{
			PlayerConversation = "���� ����׿�.";
			PlayerBalloonXSize = 200.0f;
		}
		else if (_Index == 23)
		{
			PlayerConversation = "�ж��̳׿�.";
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
		PlayerConversation = std::to_string(_Price) + "V �帱�Կ�.";
		PlayerBalloonXSize = 170.0f;
		break;
	case 1:
		PlayerConversation = std::to_string(_Price) + "V���� ���ڱ���.";
		PlayerBalloonXSize = 190.0f;
		break;
	case 2:
		PlayerConversation = std::to_string(_Price) + "V�� �� �� ��������.";
		PlayerBalloonXSize = 200.0f;
		break;
	case 3:
		PlayerConversation = std::to_string(_Price) + "V �����?";
		PlayerBalloonXSize = 200.0f;
		break;
	case 4:
		PlayerConversation = std::to_string(_Price) + "V�� ��������?";
		PlayerBalloonXSize = 200.0f;
		break;
	case 5:
		PlayerConversation = std::to_string(_Price) + "V�� �ּ��̳׿�.";
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
		PlayerConversation = "�� ��� �� ���� �� ���׿�.";
		PlayerBalloonXSize = 200.0f;
		break;
	case 1:
		PlayerConversation = "�׳� �� ��Կ�.";
		PlayerBalloonXSize = 200.0f;
		break;
	case 2:
		PlayerConversation = "�˼�������, ���⼭ �׸� �ѰԿ�.";
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
		CustomerConversation = std::to_string(_Price) + "V�� ���� �����׿�!";
		CustomerBalloonXSize = 400.0f;
		CustomerBalloonYSize = 100.0f;
		break;
	case 1:
		CustomerConversation = "���� ������ �ʿ䰡 ����! ���ƿ�.";
		CustomerBalloonXSize = 400.0f;
		CustomerBalloonYSize = 100.0f;
		break;
	case 2:
		CustomerConversation = "���� ����!";
		CustomerBalloonXSize = 400.0f;
		CustomerBalloonYSize = 100.0f;
		break;
	case 3:
		CustomerConversation = std::to_string(_Price) + "V�� ���� �����ϰھ��?";
		CustomerBalloonXSize = 400.0f;
		CustomerBalloonYSize = 100.0f;
		break;
	case 4:
		CustomerConversation = std::to_string(_Price) + "V���. �������� �ν��� ���Ͻó׿�.";
		CustomerBalloonXSize = 400.0f;
		CustomerBalloonYSize = 100.0f;
		break;
	case 5:
		CustomerConversation = std::to_string(_Price) + "V! �ƽ�!";
		CustomerBalloonXSize = 400.0f;
		CustomerBalloonYSize = 100.0f;
		break;
	case 6:
		CustomerConversation = std::to_string(_Price) + "V�� ��뵵 �� �ߴµ�!";
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
				CustomerConversation = "���� �� ���� �� �ִٴ� ��ⱺ��!";
				CustomerBalloonXSize = 400.0f;
				CustomerBalloonYSize = 100.0f;

				break;
			case 1:
				CustomerConversation = "���� ���� �����ϰ� �־�������. ��Ǵ�� \n�˷��༭ ������!";
				CustomerBalloonXSize = 400.0f;
				CustomerBalloonYSize = 120.0f;

				break;
			case 2:
				CustomerConversation = "��� ������ �� �˾Ҿ��.";
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
				CustomerConversation = "�� ������ �׳� �Ѿ ���� �ѵ�... �˾Ҿ��.";
				CustomerBalloonXSize = 400.0f;
				CustomerBalloonYSize = 100.0f;

				break;
			case 1:
				CustomerConversation = "��, ���� Ʋ�ȳ� ���׿�.";
				CustomerBalloonXSize = 250.0f;
				CustomerBalloonYSize = 100.0f;

				break;
			case 2:
				CustomerConversation = "����Ͻó׿�. �˰ھ��.";
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
				CustomerConversation = "��¾�� ���� �䰡�ΰ��߾��.";
				CustomerBalloonXSize = 400.0f;
				CustomerBalloonYSize = 100.0f;

				break;
			case 1:
				CustomerConversation = "���� ���� �����ϰ� �־�������. ��Ǵ��\n�˷��༭ ������!";
				CustomerBalloonXSize = 400.0f;
				CustomerBalloonYSize = 120.0f;

				break;
			case 2:
				CustomerConversation = "���� �Ǽ��߳� ����.";
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
				CustomerConversation = "��¾�� ������ �� �����ϱ� �ߴµ�... �˰ھ��.";
				CustomerBalloonXSize = 420.0f;
				CustomerBalloonYSize = 100.0f;

				break;
			case 1:
				CustomerConversation = "��, ���� Ʋ�ȳ� ���׿�.";
				CustomerBalloonXSize = 250.0f;
				CustomerBalloonYSize = 100.0f;

				break;
			case 2:
				CustomerConversation = "��, �� �������� �ƴ��ݾƿ�.";
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
