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

private:

};

