#pragma once


struct SlotInfo
{
	std::vector<std::shared_ptr<class ACard>> Cards;
	std::string MerchandiseName = "NONE";
	std::string SpriteName = "NONE";
	int TotalCardCount = 0;
	int SpriteIndex = 0;
	int CardPrice = 0;
	int BuyPrice = 0;
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

	void SetSlotInfo(int _SlotNum, std::string _MerchandiseName, std::vector<std::shared_ptr<class ACard>> Cards, int _TotalCardCount, std::string _SpriteName, int _SpriteIndex, int _BuyPrice, int _CardPrice);

	std::vector<struct SlotInfo> GetAllSlotInfos()
	{
		return AllSlotInfos;
	}

protected:

private:
	InvenInfo();
	std::vector<struct SlotInfo> AllSlotInfos;

};

