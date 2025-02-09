#pragma once
#include <EnginePlatform/EngineSound.h>

// ���� :
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
	std::string FullText = "NONE";  // ��ü ����
	std::string CurrentDisplayedText = ""; // ���� ǥ�õǴ� ����
	size_t CurrentTextIndex = 0;  // ���� �� ��° ���ڸ� ����ϴ���
	float TypingSpeed = 0.1f;  // ���� ��� �ӵ� (�� ����)
	float TypingTimer = 0.0f;  // Ÿ�̸�

	std::shared_ptr<class USpriteRenderer> PlayerBaloonRender;
	std::shared_ptr<class UFontRenderer> PlayerText;

};

