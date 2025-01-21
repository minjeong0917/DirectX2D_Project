#pragma once

// Ό³Έν :
class APlayerBalloon : public AActor
{
public:
	// constrcuter destructer
	APlayerBalloon();
	~APlayerBalloon();

	// delete Function
	APlayerBalloon(const APlayerBalloon& _Other) = delete;
	APlayerBalloon(APlayerBalloon&& _Other) noexcept = delete;
	APlayerBalloon& operator=(const APlayerBalloon& _Other) = delete;
	APlayerBalloon& operator=(APlayerBalloon&& _Other) noexcept = delete;
	void SetPlayerBalloonAndText();

protected:
	void BeginPlay();

private:
	float BoxXScale = 0.0f;
	std::string Text = "NONE";
	std::shared_ptr<class USpriteRenderer> PlayerBaloonRender;
	std::shared_ptr<class UFontRenderer> PlayerText;

};

