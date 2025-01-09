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
	void PlusAlpha(float _DeltaTime, float _Speed);

protected:
	void Tick(float _DeltaTime);
	void BeginPlay();

private:
	std::shared_ptr<class USpriteRenderer> MerchandiseRender;

};

