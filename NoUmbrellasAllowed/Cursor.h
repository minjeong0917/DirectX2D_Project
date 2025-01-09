#pragma once
#include "UI.h"
// Ό³Έν :
class ACursor : public AUI
{
public:
	// constrcuter destructer
	ACursor();
	~ACursor();

	// delete Function
	ACursor(const ACursor& _Other) = delete;
	ACursor(ACursor&& _Other) noexcept = delete;
	ACursor& operator=(const ACursor& _Other) = delete;
	ACursor& operator=(ACursor&& _Other) noexcept = delete;
	void SetRenderActive(bool _IsActive);

protected:
	void Tick(float _DeltaTime);
	void OnCollisionEnter(class UCollision* _This, class UCollision* _Other);
	void OnCollisionEnd(class UCollision* _This, class UCollision* _Other);
private:
	bool IsEnter = false;

	std::shared_ptr<class USpriteRenderer> CursorRender;
	std::shared_ptr<class UCollision> CursorCollision;

};

