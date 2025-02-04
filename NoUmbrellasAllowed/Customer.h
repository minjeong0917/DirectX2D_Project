#pragma once
#include <EngineCore/Actor.h>
#include <EngineBase/FSMStateManager.h>
#include "ContentsEnums.h"

struct PartsInfo
{
public:
	FVector Scale = { 1.0f, 1.0f, 1.0f };
	FVector Location = { 0.0f, 0.0f, 0.0f };
};




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
	void RandomCustomer(int _Gender, int _HairRand, int _Head, int _Body, int _Eyes, int _EyeBrow, int _Nose, int _Mouse);
	void CustomerFSMChange(CustomerFSM _FSM);



protected:
	void Tick(float _DeltaTime);

	void Idle(float _DeltaTime);
	void Angry(float _DeltaTime);
	void Happy(float _DeltaTime);
	void Startled(float _DeltaTime);


private:
	void CreateAnimation(std::shared_ptr<class USpriteRenderer>& _Render, std::string_view _AnimationName, std::string_view _SpriteName, float _Scale, std::vector<int> _Indexs, std::vector<float> _Frame, bool _Loop = true);

	std::shared_ptr<class USpriteRenderer> HeadRenderer;
	std::shared_ptr<class USpriteRenderer> BodyRenderer;

	std::shared_ptr<class USpriteRenderer> HairRenderer;
	std::shared_ptr<class USpriteRenderer> HairRenderer2;
	std::vector<PartsInfo> AllHairInfo;
	std::vector<PartsInfo> AllHairSetInfo;

	std::shared_ptr<class USpriteRenderer> RightEyeRenderer;
	std::shared_ptr<class USpriteRenderer> LeftEyeRenderer;
	std::shared_ptr<class USpriteRenderer> RightEyebrowRenderer;
	std::shared_ptr<class USpriteRenderer> LeftEyebrowRenderer;
	std::shared_ptr<class USpriteRenderer> NoseRenderer;
	std::shared_ptr<class USpriteRenderer> MouseRenderer;

	int CurEyesState = 0;
	int CurHairState = 0;
	int CurMouseState = 0;

	float StartledSpeed = 7.0f;
	float StartledTime = 0.0f;
	UFSMStateManager FSM;

};

