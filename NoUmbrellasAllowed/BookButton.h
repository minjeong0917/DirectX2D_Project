#pragma once

// Ό³Έν :
class ABookButton : public AActor
{
public:
	// constrcuter destructer
	ABookButton();
	~ABookButton();

	// delete Function
	ABookButton(const ABookButton& _Other) = delete;
	ABookButton(ABookButton&& _Other) noexcept = delete;
	ABookButton& operator=(const ABookButton& _Other) = delete;
	ABookButton& operator=(ABookButton&& _Other) noexcept = delete;
	bool GetIsBack()
	{
		return IsBack;
	}

protected:
	void Tick(float _DeltaTime);
	void OnCollisionStay(class UCollision* _This, class UCollision* _Other);
	void OnCollisionEnd(class UCollision* _This, class UCollision* _Other);
private:
	bool IsBack = false;
	std::shared_ptr<class USpriteRenderer> BackButtonRender;
	std::shared_ptr<class UCollision> BackButtonCollision;

	std::vector<std::shared_ptr<class USpriteRenderer>> AllBookButtonRenders;

};

