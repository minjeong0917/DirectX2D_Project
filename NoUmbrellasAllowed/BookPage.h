#pragma once

// Ό³Έν :
class ABookPage : public AActor
{
public:
	// constrcuter destructer
	ABookPage();
	~ABookPage();

	// delete Function
	ABookPage(const ABookPage& _Other) = delete;
	ABookPage(ABookPage&& _Other) noexcept = delete;
	ABookPage& operator=(const ABookPage& _Other) = delete;
	ABookPage& operator=(ABookPage&& _Other) noexcept = delete;

protected:

private:
	std::shared_ptr<class USpriteRenderer> BookSmallRender;
	std::shared_ptr<class UCollision> BookSmallCollision;
};

