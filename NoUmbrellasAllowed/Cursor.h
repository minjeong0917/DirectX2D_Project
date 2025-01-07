#pragma once

// Ό³Έν :
class ACursor : public AActor
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

protected:
	void Tick(float _DeltaTime);

private:
	std::shared_ptr<class USpriteRenderer> CursorRender;
	std::shared_ptr<class UCollision> CursorCollision;

};

