#pragma once
#include "ContentsEnums.h"
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

	void SetMerchandiseInfo();

protected:

private:
	MerchandiseInfo();
	EMerchandiseType MerchandiseType = EMerchandiseType::NONE;
};

