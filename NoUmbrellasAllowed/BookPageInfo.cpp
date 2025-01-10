#include "PreCompile.h"

#include "BookPageInfo.h"

BookPageInfo::BookPageInfo()
{
	AllCollsionLocation.resize(20);
	MovePageInfo.resize(20);
}

BookPageInfo::~BookPageInfo()
{
}

void BookPageInfo::SetPageInfo(int _PageNum)
{
	if (_PageNum == 0) // 목차 페이지
	{
		//AllCollsionLocation.clear();
		CollisionCount = 3;
		AllCollsionLocation.resize(CollisionCount);
		FVector StartPos = { 540.0f,70.0f,-170.0f };
		FVector InterPos = { 0.0f,-57.f,0.0f };

		for (int i = 0; i < CollisionCount; i++)
		{
			CollsionLocation = { StartPos.X, StartPos.Y + InterPos.Y * i, - 170.0f };
			AllCollsionLocation[i] = CollsionLocation;
		}
		CollisionScale = { 138.f,40.f,0.f }; 

		MovePageInfo[0] = 1;
		MovePageInfo[1] = 2;
	}
	else if (_PageNum == 1) 
	{
		CollisionCount = 1;
		AllCollsionLocation.resize(CollisionCount);
		CollsionLocation = { 540.0f,30.0f,-170.0f };
		AllCollsionLocation[0] = CollsionLocation;
		CollisionScale = { 138.f,40.f,0.f };

		MovePageInfo[0] = 2;

	}
	else if (_PageNum == 2)
	{
		CollisionCount = 0;

	}

}
