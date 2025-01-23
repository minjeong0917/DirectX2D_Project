#pragma once

// Ό³Έν :
class PlayerInfo
{
public:
	// constrcuter destructer
	~PlayerInfo();

	// delete Function
	PlayerInfo(const PlayerInfo& _Other) = delete;
	PlayerInfo(PlayerInfo&& _Other) noexcept = delete;
	PlayerInfo& operator=(const PlayerInfo& _Other) = delete;
	PlayerInfo& operator=(PlayerInfo&& _Other) noexcept = delete;

	static PlayerInfo& GetInst()
	{
		static PlayerInfo Inst = PlayerInfo();
		return Inst;
	}

	int GetGold()
	{
		return Gold;
	}

	void SetGold(int _Gold)
	{
		Gold = _Gold;
	}


protected:

private:
	PlayerInfo();
	int Gold = 3000;

};

