#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class ATitleUI : public AActor
{
public:
	// constrcuter destructer
	ATitleUI();
	~ATitleUI();

	// delete Function
	ATitleUI(const ATitleUI& _Other) = delete;
	ATitleUI(ATitleUI&& _Other) noexcept = delete;
	ATitleUI& operator=(const ATitleUI& _Other) = delete;
	ATitleUI& operator=(ATitleUI&& _Other) noexcept = delete;

	std::shared_ptr<class USpriteRenderer> GetRenderer()
	{
		return UIRenderer;
	}
	void SetUISprite(std::string _Name, int _Index);
	void SetUIScale3D(const FVector& _Value);
	void CreateAnimation(std::string_view _AnimationName, std::string_view _SpriteName, float _Scale, int _Start, int _End, float Time = 0.1f, bool _Loop = true);
	void ChangeAnimation(std::string_view _AnimationName, bool _Force = false);
	void SetRelativeLocation(const FVector& _Value);

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	std::shared_ptr<class USpriteRenderer> UIRenderer;

};

