#pragma once
#include <EngineCore/Actor.h>
#include <random>
// Ό³Έν :
class AShopGameMode : public AActor
{
public:
	// constrcuter destructer
	AShopGameMode();
	~AShopGameMode();

	// delete Function
	AShopGameMode(const AShopGameMode& _Other) = delete;
	AShopGameMode(AShopGameMode&& _Other) noexcept = delete;
	AShopGameMode& operator=(const AShopGameMode& _Other) = delete;
	AShopGameMode& operator=(AShopGameMode&& _Other) noexcept = delete;

	int RandomInt(int _Min, int _Max)
	{
		std::uniform_int_distribution<int> RandomCreate(_Min, _Max);
		return RandomCreate.operator()(MtGen);
	}

	float Randomfloat(float _Min, float _Max)
	{
		std::uniform_real_distribution<float> RandomCreate(_Min, _Max);
		return RandomCreate.operator()(MtGen);
	}

protected:
	void BeginPlay();
	void Tick(float _DeltaTime);
private:
	void CustomerMove(float _DeltaTime, std::shared_ptr<class AUI> _Customer, bool _IsRight);
	void CustomerCreateAni(std::shared_ptr<class AUI> _Customer);
	void RandomCustomerAnimation(std::shared_ptr<class AUI> _Customer);


	bool IsChange = false;

	std::mt19937_64 MtGen = std::mt19937_64(time(nullptr));
	std::vector<std::string> AllOutCustormerAni;

	std::shared_ptr<class AUI> WalkCustomer1;
	std::shared_ptr<class AUI> WalkCustomer2;
};

