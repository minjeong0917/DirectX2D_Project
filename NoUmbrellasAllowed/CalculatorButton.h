#pragma once
#include <EngineCore/Actor.h>
#include "UI.h"
// Ό³Έν :
class ACalculatorButton : public AUI
{
public:
	// constrcuter destructer
	ACalculatorButton();
	~ACalculatorButton();

	// delete Function
	ACalculatorButton(const ACalculatorButton& _Other) = delete;
	ACalculatorButton(ACalculatorButton&& _Other) noexcept = delete;
	ACalculatorButton& operator=(const ACalculatorButton& _Other) = delete;
	ACalculatorButton& operator=(ACalculatorButton&& _Other) noexcept = delete;

	bool GetButtonIsEnter()
	{
		return IsEnter;
	}
	void SetButtonIsEnter(bool _Value)
	{
		IsEnter = _Value;
	}


	int GetCurButtonIndex()
	{
		return CurButtonIndex;
	}
	void SetIsMerchandiseActive(bool _IsMerchandiseActive)
	{
		IsMerchandiseActive = _IsMerchandiseActive;
	}


protected:
	void Tick(float _DeltaTime);
	void OnCollisionEnter(class UCollision* _This, class UCollision* _Other);
	void OnCollisionStay(class UCollision* _This, class UCollision* _Other);
	void OnCollisionEnd(class UCollision* _This, class UCollision* _Other);

	void CollisionSet(std::shared_ptr<class UCollision> _Collision);

	int MerchandiseActive = 0;

private:
	std::shared_ptr<class USpriteRenderer> ButtonRender;
	std::shared_ptr<class UFontRenderer> NumButtonText;
	std::shared_ptr<class USpriteRenderer> CEButtonRender;
	std::shared_ptr<class UFontRenderer> CEButtonText1;
	std::shared_ptr<class UFontRenderer> CEButtonText2;
	std::shared_ptr<class USpriteRenderer> EnterButtonRender;
	std::shared_ptr<class UFontRenderer> EnterButtonText;
	std::shared_ptr<class USpriteRenderer> NotDealButtonRender;
	std::shared_ptr<class UFontRenderer> NotDealButtonText;
	std::shared_ptr<class USpriteRenderer> DealButtonRender;
	std::shared_ptr<class UFontRenderer> DealButtonText;

	std::shared_ptr<class UCollision> ButtonCollision;
	std::shared_ptr<class UCollision> CEButtonCollision;
	std::shared_ptr<class UCollision> EnterButtonCollision;
	std::shared_ptr<class UCollision> EnterButtonCollision2;
	std::shared_ptr<class UCollision> NotDealButtonCollision;
	std::shared_ptr<class UCollision> DealButtonCollision;

	std::string ProfileName = "NONE";
	std::string PrevProfileName = "NONE";

	bool IsMerchandiseActive = false;
	bool IsEnter = false;
	bool IsPushEnter = false;

	int CurButtonIndex = 0;
	std::vector<std::shared_ptr<class USpriteRenderer>> AllCalculatorButtonRenders;
};

