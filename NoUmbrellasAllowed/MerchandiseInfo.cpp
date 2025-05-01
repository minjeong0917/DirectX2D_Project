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
            AllBasicCard[2].CardNameNum = 0; // 완벽한 상태


            StatusLevel = 36.0f;
            Texture = 12;
            MerchandiseName = "아빠가 준 가방";
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
            AllBasicCard[2].CardNameNum = 0; // 완벽한 상태


            StatusLevel = 24.0f;
            Texture = 9;
            MerchandiseName = "엄마가 준 가방";

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
            AllBasicCard[2].CardNameNum = 1; // 완벽한 상태


            StatusLevel = 24.0f;
            Texture = 9;
            MerchandiseName = "성공의 가방";

        }
        if (_Index == 3)
        {
            AllBasicCard.resize(3);

            AllBasicCard[0].CardType = ECardType::BASIC;
            AllBasicCard[0].CardColor = ECardColor::Gray;
            AllBasicCard[0].CardNameNum = 0;

            AllBasicCard[1].CardType = ECardType::TEXTURE;
            AllBasicCard[1].CardColor = ECardColor::Green;
            AllBasicCard[1].CardNameNum = 3;

            AllBasicCard[2].CardType = ECardType::CONDITION;
            AllBasicCard[2].CardColor = ECardColor::Blue;
            AllBasicCard[2].CardNameNum = 3; // 완벽한 상태


            StatusLevel = 24.0f;
            Texture = 3;
            MerchandiseName = "가방";

        }
        if (_Index == 4)
        {
            AllBasicCard.resize(3);

            AllBasicCard[0].CardType = ECardType::BASIC;
            AllBasicCard[0].CardColor = ECardColor::Gray;
            AllBasicCard[0].CardNameNum = 0;

            AllBasicCard[1].CardType = ECardType::TEXTURE;
            AllBasicCard[1].CardColor = ECardColor::Green;
            AllBasicCard[1].CardNameNum = 19;

            AllBasicCard[2].CardType = ECardType::CONDITION;
            AllBasicCard[2].CardColor = ECardColor::Blue;
            AllBasicCard[2].CardNameNum = 1; // 완벽한 상태


            StatusLevel = -1.0f;
            Texture = 19;
            MerchandiseName = "가방";

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
            AllBasicCard[2].CardNameNum = 0; // 완벽한 상태

            StatusLevel = -24.0f;
            Texture = 9;
            MerchandiseName = "가방";

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
            AllBasicCard[2].CardNameNum = 0; // 완벽한 상태


            StatusLevel = 36.0f;
            Texture = 12;
            MerchandiseName = "하늘색 우산";
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
            AllBasicCard[2].CardNameNum = 0; // 완벽한 상태


            StatusLevel = 24.0f;
            Texture = 1;
            MerchandiseName = "노란색 우산";

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
            AllBasicCard[2].CardNameNum = 0; // 완벽한 상태


            StatusLevel = 12.0f;
            Texture = 11;
            MerchandiseName = "보라색 우산";

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
            AllBasicCard[2].CardNameNum = 0; // 완벽한 상태


            StatusLevel = -2.0f;
            Texture = 18;
            MerchandiseName = "우산";

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
            AllBasicCard[2].CardNameNum = 0; // 완벽한 상태


            StatusLevel = -1.0f;
            Texture = 14;
            MerchandiseName = "엄마가 준 우산";

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
            AllBasicCard[2].CardNameNum = 0; // 완벽한 상태

            StatusLevel = 2.0f;
            Texture = 16;
            MerchandiseName = "초록색 우산";

        }

        break;
    default:
        break;
    }


}
 