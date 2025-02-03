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
	void SetPlayerConversation(ECardType _CardType, int _Index);
	void SetCustomerCardConversation(ECardType _CardType, bool _IsPriceUp, int _RandomConversation);

	std::string GetPlayerConversation()
	{
		return PlayerConversation;
	}

	float GetPlayerBalloonXSize()
	{
		return PlayerBalloonXSize;
	}

	std::string GetCustomerConversation()
	{
		return CustomerConversation;
	}

	float GetCustomerBalloonXSize()
	{
		return CustomerBalloonXSize;
	}
	float GetCustomerBalloonYSize()
	{
		return CustomerBalloonYSize;
	}
protected:

private:
	ConversationList();
	std::string PlayerConversation = "NONE";
	float PlayerBalloonXSize = 0.0f;

	std::string CustomerConversation = "NONE";
	float CustomerBalloonXSize = 0.0f;
	float CustomerBalloonYSize = 0.0f;
};

