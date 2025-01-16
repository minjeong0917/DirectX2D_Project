#pragma once

// Ό³Έν :
class ACardSlot : public AActor
{
public:
	// constrcuter destructer
	ACardSlot();
	~ACardSlot();

	// delete Function
	ACardSlot(const ACardSlot& _Other) = delete;
	ACardSlot(ACardSlot&& _Other) noexcept = delete;
	ACardSlot& operator=(const ACardSlot& _Other) = delete;
	ACardSlot& operator=(ACardSlot&& _Other) noexcept = delete;

	bool IsActive = false;

protected:
	void Tick(float _DeltaTime);

private:
	std::shared_ptr<class USpriteRenderer> CardSlotRender;
	std::vector<std::shared_ptr<class USpriteRenderer>> AllCardSlotRender;
	std::shared_ptr<class USpriteRenderer> CardSlotInfoRender;

};

