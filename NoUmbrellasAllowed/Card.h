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
	virtual void SetCardType(ECardColor _CardTye, int _CardStep);

	void SetCardNameText(std::string _Text);
	void SetCardExplainText(std::string _Text);
	void SetCardPercentText(std::string _Text);

	void SetTextActive(bool _IsActive);
	void ChangeTextSize(float _Size);
	void SetCollisionActive(bool _IsActive);
	void SetCollisionYScale(float _YScale);
	void SetCollisionYLocation(float _YLoc);

	bool GetIsEnter()
	{
		return IsEnter;
	}


protected:
	void BeginPlay();
	void Tick(float _DeltaTime);
	void OnCollisionEnter(class UCollision* _This, class UCollision* _Other);
	void OnCollisionEnd(class UCollision* _This, class UCollision* _Other);
private:
	bool IsEnter = false;
	int percent = 0;

	std::shared_ptr<class USpriteRenderer> CardRender;
	std::shared_ptr<class UCollision> CardCollision;

	std::shared_ptr<class UFontRenderer> CardNameText;
	std::shared_ptr<class UFontRenderer> CardExplainText;
	std::shared_ptr<class UFontRenderer> CardPercentText;
};

