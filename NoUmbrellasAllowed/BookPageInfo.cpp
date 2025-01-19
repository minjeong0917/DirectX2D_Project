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
    CurPage = _PageNum;
    switch (_PageNum)
    {
    // Page 0 : 목차
    case 0:
    {
        CollisionCount = 13;
        HasNextPage = true;
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
        MovePageInfo[1] = 7;
        MovePageInfo[2] = 8;
     
        break;
    }
    // Page 1 : 감정도구 - 손상 계기판 설명
    case 1:
    {
        CollisionCount = 1;
        HasNextPage = true;


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
        HasNextPage = true;

        AllCollsionLocation.resize(CollisionCount);

        AllCollsionLocation[0] = { 740.0f, 150.0f, -170.0f };
        CollisionScale = { 100.f, 40.f, 0.f };

        MovePageInfo[0] = 8;
        break;
    }
    // Page 3 : 감정도구 - 서명 검출기 설명
    case 3:
    {
        CollisionCount = 2;
        HasNextPage = true;

        AllCollsionLocation.resize(CollisionCount);

        AllCollsionLocation[0] = { 750.0f, 150.0f, -170.0f };
        AllCollsionLocation[1] = { 750.0f, 100.0f, -170.0f };
        CollisionScale = {120.f, 40.f, 0.f };

        MovePageInfo[0] = 0;
        MovePageInfo[1] = 0;
        break;
    }
    // Page 4 : 감정도구 - 연도 추정기 설명
    case 4:
    {
        CollisionCount = 2;
        HasNextPage = true;

        AllCollsionLocation.resize(CollisionCount);

        AllCollsionLocation[0] = { 750.0f, 150.0f, -170.0f };
        AllCollsionLocation[1] = { 750.0f, 100.0f, -170.0f };
        CollisionScale = { 160.f, 40.f, 0.f };

        MovePageInfo[0] = 0;
        break;
    }
    // Page 5 : 감정도구 - 보석 감정기 설명
    case 5:
    {
        CollisionCount = 1;
        HasNextPage = true;

        AllCollsionLocation.resize(CollisionCount);
        AllCollsionLocation[0] = { 740.0f, 150.0f, -170.0f };
        CollisionScale = { 100.f, 40.f, 0.f };

        MovePageInfo[0] = 0;
        break;
    }
    // Page 6 : 감정도구 - 시계 드라이버 설명
    case 6:
    {
        CollisionCount = 1;
        HasNextPage = true;

        AllCollsionLocation.resize(CollisionCount);

        AllCollsionLocation[0] = { 750.0f, 150.0f, -170.0f };
        CollisionScale = { 190.f, 40.f, 0.f };

        MovePageInfo[0] = 0;
        break;
    }
    // Page 7 : 상태 
    case 7:
    {
        CollisionCount = 5;
        HasNextPage = false;

        AllCollsionLocation.resize(CollisionCount);

        AllCollsionLocation[0] = { 619.0f, 209.0f, -170.0f };
        AllCollsionLocation[1] = { 619.0f, 90.0f, -170.0f };
        AllCollsionLocation[2] = { 619.0f, -29.0f, -170.0f };
        AllCollsionLocation[3] = { 619.0f, -148.0f, -170.0f };
        AllCollsionLocation[4] = { 666.0f, -286.0f, -170.0f };
        CollisionScale = { 280.f, 100.f, 0.f };

        break;
    }
    // Page 8 : 재질 
    case 8:
    {
        CollisionCount = 21;
        HasNextPage = false;

        AllCollsionLocation.resize(CollisionCount);

        FVector StartPos = { 478.0f, 215.0f, -170.0f };
        FVector IterPos = { 96.51f, 0.0f, 0.0f };

        for (int i = 0; i < 5; i++)
        {
            AllCollsionLocation[i] = { StartPos.X + IterPos.X * i, StartPos.Y , -170.0f };
        }
        for (int i = 5; i < 9; i++)
        {
            AllCollsionLocation[i] = { StartPos.X + IterPos.X * (i-5), StartPos.Y - 97.f , -170.0f };
        }
        for (int i = 9; i < 12; i++)
        {
            AllCollsionLocation[i] = { StartPos.X + IterPos.X * (i - 9), StartPos.Y - 230.0f , -170.0f };
        }
        for (int i = 12; i < 17; i++)
        {
            AllCollsionLocation[i] = { StartPos.X + IterPos.X * (i - 12), StartPos.Y - 358.0f, -170.0f };
        }
        for (int i = 17; i < 21; i++)
        {
            AllCollsionLocation[i] = { StartPos.X + IterPos.X * (i - 17), StartPos.Y - 460.f , -170.0f };
        }

        CollisionScale = { 83.f, 83.f, 0.f };

        break;
    }
    default:
        CollisionCount = 0;

        HasNextPage = false;
        break;
    }
}
