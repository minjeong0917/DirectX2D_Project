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
        SpriteName = "Bag";
        SpriteScale = { 0.6f,0.6f,1.0f };
        if (_Index == 0)
        {
            AllBasicCard.resize(3);

            AllBasicCard[0].CardType = ECardType::BASIC;
            AllBasicCard[0].CardColor = ECardColor::Gray;
            AllBasicCard[0].CardNameNum = 0;

            AllBasicCard[1].CardType = ECardType::TEXTURE;
            AllBasicCard[1].CardColor = ECardColor::Green;
            AllBasicCard[1].CardNameNum = 0;

            AllBasicCard[2].CardType = ECardType::CONDITION;
            AllBasicCard[2].CardColor = ECardColor::Blue;
            AllBasicCard[2].CardNameNum = 0; // �Ϻ��� ����


            StatusLevel = 36.0f;
            Texture = 12;
            MerchandiseName = "�ƺ��� �� ����";
        }
        if (_Index == 1)
        {
            AllBasicCard.resize(3);

            AllBasicCard[0].CardType = ECardType::BASIC;
            AllBasicCard[0].CardColor = ECardColor::Gray;
            AllBasicCard[0].CardNameNum = 0;

            AllBasicCard[1].CardType = ECardType::TEXTURE;
            AllBasicCard[1].CardColor = ECardColor::Green;
            AllBasicCard[1].CardNameNum = 9;

            AllBasicCard[2].CardType = ECardType::CONDITION;
            AllBasicCard[2].CardColor = ECardColor::Blue;
            AllBasicCard[2].CardNameNum = 0; // �Ϻ��� ����


            StatusLevel = 24.0f;
            Texture = 9;
            MerchandiseName = "������ �� ����";

        }
        if (_Index == 2)
        {
            AllBasicCard.resize(3);

            AllBasicCard[0].CardType = ECardType::BASIC;
            AllBasicCard[0].CardColor = ECardColor::Gray;
            AllBasicCard[0].CardNameNum = 0;

            AllBasicCard[1].CardType = ECardType::TEXTURE;
            AllBasicCard[1].CardColor = ECardColor::Green;
            AllBasicCard[1].CardNameNum = 9;

            AllBasicCard[2].CardType = ECardType::CONDITION;
            AllBasicCard[2].CardColor = ECardColor::Blue;
            AllBasicCard[2].CardNameNum = 0; // �Ϻ��� ����


            StatusLevel = 24.0f;
            Texture = 9;
            MerchandiseName = "������ �� ����";

        }
        if (_Index == 3)
        {
            AllBasicCard.resize(3);

            AllBasicCard[0].CardType = ECardType::BASIC;
            AllBasicCard[0].CardColor = ECardColor::Gray;
            AllBasicCard[0].CardNameNum = 0;

            AllBasicCard[1].CardType = ECardType::TEXTURE;
            AllBasicCard[1].CardColor = ECardColor::Green;
            AllBasicCard[1].CardNameNum = 9;

            AllBasicCard[2].CardType = ECardType::CONDITION;
            AllBasicCard[2].CardColor = ECardColor::Blue;
            AllBasicCard[2].CardNameNum = 0; // �Ϻ��� ����


            StatusLevel = 24.0f;
            Texture = 9;
            MerchandiseName = "������ �� ����";

        }
        if (_Index == 4)
        {
            AllBasicCard.resize(3);

            AllBasicCard[0].CardType = ECardType::BASIC;
            AllBasicCard[0].CardColor = ECardColor::Gray;
            AllBasicCard[0].CardNameNum = 0;

            AllBasicCard[1].CardType = ECardType::TEXTURE;
            AllBasicCard[1].CardColor = ECardColor::Green;
            AllBasicCard[1].CardNameNum = 9;

            AllBasicCard[2].CardType = ECardType::CONDITION;
            AllBasicCard[2].CardColor = ECardColor::Blue;
            AllBasicCard[2].CardNameNum = 0; // �Ϻ��� ����


            StatusLevel = -1.0f;
            Texture = 9;
            MerchandiseName = "������ �� ����";

        }
        if (_Index == 5)
        {
            AllBasicCard.resize(3);

            AllBasicCard[0].CardType = ECardType::BASIC;
            AllBasicCard[0].CardColor = ECardColor::Gray;
            AllBasicCard[0].CardNameNum = 0;

            AllBasicCard[1].CardType = ECardType::TEXTURE;
            AllBasicCard[1].CardColor = ECardColor::Green;
            AllBasicCard[1].CardNameNum = 9;

            AllBasicCard[2].CardType = ECardType::CONDITION;
            AllBasicCard[2].CardColor = ECardColor::Blue;
            AllBasicCard[2].CardNameNum = 0; // �Ϻ��� ����

            StatusLevel = 24.0f;
            Texture = 9;
            MerchandiseName = "������ �� ����";

        }
        break;
    case EMerchandiseType::UMBRELLA:
        SpriteName = "Umbrella";
        SpriteScale = { 0.6f,0.3f,1.0f };

        if (_Index == 0)
        {
            AllBasicCard.resize(3);

            AllBasicCard[0].CardType = ECardType::BASIC;
            AllBasicCard[0].CardColor = ECardColor::Gray;
            AllBasicCard[0].CardNameNum = 1;

            AllBasicCard[1].CardType = ECardType::TEXTURE;
            AllBasicCard[1].CardColor = ECardColor::Green;
            AllBasicCard[1].CardNameNum = 0;

            AllBasicCard[2].CardType = ECardType::CONDITION;
            AllBasicCard[2].CardColor = ECardColor::Blue;
            AllBasicCard[2].CardNameNum = 0; // �Ϻ��� ����


            StatusLevel = 36.0f;
            Texture = 12;
            MerchandiseName = "�ƺ��� �� ���";
        }
        if (_Index == 1)
        {
            AllBasicCard.resize(3);

            AllBasicCard[0].CardType = ECardType::BASIC;
            AllBasicCard[0].CardColor = ECardColor::Gray;
            AllBasicCard[0].CardNameNum = 1;

            AllBasicCard[1].CardType = ECardType::TEXTURE;
            AllBasicCard[1].CardColor = ECardColor::Green;
            AllBasicCard[1].CardNameNum = 9;

            AllBasicCard[2].CardType = ECardType::CONDITION;
            AllBasicCard[2].CardColor = ECardColor::Blue;
            AllBasicCard[2].CardNameNum = 0; // �Ϻ��� ����


            StatusLevel = 24.0f;
            Texture = 9;
            MerchandiseName = "������ �� ���";

        }
        if (_Index == 2)
        {
            AllBasicCard.resize(3);

            AllBasicCard[0].CardType = ECardType::BASIC;
            AllBasicCard[0].CardColor = ECardColor::Gray;
            AllBasicCard[0].CardNameNum = 1;

            AllBasicCard[1].CardType = ECardType::TEXTURE;
            AllBasicCard[1].CardColor = ECardColor::Green;
            AllBasicCard[1].CardNameNum = 9;

            AllBasicCard[2].CardType = ECardType::CONDITION;
            AllBasicCard[2].CardColor = ECardColor::Blue;
            AllBasicCard[2].CardNameNum = 0; // �Ϻ��� ����


            StatusLevel = 24.0f;
            Texture = 9;
            MerchandiseName = "������ �� ���";

        }
        if (_Index == 3)
        {
            AllBasicCard.resize(3);

            AllBasicCard[0].CardType = ECardType::BASIC;
            AllBasicCard[0].CardColor = ECardColor::Gray;
            AllBasicCard[0].CardNameNum = 1;

            AllBasicCard[1].CardType = ECardType::TEXTURE;
            AllBasicCard[1].CardColor = ECardColor::Green;
            AllBasicCard[1].CardNameNum = 9;

            AllBasicCard[2].CardType = ECardType::CONDITION;
            AllBasicCard[2].CardColor = ECardColor::Blue;
            AllBasicCard[2].CardNameNum = 0; // �Ϻ��� ����


            StatusLevel = 24.0f;
            Texture = 9;
            MerchandiseName = "������ �� ���";

        }
        if (_Index == 4)
        {
            AllBasicCard.resize(3);

            AllBasicCard[0].CardType = ECardType::BASIC;
            AllBasicCard[0].CardColor = ECardColor::Gray;
            AllBasicCard[0].CardNameNum = 1;

            AllBasicCard[1].CardType = ECardType::TEXTURE;
            AllBasicCard[1].CardColor = ECardColor::Green;
            AllBasicCard[1].CardNameNum = 9;

            AllBasicCard[2].CardType = ECardType::CONDITION;
            AllBasicCard[2].CardColor = ECardColor::Blue;
            AllBasicCard[2].CardNameNum = 0; // �Ϻ��� ����


            StatusLevel = -1.0f;
            Texture = 9;
            MerchandiseName = "������ �� ���";

        }
        if (_Index == 5)
        {
            AllBasicCard.resize(3);

            AllBasicCard[0].CardType = ECardType::BASIC;
            AllBasicCard[0].CardColor = ECardColor::Gray;
            AllBasicCard[0].CardNameNum = 1;

            AllBasicCard[1].CardType = ECardType::TEXTURE;
            AllBasicCard[1].CardColor = ECardColor::Green;
            AllBasicCard[1].CardNameNum = 9;

            AllBasicCard[2].CardType = ECardType::CONDITION;
            AllBasicCard[2].CardColor = ECardColor::Blue;
            AllBasicCard[2].CardNameNum = 0; // �Ϻ��� ����

            StatusLevel = 24.0f;
            Texture = 9;
            MerchandiseName = "������ �� ���";

        }

        break;
    default:
        break;
    }


}
