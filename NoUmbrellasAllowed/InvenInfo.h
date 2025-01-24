#pragma once
#include "ContentsEnums.h"

struct SlotInfo
{
	std::vector<struct SlotCardInfo> Cards;
	std::string MerchandiseName = "NONE";
	std::string SpriteName = "NONE";
	int TotalCardCount = 0;
	int SpriteIndex = 0;
	int CardPrice = 0;
	int BuyPrice = 0;
};

struct SlotCardInfo
{
	ECardColor CardColor = ECardColor::Gray ;
	ECardType CardType = ECardType::NONE;
	int CardStep = 0 ;
	int CardNum = 0;
};

// Ό³Έν :
class InvenInfo
{
public:
	// constrcuter destructer
	~InvenInfo();

	// delete Function
	InvenInfo(const InvenInfo& _Other) = delete;
	InvenInfo(InvenInfo&& _Other) noexcept = delete;
	InvenInfo& operator=(const InvenInfo& _Other) = delete;
	InvenInfo& operator=(InvenInfo&& _Other) noexcept = delete;


	static InvenInfo& GetInst()
	{
		static InvenInfo Inst = InvenInfo();
		return Inst;
	}

	void SetSlotInfo(int _SlotNum, std::string _MerchandiseName, int _TotalCardCount, std::string _SpriteName, int _SpriteIndex, int _BuyPrice, int _CardPrice);
	void SetCardInfo(int _SlotNum, int _CardCount, ECardColor _Color, int CardStep, ECardType _CardType, int CardNum);
	const std::vector<SlotInfo>& GetAllSlotInfos() const
	{
		return AllSlotInfos;
	}

protected:

private:
	InvenInfo();
	std::vector<struct SlotInfo> AllSlotInfos;
	std::vector<struct SlotCardInfo> AllSlotCardInfos;

};

