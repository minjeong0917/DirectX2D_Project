#pragma once
#include <EngineCore/Actor.h>
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



protected:
	void BeginPlay();
	void Tick(float _DeltaTime);
private:
	void CustomerMove(float _DeltaTime, std::shared_ptr<class AUI> _Customer, bool _IsRight);
	void CustomerCreateAni(std::shared_ptr<class AUI> _Customer);
	void RandomCustomerAnimation(std::shared_ptr<class AUI> _Customer);
	void CustomerEnter(float _DeltaTime);
	void CustomerOut(float _DeltaTime);
	void DoorOpen(float _DeltaTime);
	void DoorClose(float _DeltaTime);

	int CustomerActive = 0;
	bool IsExistCustomer = false;
	float NotExistCustomerTime = 0.0f;

	float DoorClosedTime = 0.0f;
	float DoorOpenTime = 0.0f;

	float DoorAcc = 1.0f;

	bool IsOut = false;

	float CustomerSpeed = 120;
	std::shared_ptr<class UTimeEventComponent> TimeEventComponent;
	std::vector<std::string> AllOutCustormerAni;

	std::shared_ptr<class AUI> WalkCustomer1;
	std::shared_ptr<class AUI> WalkCustomer2;
	std::shared_ptr<class ACustomer> Customer;

	std::shared_ptr<class ACalculator> Calculator;
	std::shared_ptr<class AUI> DoorUp;
	std::shared_ptr<class AUI> DoorDown;
};

