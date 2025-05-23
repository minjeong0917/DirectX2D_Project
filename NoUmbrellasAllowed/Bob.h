#pragma once

// ���� :
class ABob : public APawn
{
public:
	// constrcuter destructer
	ABob();
	~ABob();

	// delete Function
	ABob(const ABob& _Other) = delete;
	ABob(ABob&& _Other) noexcept = delete;
	ABob& operator=(const ABob& _Other) = delete;
	ABob& operator=(ABob&& _Other) noexcept = delete;

protected:
	void BeginPlay();
	void Tick(float _DeltaTime);
private:
	std::shared_ptr<class UFontRenderer> GoldText;

};

