#pragma once
#include "ContentsEnums.h"

// Ό³Έν :
class ACard : public AActor
{
public:
	// constrcuter destructer
	ACard();
	~ACard();

	// delete Function
	ACard(const ACard& _Other) = delete;
	ACard(ACard&& _Other) noexcept = delete;
	ACard& operator=(const ACard& _Other) = delete;
	ACard& operator=(ACard&& _Other) noexcept = delete;
	ENGINEAPI virtual void SetCardType(ECardColor _CardTye, int _CardStep);

	void SetCardNameText(std::string _Text);
	void SetTextActive(bool _IsActive);
protected:
	void BeginPlay();
	void Tick(float _DeltaTime);

private:
	std::shared_ptr<class USpriteRenderer> CardRender;
	std::shared_ptr<class UCollision> CardCollision;
	std::shared_ptr<class UFontRenderer> CardNameText;

};

