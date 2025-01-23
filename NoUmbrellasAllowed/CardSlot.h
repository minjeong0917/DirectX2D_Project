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


	void SetUpDownText(int _Price);
	void SetUpDownActive(bool _IsActive);


	bool IsActive = false;
	bool IsUpdownActive = false;

	bool GetIsEnter()
	{
		return IsEnter;
	}
	void SetMerchandiseNameText(std::string _Name);
	void SetNameTextActive(bool _IsActive);

protected:
	void Tick(float _DeltaTime);
	void OnCollisionEnter(class UCollision* _This, class UCollision* _Other);
	void OnCollisionEnd(class UCollision* _This, class UCollision* _Other);
private:

	bool IsEnter = false;

	std::shared_ptr<class USpriteRenderer> CardSlotRender;
	std::shared_ptr<class USpriteRenderer> UpDownRender;
	std::shared_ptr<class UFontRenderer> UpDownText;
	std::shared_ptr<class UFontRenderer> MerchandiseNameText;

	std::vector<std::shared_ptr<class USpriteRenderer>> AllCardSlotRender;
	std::shared_ptr<class USpriteRenderer> CardSlotInfoRender;
	std::shared_ptr<class UCollision> CardSlotCollision;

};

