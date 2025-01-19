#pragma once
#include "ContentsEnums.h"
#include "Card.h"

// Ό³Έν :
class ASelectedCard : public ACard
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

	void SetCardType(ECardColor _CardTye, int _CardStep) override;
	void SetCardNameText(std::string _Text);
	void SetCardExplainText(std::string _Text);
	void SetCardPercentText(std::string _Text);

	void SetTextActive(bool _IsActive);

protected:
	void Tick(float _DeltaTime);
	void BeginPlay();


private:
	bool HaveN = false;
	std::shared_ptr<class USpriteRenderer> SelectedCardRender;
	std::shared_ptr<class UCollision> SelectedCardCollision;
	std::shared_ptr<class UFontRenderer> CardNameText;
	std::shared_ptr<class UFontRenderer> CardExplainText;
	std::shared_ptr<class UFontRenderer> CardPercentText;

};

