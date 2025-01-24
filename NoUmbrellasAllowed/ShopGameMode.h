#pragma once

// Ό³Έν :
class AShopGameMode : public AGameMode
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


	bool CursorActive = true;
	bool MerchandiseCheck = false;
protected:
	void BeginPlay();
	void Tick(float _DeltaTime);

private:
	void PeopleMove(float _DeltaTime, std::shared_ptr<class AUI> _Customer, bool _IsRight);
	void PeopleCreateAni(std::shared_ptr<class AUI> _Customer);
	void RandomPeopleAnimation(std::shared_ptr<class AUI> _Customer);
	void CustomerEnter(float _DeltaTime);
	void CustomerOut(float _DeltaTime);
	void DoorOpen(float _DeltaTime);
	void DoorClose(float _DeltaTime);
	void MerchandiseActive(float _DeltaTime);
	void CardCompareAndChange(float _DeltaTime);
	void MerchandiseCardCheck(float _DeltaTime);
	void BuyMerchandise(float _DeltaTime);
	void LoadTotalCardInfo(int _Index);

	float CardChangeTime = 0.0f;
	bool IsCardChange = false;
	int ChangeCardNum = 0;
	bool IsMerchandisActive = false;

	int CurPrice = 0;
	int TotalPrice = 0;
	bool IsCardHover = false;
	int HoverCardNum = 0;
	int IsPriceChange = 0;
	float ChangePriceActiveTime = 0.0f;


	int CustomerActive = 0;

	bool IsExistCustomer = false;

	float NotExistCustomerTime = 0.0f;
	float CustomerEnterTime = 0.0f;

	float DoorClosedTime = 0.0f;
	float DoorOpenTime = 0.0f;

	bool IsDoorDown = false;
	bool IsDoorClosed = true;

	float DoorAcc = 1.0f;
	bool IsOut = false;
	std::shared_ptr<class ACursor> Cursor;

	float CustomerSpeed = 120;
	std::shared_ptr<class UTimeEventComponent> TimeEventComponent;
	std::vector<std::string> AllOutPeopleAni;

	std::shared_ptr<class AUI> WalkCustomer1;
	std::shared_ptr<class AUI> WalkCustomer2;
	std::shared_ptr<class ACustomer> Customer;
	std::shared_ptr<class APlayerBalloon> PlayerBalloon;

	std::shared_ptr<class ACard> Card;
	std::vector<std::shared_ptr<class ACard>> AllCard;
	std::vector<FVector> AllCardLocations;
	int CurCardCount = 0;


	std::shared_ptr<class ACalculator> Calculator;
	std::shared_ptr<class AInventory> Inventory;
	std::shared_ptr<class AItemShelf> ItemShelf;
	std::shared_ptr<class AMerchandise> Merchandise;
	std::shared_ptr<class AMerchandiseMaterial> MerchandiseMaterial;
	std::shared_ptr<class ACardSlot> CardSlot;
	std::shared_ptr<class ACardTotalPrice> CardTotalPrice;

	std::shared_ptr<class ABook> Book;
	std::shared_ptr<class ABookSmall> BookSmall;


	std::shared_ptr<class AButton> NumButton;
	std::shared_ptr<class AUI> DoorUp;
	std::shared_ptr<class AUI> DoorDown;
};

