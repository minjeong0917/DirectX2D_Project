#pragma once
#include <EngineCore/Actor.h>
#include "UI.h"
// Ό³Έν :
class AButton : public AUI
{
public:
	// constrcuter destructer
	AButton();
	~AButton();

	// delete Function
	AButton(const AButton& _Other) = delete;
	AButton(AButton&& _Other) noexcept = delete;
	AButton& operator=(const AButton& _Other) = delete;
	AButton& operator=(AButton&& _Other) noexcept = delete;

	bool GetButtonIsEnter()
	{
		return IsEnter;
	}

protected:
	void Tick(float _DeltaTime);
	void OnCollisionEnter(class UCollision* _This, class UCollision* _Other);
	void OnCollisionStay(class UCollision* _This, class UCollision* _Other);
	void OnCollisionEnd(class UCollision* _This, class UCollision* _Other);

	void CollisionSet(std::shared_ptr<class UCollision> _Collision);
private:
	std::shared_ptr<class USpriteRenderer> ButtonRender;
	std::shared_ptr<class USpriteRenderer> CEButtonRender;
	std::shared_ptr<class USpriteRenderer> EnterButtonRender;
	std::shared_ptr<class USpriteRenderer> NotDealButtonRender;
	std::shared_ptr<class USpriteRenderer> DealButtonRender;

	std::shared_ptr<class UCollision> ButtonCollision;
	std::shared_ptr<class UCollision> CEButtonCollision;
	std::shared_ptr<class UCollision> EnterButtonCollision;
	std::shared_ptr<class UCollision> EnterButtonCollision2;
	std::shared_ptr<class UCollision> NotDealButtonCollision;
	std::shared_ptr<class UCollision> DealButtonCollision;

	std::string ProfileName = "NONE";
	std::string PrevProfileName = "NONE";

	bool IsEnter = false;
	int ButtonIndex = 0;
	std::vector<std::shared_ptr<class USpriteRenderer>> AllCalculatorButtonRenders;
};

