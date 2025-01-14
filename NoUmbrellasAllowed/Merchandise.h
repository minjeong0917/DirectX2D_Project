#pragma once

// Ό³Έν :
class AMerchandise : public AActor
{
public:
	// constrcuter destructer
	AMerchandise();
	~AMerchandise();

	// delete Function
	AMerchandise(const AMerchandise& _Other) = delete;
	AMerchandise(AMerchandise&& _Other) noexcept = delete;
	AMerchandise& operator=(const AMerchandise& _Other) = delete;
	AMerchandise& operator=(AMerchandise&& _Other) noexcept = delete;
	void PlusAlpha(float _DeltaTime);
	bool GetIsEnter()
	{
		return IsEnter;
	}
	void SetIsApear(bool _IsActive)
	{
		IsApear = _IsActive;
	}
protected:
	void Tick(float _DeltaTime);
	void BeginPlay();

	void OnCollisionEnter(class UCollision* _This, class UCollision* _Other);
	void OnCollisionEnd(class UCollision* _This, class UCollision* _Other);
private:
	bool IsEnter = false;
	bool IsApear = false;
	float Speed = 0.5f;
	float Acc = 1.0f;
	std::shared_ptr<class USpriteRenderer> MerchandiseRender;
	std::shared_ptr<class UCollision> MerchandiseCollision;

};

