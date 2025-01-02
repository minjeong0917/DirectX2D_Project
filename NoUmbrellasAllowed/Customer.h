#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class ACustomer : public AActor
{
public:
	// constrcuter destructer
	ACustomer();
	~ACustomer();

	// delete Function
	ACustomer(const ACustomer& _Other) = delete;
	ACustomer(ACustomer&& _Other) noexcept = delete;
	ACustomer& operator=(const ACustomer& _Other) = delete;
	ACustomer& operator=(ACustomer&& _Other) noexcept = delete;

protected:

private:
	void CreateAnimation(std::shared_ptr<class USpriteRenderer>& _Render, std::string_view _AnimationName, std::string_view _SpriteName, float _Scale, std::vector<int> _Indexs, std::vector<float> _Frame, bool _Loop = true);

	std::shared_ptr<class USpriteRenderer> HeadRenderer;
	std::shared_ptr<class USpriteRenderer> HairRenderer;
	std::shared_ptr<class USpriteRenderer> BodyRenderer;
	std::shared_ptr<class USpriteRenderer> RightEyeRenderer;
	std::shared_ptr<class USpriteRenderer> LeftEyeRenderer;
	std::shared_ptr<class USpriteRenderer> RightEyebrowRenderer;
	std::shared_ptr<class USpriteRenderer> LeftEyebrowRenderer;
	std::shared_ptr<class USpriteRenderer> NoseRenderer;
	std::shared_ptr<class USpriteRenderer> MouseRenderer;


};

