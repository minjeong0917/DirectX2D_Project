#pragma once

// Ό³Έν :
class AItemShelf : public AActor
{
public:
	// constrcuter destructer
	AItemShelf();
	~AItemShelf();

	// delete Function
	AItemShelf(const AItemShelf& _Other) = delete;
	AItemShelf(AItemShelf&& _Other) noexcept = delete;
	AItemShelf& operator=(const AItemShelf& _Other) = delete;
	AItemShelf& operator=(AItemShelf&& _Other) noexcept = delete;

protected:
	void Tick(float _DeltaTime);

	void OnCollisionEnter(class UCollision* _This, class UCollision* _Other);
	void OnCollisionEnd(class UCollision* _This, class UCollision* _Other);
private:
	bool IsEnter = false;

	std::shared_ptr<class USpriteRenderer> ItemShelfRender;
	std::shared_ptr<class UCollision> ItemShelfCollision;
};

