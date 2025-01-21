#pragma once

// Ό³Έν :
class ACardTotalPrice : public AActor
{
public:
	// constrcuter destructer
	ACardTotalPrice();
	~ACardTotalPrice();

	// delete Function
	ACardTotalPrice(const ACardTotalPrice& _Other) = delete;
	ACardTotalPrice(ACardTotalPrice&& _Other) noexcept = delete;
	ACardTotalPrice& operator=(const ACardTotalPrice& _Other) = delete;
	ACardTotalPrice& operator=(ACardTotalPrice&& _Other) noexcept = delete;
	void TotalPriceCheck();

protected:
	void BeginPlay();
	void Tick(float _DeltaTime);


private:
	std::shared_ptr<class UFontRenderer> CardTotalPrice;
	int TotalPrice = 0;
	int CurPrice = 0;
};

