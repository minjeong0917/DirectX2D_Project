#pragma once

// Ό³Έν :
class AInventory : public AActor
{
public:
	// constrcuter destructer
	AInventory();
	~AInventory();

	// delete Function
	AInventory(const AInventory& _Other) = delete;
	AInventory(AInventory&& _Other) noexcept = delete;
	AInventory& operator=(const AInventory& _Other) = delete;
	AInventory& operator=(AInventory&& _Other) noexcept = delete;


protected:
	void BeginPlay();
	void Tick(float _DeltaTime);

	void OnCollisionStay(class UCollision* _This, class UCollision* _Other);
	void OnCollisionEnd(class UCollision* _This, class UCollision* _Other);

private:
	void ChangeLocation(float _DeltaTime);

	int IsClick = 0;
	int CurClickIndex = 0;
	std::vector<std::shared_ptr<class ASlot>> AllSlots;

	std::shared_ptr<class USpriteRenderer>InvenRender;
	std::shared_ptr<class USpriteRenderer>InvenSlotRender;
	std::vector<std::shared_ptr<class USpriteRenderer>> AllInvenSlotRender;

	std::shared_ptr<class UFontRenderer> MerchandiseNameText;
	std::shared_ptr<class UCollision> InvenButtonCollision;

	std::shared_ptr<class ACard> MerchandiseCard;
	std::vector<std::shared_ptr<class ACard>> AllMerchandiseCard;
	std::vector<FVector> AllMerchandiseCardLocations;
};

