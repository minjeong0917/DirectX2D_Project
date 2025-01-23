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

        AllCardType[0].CardName = "가방";
        AllCardType[0].CardExplanation = "있으면 불편하고 없으면 허전하다.";
        AllCardType[0].CardPercentText = "20V";
        AllCardType[0].CardPercent = 20;
        AllCardType[0].CardNameTextSize = NameTextSize;

        break;

    case ECardType::CONDITION:

        AllCardType.resize(5);

        AllCardType[0].CardName = "완벽한 상태";
        AllCardType[0].CardExplanation = "가격을 10% 올립니다";
        AllCardType[0].CardPercentText = "10%";
        AllCardType[0].CardPercent = 10;
        AllCardType[0].CardNameTextSize = NameTextSize;

        AllCardType[1].CardName = "조금 손상";
        AllCardType[1].CardExplanation = "가격을 20% 내립니다";
        AllCardType[1].CardPercentText = "-20%";
        AllCardType[1].CardPercent = -20;
        AllCardType[1].CardNameTextSize = NameTextSize;

        AllCardType[2].CardName = "심한 손상";
        AllCardType[2].CardExplanation = "가격을 60% 내립니다";
        AllCardType[2].CardPercentText = "-60%";
        AllCardType[2].CardPercent = -60;
        AllCardType[2].CardNameTextSize = NameTextSize;

        AllCardType[3].CardName = "가치 상실";
        AllCardType[3].CardExplanation = "가격을 90% 내립니다";
        AllCardType[3].CardPercentText = "-90%";
        AllCardType[3].CardPercent = -90;
        AllCardType[3].CardNameTextSize = NameTextSize;

        AllCardType[4].CardName = "잠재적 쓰레기";
        AllCardType[4].CardExplanation = "심한손상 혹은 무가치한 \n 물건에는 무효. 2일 뒤 \n '무가치'로 악화.";
        AllCardType[4].CardPercentText = "-25%";
        AllCardType[4].CardPercent = -25;
        AllCardType[4].CardNameTextSize = NameTextSize;
        break;

    case ECardType::TEXTURE:
        AllCardType.resize(24);

        AllCardType[0].CardName = "알루미늄 합금";
        AllCardType[0].CardExplanation = "재활용 가능: 수거 대상이 \n 되면 가격이 오릅니다";
        AllCardType[0].CardPercentText = "+30V";
        AllCardType[0].CardPercent = 30;
        AllCardType[0].CardNameTextSize = NameTextSize;

        AllCardType[1].CardName = "써지컬스틸 소재";
        AllCardType[1].CardExplanation = "재활용 가능: 수거 대상이 \n 되면 가격이 오릅니다";
        AllCardType[1].CardPercentText = "+50V";
        AllCardType[1].CardPercent = 50;
        AllCardType[1].CardNameTextSize = NameTextSize;

        AllCardType[2].CardName = "플래티늄 소재";
        AllCardType[2].CardExplanation = "일반적인 금속제품보다 \n 200V 비싸집니다";
        AllCardType[2].CardPercentText = "+200V";
        AllCardType[2].CardPercent = 200;
        AllCardType[2].CardNameTextSize = NameTextSize;

        AllCardType[3].CardName = "스테인레스스틸 소재";
        AllCardType[3].CardExplanation = "재활용 가능: 수거 대상이 \n 되면 가격이 오릅니다";
        AllCardType[3].CardPercentText = "+50V";
        AllCardType[3].CardPercent = 50;
        AllCardType[3].CardNameTextSize = 20.0f;

        AllCardType[4].CardName = "탄소섬유 소재";
        AllCardType[4].CardExplanation = "굳이 식별할 필요가 없는 금속 \n 중 하나";
        AllCardType[4].CardPercentText = "+20V";
        AllCardType[4].CardPercent = 20;
        AllCardType[4].CardNameTextSize = NameTextSize;

        AllCardType[5].CardName = "14k 옐로골드 소재";
        AllCardType[5].CardExplanation = "순도 58% 금 ";
        AllCardType[5].CardPercentText = "+200V";
        AllCardType[5].CardPercent = 200;
        AllCardType[5].CardNameTextSize = 20.0f;

        AllCardType[6].CardName = "18k 화이트골드 소재";
        AllCardType[6].CardExplanation = "순도 75% 금";
        AllCardType[6].CardPercentText = "+350V";
        AllCardType[6].CardPercent = 350;
        AllCardType[6].CardNameTextSize = 20.0f;

        AllCardType[7].CardName = "은 소재";
        AllCardType[7].CardExplanation = "재활용 가능: 수거 대상이 \n 되면 가격이 오릅니다";
        AllCardType[7].CardPercentText = "+75V";
        AllCardType[7].CardPercent = 75;
        AllCardType[7].CardNameTextSize = NameTextSize;

        AllCardType[8].CardName = "소가죽 소재";
        AllCardType[8].CardExplanation = "동물 희생의 잔재";
        AllCardType[8].CardPercentText = "+50V";
        AllCardType[8].CardPercent = 50;
        AllCardType[8].CardNameTextSize = NameTextSize;

        AllCardType[9].CardName = "벨벳 소재";
        AllCardType[9].CardExplanation = "부드로운 촉감";
        AllCardType[9].CardPercentText = "+65V";
        AllCardType[9].CardPercent = 65;
        AllCardType[9].CardNameTextSize = NameTextSize;

        AllCardType[10].CardName = "24K 골드 소재";
        AllCardType[10].CardExplanation = "순도 100% 금";
        AllCardType[10].CardPercentText = "+500V";
        AllCardType[10].CardPercent = 500;
        AllCardType[10].CardNameTextSize = NameTextSize;

        AllCardType[11].CardName = "종이 소재";
        AllCardType[11].CardExplanation = "재활용 가능: 수거 대상이 \n 되면 가격이 오릅니다";
        AllCardType[11].CardPercentText = "+5V";
        AllCardType[11].CardPercent = 5;
        AllCardType[11].CardNameTextSize = NameTextSize;

        AllCardType[12].CardName = "캔버스 소재";
        AllCardType[12].CardExplanation = "가격에 영향 없음";
        AllCardType[12].CardPercentText = "+0V";
        AllCardType[12].CardPercent = 0;
        AllCardType[12].CardNameTextSize = NameTextSize;

        AllCardType[13].CardName = "유리 소재";
        AllCardType[13].CardExplanation = "재활용 가능: 수거 대상이 \n 되면 가격이 오릅니다";
        AllCardType[13].CardPercentText = "+5V";
        AllCardType[13].CardPercent = 5;
        AllCardType[13].CardNameTextSize = NameTextSize;

        AllCardType[14].CardName = "플라스틱 소재";
        AllCardType[14].CardExplanation = "재활용 가능: 수거 대상이 \n 되면 가격이 오릅니다";
        AllCardType[14].CardPercentText = "+5V";
        AllCardType[14].CardPercent = 5;
        AllCardType[14].CardNameTextSize = NameTextSize;

        AllCardType[15].CardName = "베이스메탈 소재";
        AllCardType[15].CardExplanation = "재활용 가능: 수거 대상이 \n 되면 가격이 오릅니다";
        AllCardType[15].CardPercentText = "+0V";
        AllCardType[15].CardPercent = 0;
        AllCardType[15].CardNameTextSize = NameTextSize;

        AllCardType[16].CardName = "PVC 소재";
        AllCardType[16].CardExplanation = "가격에 영향 없음";
        AllCardType[16].CardPercentText = "+0V";
        AllCardType[16].CardPercent = 0;
        AllCardType[16].CardNameTextSize = NameTextSize;

        AllCardType[17].CardName = "실리콘 소재";
        AllCardType[17].CardExplanation = "가격에 영향 없음";
        AllCardType[17].CardPercentText = "+0V";
        AllCardType[17].CardPercent = 0;
        AllCardType[17].CardNameTextSize = NameTextSize;

        AllCardType[18].CardName = "인조가죽 소재";
        AllCardType[18].CardExplanation = "가격에 영향 없음";
        AllCardType[18].CardPercentText = "+0V";
        AllCardType[18].CardPercent = 0;
        AllCardType[18].CardNameTextSize = NameTextSize;

        AllCardType[19].CardName = "면 소재";
        AllCardType[19].CardExplanation = "가격에 영향 없음";
        AllCardType[19].CardPercentText = "+0V";
        AllCardType[19].CardPercent = 0;
        AllCardType[19].CardNameTextSize = NameTextSize;

        AllCardType[20].CardName = "돌 소재";
        AllCardType[20].CardExplanation = "가격에 영향 없음";
        AllCardType[20].CardPercentText = "+0V";
        AllCardType[20].CardPercent = 0;
        AllCardType[20].CardNameTextSize = NameTextSize;

        AllCardType[21].CardName = "나무 소재";
        AllCardType[21].CardExplanation = "가격에 영향 없음";
        AllCardType[21].CardPercentText = "+0V";
        AllCardType[21].CardPercent = 0;
        AllCardType[21].CardNameTextSize = NameTextSize;

        AllCardType[22].CardName = "점토 소재";
        AllCardType[22].CardExplanation = "가격에 영향 없음";
        AllCardType[22].CardPercentText = "+0V";
        AllCardType[22].CardPercent = 0;
        AllCardType[22].CardNameTextSize = NameTextSize;

        AllCardType[23].CardName = "밀랍";
        AllCardType[23].CardExplanation = "가격에 영향 없음";
        AllCardType[23].CardPercentText = "+0V";
        AllCardType[23].CardPercent = 0;
        AllCardType[23].CardNameTextSize = NameTextSize;
        break;

    default:
        break;
    }
}
