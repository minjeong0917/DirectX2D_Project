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
    switch (_PageNum)
    {
    // Page 0 : 목차
    case 0:
    {
        CollisionCount = 13;

        AllCollsionLocation.resize(CollisionCount);

        FVector startPosition = { 540.0f, 70.0f, -170.0f };
        FVector offsetPosition = { 0.0f, -57.0f, 0.0f };

        for (int i = 0; i < CollisionCount; ++i)
        {
            FVector currentPosition = startPosition;

            if (i < 7)
            {
                currentPosition.Y += offsetPosition.Y * i;
            }
            else
            {
                currentPosition.X += 250.0f;
                currentPosition.Y += offsetPosition.Y * (i - 7);
            }

            AllCollsionLocation[i] = currentPosition;
        }

        CollisionScale = { 170.f, 40.f, 0.f };

        MovePageInfo[0] = 1;
        break;
    }
    // Page 1 : 감정도구 - 손상 계기판 설명
    case 1:
    {
        CollisionCount = 1;

        AllCollsionLocation.resize(CollisionCount);

        AllCollsionLocation[0] = { 740.0f, 150.0f, -170.0f };
        CollisionScale = { 100.f, 40.f, 0.f };

        MovePageInfo[0] = 7;
        break;
    }
    // Page 2 : 감정도구 - 재질 돋보기 설명
    case 2:
    {
        CollisionCount = 1;

        AllCollsionLocation.resize(CollisionCount);

        AllCollsionLocation[0] = { 740.0f, 150.0f, -170.0f };
        CollisionScale = { 138.f, 40.f, 0.f };

        MovePageInfo[0] = 7;
        break;
    }
    // Page 3 : 감정도구 - 서명 검출기 설명
    case 3:
    {
        CollisionCount = 2;

        AllCollsionLocation.resize(CollisionCount);

        AllCollsionLocation[0] = { 540.0f, 30.0f, -170.0f };
        CollisionScale = { 138.f, 40.f, 0.f };

        MovePageInfo[0] = 7;
        break;
    }
    // Page 4 : 감정도구 - 연도 추정기 설명
    case 4:
    {
        CollisionCount = 2;

        AllCollsionLocation.resize(CollisionCount);

        AllCollsionLocation[0] = { 540.0f, 30.0f, -170.0f };
        CollisionScale = { 138.f, 40.f, 0.f };

        MovePageInfo[0] = 7;
        break;
    }
    default:
        break;
    }
}
