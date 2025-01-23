#pragma once


struct SlotInfo
{
	std::vector<std::shared_ptr<class ACard>> Cards;
	std::string MerchandiseName = "NONE";
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

	void SetSlotInfo(int _SlotNum, int _BuyPrice, int _CardPrice);


protected:

private:
	InvenInfo();
	std::vector<struct SlotInfo> AllSlotInfos;

};

