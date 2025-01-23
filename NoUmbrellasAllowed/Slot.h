#pragma once

// Ό³Έν :
class ASlot : public AActor
{
public:
	// constrcuter destructer
	ASlot();
	~ASlot();

	// delete Function
	ASlot(const ASlot& _Other) = delete;
	ASlot(ASlot&& _Other) noexcept = delete;
	ASlot& operator=(const ASlot& _Other) = delete;
	ASlot& operator=(ASlot&& _Other) noexcept = delete;
	void SetSlotItemSetting(std::string _SpriteName, int _Index, FVector _Scale);
	void SetItemActive(bool _IsActive);
	void SetSlotSprite(int _Index);

	bool GetIsStay()
	{
		return IsStay;
	}

protected:
	void OnCollisionStay(class UCollision* _This, class UCollision* _Other);
	void OnCollisionEnd(class UCollision* _This, class UCollision* _Other);
private:
	std::shared_ptr<class USpriteRenderer>SlotRender;
	std::shared_ptr<class USpriteRenderer>SlotItemRender;
	std::shared_ptr<class UCollision> SlotCollision;

	bool IsStay = false;


};

