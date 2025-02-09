#pragma once
#include <EnginePlatform/EngineSound.h>

// 설명 :
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
	void Tick(float _DeltaTime);

private:
	USoundPlayer SoundPlayer;


	float BoxXScale = 0.0f;
	std::string Text = "NONE";

	bool IsStartEffect = false;
	std::string FullText = "NONE";  // 전체 문장
	std::string CurrentDisplayedText = ""; // 현재 표시되는 문장
	size_t CurrentTextIndex = 0;  // 현재 몇 번째 글자를 출력하는지
	float TypingSpeed = 0.1f;  // 글자 출력 속도 (초 단위)
	float TypingTimer = 0.0f;  // 타이머

	std::shared_ptr<class USpriteRenderer> PlayerBaloonRender;
	std::shared_ptr<class UFontRenderer> PlayerText;

};

