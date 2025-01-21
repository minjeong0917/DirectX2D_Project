#include "PreCompile.h"

#include "CardTotalPrice.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/FontRenderer.h>
#include "MerchandiseInfo.h"
#include "CardInfo.h"
#include "ContentsEnums.h"

ACardTotalPrice::ACardTotalPrice()
{
    std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
    RootComponent = Default;

    CardTotalPrice = CreateDefaultSubObject<UFontRenderer>();
    CardTotalPrice->SetFont("OrangeKid", 52.0f, TColor<unsigned char>(196, 247, 1, 255), FW1_RIGHT);
    CardTotalPrice->SetWorldLocation({ -585.0f,-178.0f,-170.0f });
    CardTotalPrice->SetupAttachment(RootComponent);
}

ACardTotalPrice::~ACardTotalPrice()
{
}

void ACardTotalPrice::BeginPlay()
{
    AActor::BeginPlay();


}
void ACardTotalPrice::Tick(float _DeltaTime)
{
    AActor::Tick(_DeltaTime);
    


}
void ACardTotalPrice::SetPrice(int _Price)
{
    CardTotalPrice->SetText(std::to_string(_Price));
}

int ACardTotalPrice::TotalPriceCheck()
{
    for (size_t i = 0; i < MerchandiseInfo::GetInst().GetAllBasicCard().size(); i++)
    {
        ECardType CardType = MerchandiseInfo::GetInst().GetAllBasicCard()[i].CardType;
 
        CardInfo::GetInst().SetCardType(CardType);
        CardInfo::GetInst().CardTypeInfo();
        int CardNum = MerchandiseInfo::GetInst().GetAllBasicCard()[i].CardNameNum;

        if (CardType == ECardType::BASIC)
        {

            int BasicPrice = CardInfo::GetInst().GetAllCardType()[CardNum].CardPercent;
            TotalPrice = BasicPrice;
        }
        else if (CardType == ECardType::CONDITION)
        {
            int Percentage = CardInfo::GetInst().GetAllCardType()[CardNum].CardPercent;
            TotalPrice *= (100 + Percentage) / 100;
        }
        else if (CardType == ECardType::TEXTURE)
        {
            int PlusPrice = CardInfo::GetInst().GetAllCardType()[CardNum].CardPercent;
            TotalPrice += PlusPrice;
        }

    }

    return TotalPrice;
}
