#pragma once

// Ό³Έν :
class ACustomerBalloon : public AActor
{
public:
	// constrcuter destructer
	ACustomerBalloon();
	~ACustomerBalloon();

	// delete Function
	ACustomerBalloon(const ACustomerBalloon& _Other) = delete;
	ACustomerBalloon(ACustomerBalloon&& _Other) noexcept = delete;
	ACustomerBalloon& operator=(const ACustomerBalloon& _Other) = delete;
	ACustomerBalloon& operator=(ACustomerBalloon&& _Other) noexcept = delete;

	void SetCustomerBalloonAndText();

protected:

private:
	float BoxXScale = 0.0f;
	float BoxYScale = 0.0f;
	std::string Text = "NONE";

	std::shared_ptr<class USpriteRenderer> CustomerBaloonRender;
	std::shared_ptr<class UFontRenderer> CustomerText;
};

