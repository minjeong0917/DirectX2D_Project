#pragma once
#include <EnginePlatform/EngineSound.h>

// Ό³Έν :
class ATitleGameMode : public AGameMode
{
public:
	// constrcuter destructer
	ATitleGameMode();
	~ATitleGameMode();

	// delete Function
	ATitleGameMode(const ATitleGameMode& _Other) = delete;
	ATitleGameMode(ATitleGameMode&& _Other) noexcept = delete;
	ATitleGameMode& operator=(const ATitleGameMode& _Other) = delete;
	ATitleGameMode& operator=(ATitleGameMode&& _Other) noexcept = delete;



protected:
	void BeginPlay();

	void Tick(float _DeltaTime);
	void LevelChangeEnd();

private:
	USoundPlayer SoundPlayer;
	std::shared_ptr<class ALogo> Logo;
	std::shared_ptr<class AUI> Background;
	std::shared_ptr<class ACursor> Cursor;
	std::vector<std::shared_ptr<class AUI>> AllPlants;

};

