#pragma once

// ���� :
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
	void SetToolAccessoriesSprite(int _SpriteIndex);
	void SetToolFrontActive(bool _IsActive);
	void SetToolAccRotation(float _Rotation, float _Speed);
	float GetAccRotZ();

protected:
	void Tick(float _DeltaTime);

private:
	std::shared_ptr<class USpriteRenderer> SelectdToolRender;
	std::shared_ptr<class USpriteRenderer> SelectdToolFrontRender;
	std::shared_ptr<class USpriteRenderer> SelectdToolAccessoriesRender;
	std::shared_ptr<class UCollision> SelectdToolCollision;

};

