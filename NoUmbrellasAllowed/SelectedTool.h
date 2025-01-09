#pragma once

// Ό³Έν :
class ASelectedTool : public AActor
{
public:
	// constrcuter destructer
	ASelectedTool();
	~ASelectedTool();

	// delete Function
	ASelectedTool(const ASelectedTool& _Other) = delete;
	ASelectedTool(ASelectedTool&& _Other) noexcept = delete;
	ASelectedTool& operator=(const ASelectedTool& _Other) = delete;
	ASelectedTool& operator=(ASelectedTool&& _Other) noexcept = delete;
	void SetToolSprite(int _SpriteIndex);

protected:
	void Tick(float _DeltaTime);

private:
	std::shared_ptr<class USpriteRenderer> SelectdToolRender;
	std::shared_ptr<class UCollision> SelectdToolCollision;

};

