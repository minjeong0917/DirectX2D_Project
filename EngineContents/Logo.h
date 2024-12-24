#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
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
	std::shared_ptr<class USpriteRenderer> GetRenderer()
	{
		return LogoRenderer;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> LogoRenderer;
};

