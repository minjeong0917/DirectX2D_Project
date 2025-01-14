#pragma once

// Ό³Έν :
class ABookSmall : public AActor
{
public:
	// constrcuter destructer
	ABookSmall();
	~ABookSmall();

	// delete Function
	ABookSmall(const ABookSmall& _Other) = delete;
	ABookSmall(ABookSmall&& _Other) noexcept = delete;
	ABookSmall& operator=(const ABookSmall& _Other) = delete;
	ABookSmall& operator=(ABookSmall&& _Other) noexcept = delete;

	void SetRenderActive(bool _IsActive);

	bool GetIsEnter()
	{
		return IsEnter;
	}


protected:
	void Tick(float _DeltaTime);
	void OnCollisionStay(class UCollision* _This, class UCollision* _Other);
	void OnCollisionEnd(class UCollision* _This, class UCollision* _Other);
private:
	bool IsEnter = false;



	std::shared_ptr<class USpriteRenderer> BookSmallRender;
	std::shared_ptr<class UCollision> BookSmallCollision;
	std::shared_ptr<class USpriteRenderer> BookSmallGroundRender;




};

