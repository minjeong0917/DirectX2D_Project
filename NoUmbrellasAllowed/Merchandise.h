#pragma once

// 설명 :
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
	std::string GetSpriteName();
	int GetSpriteIndex();
	void SetSprite(std::string _Sprite, int _Index);
	float GetRealPrice();


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
	int RealPrice = 0;


	float CheckRealStatusPrice();
	float CheckRealTexturePercent();



	// 35이상 -> 완벽 , 31-15 -> 조금손상 , 15 - -20 -> 심한손상 , 나머지 가치상실
	float PerfectStatus = 35.0f;
	float LittleDamageStatus = 15.0f;
	float DamageStatus = -20.0f;
	float LossValueStatus = -30.0f;

	std::shared_ptr<class USpriteRenderer> MerchandiseRender;
	std::shared_ptr<class UCollision> MerchandiseCollision;

};

