#include "PreCompile.h"

#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/Collision.h>

#include "Merchandise.h"
#include "MerchandiseInfo.h"
#include "CardInfo.h"

AMerchandise::AMerchandise()
{
    std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
    RootComponent = Default;

    MerchandiseRender = CreateDefaultSubObject<USpriteRenderer>();
    MerchandiseRender->SetSprite("Bag", 0);
    MerchandiseRender->SetAutoScaleRatio(3.0f);
    MerchandiseRender->SetWorldLocation({ 0.0f, -260.0f, -150.0f });
    MerchandiseRender->SetupAttachment(RootComponent);

    MerchandiseCollision = CreateDefaultSubObject<UCollision>();
    MerchandiseCollision->SetCollisionProfileName("Merchandise");
    MerchandiseCollision->SetScale3D({ 1.0f,0.8f,0.0f });
    MerchandiseCollision->SetRelativeLocation({ 0.0f, 0.5f,0.0f });
    MerchandiseCollision->SetupAttachment(MerchandiseRender);

    MerchandiseCollision->SetCollisionEnter([this](UCollision* _This, UCollision* _Other)
        {
            this->OnCollisionEnter(_This, _Other);
        });
    MerchandiseCollision->SetCollisionEnd([this](UCollision* _This, UCollision* _Other)
        {
            this->OnCollisionEnd(_This, _Other);

        });

}

AMerchandise::~AMerchandise()
{
}

void AMerchandise::BeginPlay()
{
    AActor::BeginPlay();

    MerchandiseRender->ColorData.PlusColor.W -= 1.0f;
}

void AMerchandise::SetSprite(std::string _Sprite, int _Index)
{
    MerchandiseRender->SetSprite(_Sprite, _Index);
}

void AMerchandise::Tick(float _DeltaTime)
{
    AActor::Tick(_DeltaTime);

    if (IsApear == true && MerchandiseRender->ColorData.PlusColor.W <= 0.0f)
    {
        PlusAlpha(_DeltaTime);
    }
    else
    {
        Acc = 1.0f;
    }
    if (IsApear == false && MerchandiseRender->ColorData.PlusColor.W >= -1.0f)
    {
        PlusAlpha(_DeltaTime * (-1.0f));
    }

}


std::string AMerchandise::GetSpriteName()
{
    return MerchandiseRender->GetCurSpriteName();
}

int AMerchandise::GetSpriteIndex()
{
    return MerchandiseRender->GetCurIndex();
}

void AMerchandise::PlusAlpha(float _DeltaTime)
{
    Acc += 0.01f;
    MerchandiseRender->ColorData.PlusColor.W += _DeltaTime * Speed * Acc;
}

float AMerchandise::GetRealPrice()
{
    // 물건 종류 카드 정보
    CardInfo::GetInst().CardTypeInfo(ECardType::BASIC);


    int CardNum = MerchandiseInfo::GetInst().GetAllBasicCard()[0].CardNameNum;

    int BasicPrice = CardInfo::GetInst().GetAllCardType()[CardNum].CardPercent;
    RealPrice = BasicPrice;
    

    float StatusPercent = CheckRealStatusPrice();
    float TexturePrecet = CheckRealTexturePercent();

    RealPrice = static_cast<int>((RealPrice + TexturePrecet) * StatusPercent);
    UEngineDebug::OutPutString("Real Price : " + std::to_string(RealPrice));

    return RealPrice;
}

float AMerchandise::CheckRealStatusPrice()
{

    // 상태 부분 카드 정보
    CardInfo::GetInst().CardTypeInfo(ECardType::CONDITION);

    int StatusIndex = 0;

    int StatusLevel = MerchandiseInfo::GetInst().GetStatusLevel();

    if (StatusLevel > PerfectStatus)
    {
        // 완벽한 상태
        StatusIndex = 0;
    }
    else if (StatusLevel <= PerfectStatus && StatusLevel > LittleDamageStatus)
    {
        // 조금 손상
        StatusIndex = 1;
    }
    else if (StatusLevel <= LittleDamageStatus && StatusLevel > DamageStatus)
    {
        // 심한 손상
        StatusIndex = 2;
    }
    else if (StatusLevel <= DamageStatus && StatusLevel > LossValueStatus)
    {
        // 가치 상실
        StatusIndex = 3;
    }
    else if (StatusLevel <= LossValueStatus)
    {
        // 잠재적 쓰레기
        StatusIndex = 4;
    }


    int Percentage = CardInfo::GetInst().GetAllCardType()[StatusIndex].CardPercent;

    float ConditionPercent = (100 + Percentage) / 100.0f;

    return ConditionPercent;
}


float AMerchandise::CheckRealTexturePercent()
{
   
    CardInfo::GetInst().CardTypeInfo(ECardType::TEXTURE);

    int TextureIndex = MerchandiseInfo::GetInst().GetTexture();

    int Percentage = CardInfo::GetInst().GetAllCardType()[TextureIndex].CardPercent;

    return Percentage;
}

void AMerchandise::OnCollisionEnter(UCollision* _This, UCollision* _Other)
{
    IsEnter = true;
}

void AMerchandise::OnCollisionEnd(UCollision* _This, UCollision* _Other)
{
    IsEnter = false;
}

