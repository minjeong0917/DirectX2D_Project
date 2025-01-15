#pragma once
#include <EngineCore/HUD.h>

// Ό³Έν :
class AShopHUD : public AHUD
{
public:
	// constrcuter destructer
	AShopHUD();
	~AShopHUD();

	// delete Function
	AShopHUD(const AShopHUD& _Other) = delete;
	AShopHUD(AShopHUD&& _Other) noexcept = delete;
	AShopHUD& operator=(const AShopHUD& _Other) = delete;
	AShopHUD& operator=(AShopHUD&& _Other) noexcept = delete;

protected:
	void BeginPlay();
	void Tick(float _DeltaTime);
private:
	std::shared_ptr<class UImageWidget> Cursor;
};

