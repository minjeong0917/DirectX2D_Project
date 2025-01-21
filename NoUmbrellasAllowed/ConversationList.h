#pragma once
#include "ContentsEnums.h"

// Ό³Έν :
class ConversationList
{
public:
	// constrcuter destructer
	~ConversationList();

	// delete Function
	ConversationList(const ConversationList& _Other) = delete;
	ConversationList(ConversationList&& _Other) noexcept = delete;
	ConversationList& operator=(const ConversationList& _Other) = delete;
	ConversationList& operator=(ConversationList&& _Other) noexcept = delete;


	static ConversationList& GetInst()
	{
		static ConversationList Inst = ConversationList();
		return Inst;
	}
	void SetPlayerConverastion(ECardType _CardType, int _Index);

	std::string GetPlayerConversation()
	{
		return PlayerConversation;
	}

	float GetBallonXSize()
	{
		return BalloonXSize;
	}

protected:

private:
	ConversationList();
	std::string PlayerConversation = "NONE";
	float BalloonXSize = 0.0f;
};

