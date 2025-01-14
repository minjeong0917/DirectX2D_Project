#pragma once
#include "ContentsEnums.h"
// Ό³Έν :
class ASelectedCard : public AActor
{
public:
	// constrcuter destructer
	ASelectedCard();
	~ASelectedCard();

	// delete Function
	ASelectedCard(const ASelectedCard& _Other) = delete;
	ASelectedCard(ASelectedCard&& _Other) noexcept = delete;
	ASelectedCard& operator=(const ASelectedCard& _Other) = delete;
	ASelectedCard& operator=(ASelectedCard&& _Other) noexcept = delete;
	void SetCardType(ECardType _CardTye, int _CardStep);


protected:
	void Tick(float _DeltaTime);

private:
	std::shared_ptr<class USpriteRenderer> SelectedCardRender;
	std::shared_ptr<class UCollision> SelectedCardCollision;
};

