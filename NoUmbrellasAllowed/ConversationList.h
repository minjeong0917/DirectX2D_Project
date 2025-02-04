#pragma once
#include "ContentsEnums.h"

// 설명 :
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
	// Player Convo
	void SetPlayerConversation(ECardType _CardType, int _Index);
	void SetPlayerOfferPriceConvo(int _Price, int _RandomConvo);
	void SetPlayerNotDealConvo(int _RandomConvo);

	// Customer Convo
	void SetCustomerCardConversation(ECardType _CardType, bool _IsPriceUp, int _RandomConversation);
	void SetCustomerGoodDealConvo(int _Price, int _RandomConvo);
	void SetCustomerGoodDealConvo2(int _RandomConvo);
	void SetCustomerOfferPriceConvo(int _Price, int _RandomConvo);
	void SetCustomerRefuseConvo(int _Price, int _RandomConvo);
	void SetCustomerNotDealConvo(int _Price, int _RandomConvo); // Customer가 거래 포기
	void SetCustomerPlayerNotDealConvo(int _RandomConvo); // Player가 거래 포기 시



	
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

