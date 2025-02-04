#pragma once

typedef __int8 int8;

enum class ECardColor : int8
{
	Blue,
	Gray,
	Green
};


enum class ECardType : int8
{
	NONE,
	BASIC,
	CONDITION,
	TEXTURE
};

enum class EMerchandiseType : int8
{
	NONE,
	BAG,
	UMBRELLA,

};

enum class CustomerFSM : int8
{
	Idle,
	Startled,
	Happy,
	Angry,

};