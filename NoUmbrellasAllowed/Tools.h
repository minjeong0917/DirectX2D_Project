#pragma once

// Ό³Έν :
class ATools : public AActor
{
public:
	// constrcuter destructer
	ATools();
	~ATools();

	// delete Function
	ATools(const ATools& _Other) = delete;
	ATools(ATools&& _Other) noexcept = delete;
	ATools& operator=(const ATools& _Other) = delete;
	ATools& operator=(ATools&& _Other) noexcept = delete;
	bool GetIsToolClick()
	{
		return IsToolClick;
	}
	bool IsSelectedToolActive();

protected:
	void Tick(float _DeltaTime);

	void OnCollisionStay(class UCollision* _This, class UCollision* _Other);
	void OnCollisionEnd(class UCollision* _This, class UCollision* _Other);
private:
	bool IsEnter = false;
	bool IsToolClick = false;
	bool IsSameToolClick = false;
	int CurSpriteIndex = 0;

	float AccRotation = 1.0f;

	int PrevSpriteIndex = 0;
	float Time = 0.0f;
	std::shared_ptr<class USpriteRenderer> ToolsRender;
	std::shared_ptr<class UCollision> ToolsCollision;
	std::shared_ptr<class ASelectedTool> SelectedTools;

	std::vector< std::shared_ptr<class USpriteRenderer>> AllToolsRenders;
};

