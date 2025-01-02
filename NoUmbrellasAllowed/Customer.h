#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class ACustomer : public AActor
{
public:
	// constrcuter destructer
	ACustomer();
	~ACustomer();

	// delete Function
	ACustomer(const ACustomer& _Other) = delete;
	ACustomer(ACustomer&& _Other) noexcept = delete;
	ACustomer& operator=(const ACustomer& _Other) = delete;
	ACustomer& operator=(ACustomer&& _Other) noexcept = delete;

protected:

private:
	std::shared_ptr<class USpriteRenderer> CustomerRenderer;

};

