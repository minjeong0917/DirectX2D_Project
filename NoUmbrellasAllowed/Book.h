#pragma once

// Ό³Έν :
class ABook : public AActor
{
public:
	// constrcuter destructer
	ABook();
	~ABook();

	// delete Function
	ABook(const ABook& _Other) = delete;
	ABook(ABook&& _Other) noexcept = delete;
	ABook& operator=(const ABook& _Other) = delete;
	ABook& operator=(ABook&& _Other) noexcept = delete;
	bool GetIsBack();
	void SetBookPageActive();
	bool GetIsEnter()
	{
		return IsEnter;
	}
protected:
	void Tick(float _DeltaTime);
	void OnCollisionEnter(class UCollision* _This, class UCollision* _Other);
	void OnCollisionEnd(class UCollision* _This, class UCollision* _Other);
private:
	bool IsEnter = false;


	std::shared_ptr<class USpriteRenderer> BookMainRender;

	std::shared_ptr<class UCollision> BookMainCollision;



	std::shared_ptr<class ABookButton> BookButtons;

};

