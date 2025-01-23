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
	void Tick(float _DeltaTime);

	void OnCollisionStay(class UCollision* _This, class UCollision* _Other);
	void OnCollisionEnd(class UCollision* _This, class UCollision* _Other);
private:
	int IsClick = 0;

	std::vector<std::shared_ptr<class ASlot>>AllSlots;

	std::shared_ptr<class USpriteRenderer>InvenRender;
	std::shared_ptr<class UCollision> InvenButtonCollision;
};

