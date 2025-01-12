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
	void SetIsBack(bool _Value)
	{
		IsBack = _Value;
	}
	bool IsMoveToIndex = false;
	bool IsMoveToNextPage = false;
	bool IsMoveToBackPage = false;
	bool IsEnter = false;

protected:
	void Tick(float _DeltaTime);
	void OnCollisionStay(class UCollision* _This, class UCollision* _Other);
	void OnCollisionEnd(class UCollision* _This, class UCollision* _Other);
private:
	bool IsBack = false;

	std::shared_ptr<class USpriteRenderer> BackButtonRender;
	std::shared_ptr<class USpriteRenderer> IndexButtonRender;
	std::shared_ptr<class USpriteRenderer> BackPageButtonRender;
	std::shared_ptr<class USpriteRenderer> NextPageButtonRender;

	std::shared_ptr<class UCollision> BackButtonCollision;
	std::shared_ptr<class UCollision> IndexButtonCollision;
	std::shared_ptr<class UCollision> BackPageButtonCollision;
	std::shared_ptr<class UCollision> NextPageButtonCollision;

	std::vector<std::shared_ptr<class USpriteRenderer>> AllBookButtonRenders;

};

