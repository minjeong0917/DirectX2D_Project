#pragma once

// Ό³Έν :
class ATitleButton : public AActor
{
public:
	// constrcuter destructer
	ATitleButton();
	~ATitleButton();

	// delete Function
	ATitleButton(const ATitleButton& _Other) = delete;
	ATitleButton(ATitleButton&& _Other) noexcept = delete;
	ATitleButton& operator=(const ATitleButton& _Other) = delete;
	ATitleButton& operator=(ATitleButton&& _Other) noexcept = delete;

	void OnCollisionEnter(class UCollision* _This, class UCollision* _Other);
	void OnCollisionEnd(class UCollision* _This, class UCollision* _Other);

	bool GetIsEnter()
	{
		return IsEnter;
	}
protected:
	
private:
	std::shared_ptr<class USpriteRenderer> StartButtonRenderer;
	std::shared_ptr<class UFontRenderer> StartText;
	std::shared_ptr<class UCollision> CardCollision;
	bool IsEnter = false;
};

