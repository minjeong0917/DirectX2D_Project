#pragma once
#include <EngineCore/Actor.h>

// ���� :
class ALogo : public AActor
{
public:
	// constrcuter destructer
	ALogo();
	~ALogo();

	// delete Function
	ALogo(const ALogo& _Other) = delete;
	ALogo(ALogo&& _Other) noexcept = delete;
	ALogo& operator=(const ALogo& _Other) = delete;
	ALogo& operator=(ALogo&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class URenderer> LogoRenderer;
};

