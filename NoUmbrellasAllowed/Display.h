#pragma once

// Ό³Έν :
class ADisplay : public AActor
{
public:
	// constrcuter destructer
	ADisplay();
	~ADisplay();

	// delete Function
	ADisplay(const ADisplay& _Other) = delete;
	ADisplay(ADisplay&& _Other) noexcept = delete;
	ADisplay& operator=(const ADisplay& _Other) = delete;
	ADisplay& operator=(ADisplay&& _Other) noexcept = delete;

protected:

private:

};

