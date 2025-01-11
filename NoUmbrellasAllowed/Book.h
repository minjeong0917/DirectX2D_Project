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

	bool GetIsEnter()
	{
		return IsEnter;
	}
	void SetButtonActive(bool IsActive);
	void SetIsBack(bool IsActive);
	bool GetIsBack();
	int GetNextPage()
	{
		return NextPage;
	}

	void SetIsBookActive(bool _Value)
	{
		IsBookActive = _Value;
	}
	void SetPage0();

protected:
protected:
	void Tick(float _DeltaTime);
	void OnCollisionEnter(class UCollision* _This, class UCollision* _Other);
	void OnCollisionEnd(class UCollision* _This, class UCollision* _Other);
	void CollsionSetting(int _Page);

private:
	bool IsEnter = false;
	int ClickNum = 0;
	bool ClickBookPage = false;
	bool IsOff = false;

	int NextPage = 0;
	bool IsBookActive = false;
	std::shared_ptr<class USpriteRenderer> BookMainRender;

	std::shared_ptr<class UCollision> BookMainCollision;
	std::vector<std::shared_ptr<class UCollision>> AllBookPageCollision;

	std::shared_ptr<class ABookButton> BookButtons;



};

