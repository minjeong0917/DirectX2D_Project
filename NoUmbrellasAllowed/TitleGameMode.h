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

	void Tick(float _DeltaTime);


protected:

private:
	std::shared_ptr<class ALogo> Logo;
	std::shared_ptr<class ATitleUI> Background;
	std::shared_ptr<class ATitleUI> Building;
	std::shared_ptr<class ATitleUI> BuildingFrame;
	std::shared_ptr<class ATitleUI> BackBuilding1;
	std::shared_ptr<class ATitleUI> BackBuilding2;
	std::shared_ptr<class ATitleUI> BackBuilding3;

	std::vector<class ATitleUI> AllPlants;
};

