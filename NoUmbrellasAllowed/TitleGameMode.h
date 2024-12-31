#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class ATitleGameMode : public AActor
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

private:
	std::shared_ptr<class ALogo> Logo;
	std::shared_ptr<class ATitleUI> Background;
	std::vector<std::shared_ptr<class ATitleUI>> AllPlants;

};

