#pragma once
#include "ContentsEnums.h"

struct MBasicCardInfo
{
	ECardType CardType;
	ECardColor CardColor;
	int CardStep;
	int CardNameNum;
};



// Ό³Έν :
class MerchandiseInfo
{
public:
	// constrcuter destructer
	~MerchandiseInfo();
	static MerchandiseInfo& GetInst()
	{
		static MerchandiseInfo Inst = MerchandiseInfo();
		return Inst;
	}

	// delete Function
	MerchandiseInfo(const MerchandiseInfo& _Other) = delete;
	MerchandiseInfo(MerchandiseInfo&& _Other) noexcept = delete;
	MerchandiseInfo& operator=(const MerchandiseInfo& _Other) = delete;
	MerchandiseInfo& operator=(MerchandiseInfo&& _Other) noexcept = delete;

	void SetMerchandiseInfo(bool _IsFake, EMerchandiseType _MerchandiseType, int _Index);

	std::vector<struct MBasicCardInfo> GetAllBasicCard()
	{
		return AllBasicCard;
	}
	
	void SetCardNameNum(int _th, int _CardNum)
	{
		AllBasicCard[_th].CardNameNum = _CardNum;
	}
	float GetStatusLevel()
	{
		return StatusLevel;
	}

	EMerchandiseType GetMerchandiseType()
	{
		return MerchandiseType;
	}

protected:

private:
	MerchandiseInfo();
	EMerchandiseType MerchandiseType = EMerchandiseType::NONE;
	std::vector<struct MBasicCardInfo> AllBasicCard;
	float StatusLevel = 0.0f;
};

