#include "PreCompile.h"

#include "CardInfo.h"
#include "BookPageInfo.h"

CardInfo::CardInfo()
{


}

CardInfo::~CardInfo()
{
}

void CardInfo::SetSelectedCardInfo()
{
    if (BookPageInfo::GetInst().GetCurPage() == 7)
    {
        CardType = ECardType::CONDITION;
        CardColor = ECardColor::Blue;
        CardStep = 0;

    }
    else if (BookPageInfo::GetInst().GetCurPage() == 8)
    {
        CardType = ECardType::TEXTURE;
        CardColor = ECardColor::Green;
        CardStep = 0;

    }

    CardTypeInfo(CardType);
}


void CardInfo::CardTypeInfo(ECardType _CardType)
{

    switch (_CardType)
    {
    case ECardType::NONE:
        break;
    case ECardType::BASIC:
        AllCardType.resize(5);

        AllCardType[0].CardName = "����";
        AllCardType[0].CardExplanation = "������ �����ϰ� ������ �����ϴ�.";
        AllCardType[0].CardPercentText = "20V";
        AllCardType[0].CardPercent = 20;
        AllCardType[0].CardNameTextSize = NameTextSize;

        break;

    case ECardType::CONDITION:

        AllCardType.resize(5);

        AllCardType[0].CardName = "�Ϻ��� ����";
        AllCardType[0].CardExplanation = "������ 10% �ø��ϴ�";
        AllCardType[0].CardPercentText = "10%";
        AllCardType[0].CardPercent = 10;
        AllCardType[0].CardNameTextSize = NameTextSize;

        AllCardType[1].CardName = "���� �ջ�";
        AllCardType[1].CardExplanation = "������ 20% �����ϴ�";
        AllCardType[1].CardPercentText = "-20%";
        AllCardType[1].CardPercent = -20;
        AllCardType[1].CardNameTextSize = NameTextSize;

        AllCardType[2].CardName = "���� �ջ�";
        AllCardType[2].CardExplanation = "������ 60% �����ϴ�";
        AllCardType[2].CardPercentText = "-60%";
        AllCardType[2].CardPercent = -60;
        AllCardType[2].CardNameTextSize = NameTextSize;

        AllCardType[3].CardName = "��ġ ���";
        AllCardType[3].CardExplanation = "������ 90% �����ϴ�";
        AllCardType[3].CardPercentText = "-90%";
        AllCardType[3].CardPercent = -90;
        AllCardType[3].CardNameTextSize = NameTextSize;

        AllCardType[4].CardName = "������ ������";
        AllCardType[4].CardExplanation = "���Ѽջ� Ȥ�� ����ġ�� \n ���ǿ��� ��ȿ. 2�� �� \n '����ġ'�� ��ȭ.";
        AllCardType[4].CardPercentText = "-25%";
        AllCardType[4].CardPercent = -25;
        AllCardType[4].CardNameTextSize = NameTextSize;
        break;

    case ECardType::TEXTURE:
        AllCardType.resize(24);

        AllCardType[0].CardName = "�˷�̴� �ձ�";
        AllCardType[0].CardExplanation = "��Ȱ�� ����: ���� ����� \n �Ǹ� ������ �����ϴ�";
        AllCardType[0].CardPercentText = "+30V";
        AllCardType[0].CardPercent = 30;
        AllCardType[0].CardNameTextSize = NameTextSize;

        AllCardType[1].CardName = "�����ý�ƿ ����";
        AllCardType[1].CardExplanation = "��Ȱ�� ����: ���� ����� \n �Ǹ� ������ �����ϴ�";
        AllCardType[1].CardPercentText = "+50V";
        AllCardType[1].CardPercent = 50;
        AllCardType[1].CardNameTextSize = NameTextSize;

        AllCardType[2].CardName = "�÷�Ƽ�� ����";
        AllCardType[2].CardExplanation = "�Ϲ����� �ݼ���ǰ���� \n 200V ������ϴ�";
        AllCardType[2].CardPercentText = "+200V";
        AllCardType[2].CardPercent = 200;
        AllCardType[2].CardNameTextSize = NameTextSize;

        AllCardType[3].CardName = "�����η�����ƿ ����";
        AllCardType[3].CardExplanation = "��Ȱ�� ����: ���� ����� \n �Ǹ� ������ �����ϴ�";
        AllCardType[3].CardPercentText = "+50V";
        AllCardType[3].CardPercent = 50;
        AllCardType[3].CardNameTextSize = 20.0f;

        AllCardType[4].CardName = "ź�Ҽ��� ����";
        AllCardType[4].CardExplanation = "���� �ĺ��� �ʿ䰡 ���� �ݼ� \n �� �ϳ�";
        AllCardType[4].CardPercentText = "+20V";
        AllCardType[4].CardPercent = 20;
        AllCardType[4].CardNameTextSize = NameTextSize;

        AllCardType[5].CardName = "14k ���ΰ�� ����";
        AllCardType[5].CardExplanation = "���� 58% �� ";
        AllCardType[5].CardPercentText = "+200V";
        AllCardType[5].CardPercent = 200;
        AllCardType[5].CardNameTextSize = 20.0f;

        AllCardType[6].CardName = "18k ȭ��Ʈ��� ����";
        AllCardType[6].CardExplanation = "���� 75% ��";
        AllCardType[6].CardPercentText = "+350V";
        AllCardType[6].CardPercent = 350;
        AllCardType[6].CardNameTextSize = 20.0f;

        AllCardType[7].CardName = "�� ����";
        AllCardType[7].CardExplanation = "��Ȱ�� ����: ���� ����� \n �Ǹ� ������ �����ϴ�";
        AllCardType[7].CardPercentText = "+75V";
        AllCardType[7].CardPercent = 75;
        AllCardType[7].CardNameTextSize = NameTextSize;

        AllCardType[8].CardName = "�Ұ��� ����";
        AllCardType[8].CardExplanation = "���� ����� ����";
        AllCardType[8].CardPercentText = "+50V";
        AllCardType[8].CardPercent = 50;
        AllCardType[8].CardNameTextSize = NameTextSize;

        AllCardType[9].CardName = "���� ����";
        AllCardType[9].CardExplanation = "�ε�ο� �˰�";
        AllCardType[9].CardPercentText = "+65V";
        AllCardType[9].CardPercent = 65;
        AllCardType[9].CardNameTextSize = NameTextSize;

        AllCardType[10].CardName = "24K ��� ����";
        AllCardType[10].CardExplanation = "���� 100% ��";
        AllCardType[10].CardPercentText = "+500V";
        AllCardType[10].CardPercent = 500;
        AllCardType[10].CardNameTextSize = NameTextSize;

        AllCardType[11].CardName = "���� ����";
        AllCardType[11].CardExplanation = "��Ȱ�� ����: ���� ����� \n �Ǹ� ������ �����ϴ�";
        AllCardType[11].CardPercentText = "+5V";
        AllCardType[11].CardPercent = 5;
        AllCardType[11].CardNameTextSize = NameTextSize;

        AllCardType[12].CardName = "ĵ���� ����";
        AllCardType[12].CardExplanation = "���ݿ� ���� ����";
        AllCardType[12].CardPercentText = "+0V";
        AllCardType[12].CardPercent = 0;
        AllCardType[12].CardNameTextSize = NameTextSize;

        AllCardType[13].CardName = "���� ����";
        AllCardType[13].CardExplanation = "��Ȱ�� ����: ���� ����� \n �Ǹ� ������ �����ϴ�";
        AllCardType[13].CardPercentText = "+5V";
        AllCardType[13].CardPercent = 5;
        AllCardType[13].CardNameTextSize = NameTextSize;

        AllCardType[14].CardName = "�ö�ƽ ����";
        AllCardType[14].CardExplanation = "��Ȱ�� ����: ���� ����� \n �Ǹ� ������ �����ϴ�";
        AllCardType[14].CardPercentText = "+5V";
        AllCardType[14].CardPercent = 5;
        AllCardType[14].CardNameTextSize = NameTextSize;

        AllCardType[15].CardName = "���̽���Ż ����";
        AllCardType[15].CardExplanation = "��Ȱ�� ����: ���� ����� \n �Ǹ� ������ �����ϴ�";
        AllCardType[15].CardPercentText = "+0V";
        AllCardType[15].CardPercent = 0;
        AllCardType[15].CardNameTextSize = NameTextSize;

        AllCardType[16].CardName = "PVC ����";
        AllCardType[16].CardExplanation = "���ݿ� ���� ����";
        AllCardType[16].CardPercentText = "+0V";
        AllCardType[16].CardPercent = 0;
        AllCardType[16].CardNameTextSize = NameTextSize;

        AllCardType[17].CardName = "�Ǹ��� ����";
        AllCardType[17].CardExplanation = "���ݿ� ���� ����";
        AllCardType[17].CardPercentText = "+0V";
        AllCardType[17].CardPercent = 0;
        AllCardType[17].CardNameTextSize = NameTextSize;

        AllCardType[18].CardName = "�������� ����";
        AllCardType[18].CardExplanation = "���ݿ� ���� ����";
        AllCardType[18].CardPercentText = "+0V";
        AllCardType[18].CardPercent = 0;
        AllCardType[18].CardNameTextSize = NameTextSize;

        AllCardType[19].CardName = "�� ����";
        AllCardType[19].CardExplanation = "���ݿ� ���� ����";
        AllCardType[19].CardPercentText = "+0V";
        AllCardType[19].CardPercent = 0;
        AllCardType[19].CardNameTextSize = NameTextSize;

        AllCardType[20].CardName = "�� ����";
        AllCardType[20].CardExplanation = "���ݿ� ���� ����";
        AllCardType[20].CardPercentText = "+0V";
        AllCardType[20].CardPercent = 0;
        AllCardType[20].CardNameTextSize = NameTextSize;

        AllCardType[21].CardName = "���� ����";
        AllCardType[21].CardExplanation = "���ݿ� ���� ����";
        AllCardType[21].CardPercentText = "+0V";
        AllCardType[21].CardPercent = 0;
        AllCardType[21].CardNameTextSize = NameTextSize;

        AllCardType[22].CardName = "���� ����";
        AllCardType[22].CardExplanation = "���ݿ� ���� ����";
        AllCardType[22].CardPercentText = "+0V";
        AllCardType[22].CardPercent = 0;
        AllCardType[22].CardNameTextSize = NameTextSize;

        AllCardType[23].CardName = "�ж�";
        AllCardType[23].CardExplanation = "���ݿ� ���� ����";
        AllCardType[23].CardPercentText = "+0V";
        AllCardType[23].CardPercent = 0;
        AllCardType[23].CardNameTextSize = NameTextSize;
        break;

    default:
        break;
    }
}
