#pragma once


class URenderUnit
{
public:
	// constrcuter destructer
	URenderUnit();
	~URenderUnit();

	// delete Function
	URenderUnit(const URenderUnit& _Other) = delete;
	URenderUnit(URenderUnit&& _Other) noexcept = delete;
	URenderUnit& operator=(const URenderUnit& _Other) = delete;
	URenderUnit& operator=(URenderUnit&& _Other) noexcept = delete;

protected:

private:

};

