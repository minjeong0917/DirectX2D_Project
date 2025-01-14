#pragma once

// ���� :
class BookPageInfo
{
public:
	// constrcuter destructer
	~BookPageInfo();

	// delete Function
	BookPageInfo(const BookPageInfo& _Other) = delete;
	BookPageInfo(BookPageInfo&& _Other) noexcept = delete;
	BookPageInfo& operator=(const BookPageInfo& _Other) = delete;
	BookPageInfo& operator=(BookPageInfo&& _Other) noexcept = delete;

	static BookPageInfo& GetInst()
	{
		static BookPageInfo Inst = BookPageInfo();
		return Inst;
	}

	void SetPageInfo(int _PageNum);
	int GetCurPage()
	{
		return CurPage;
	}

	int GetCollsionCount()
	{
		return CollisionCount;
	}
	FVector GetAllCollsionLocation(int _Index)
	{
		return AllCollsionLocation[_Index];
	}

	int GetMovePageInfo(int _Index)
	{
		return MovePageInfo[_Index];
	}

	FVector GetAllCollisionScale()
	{
		return CollisionScale;
	}

	bool GetHasNextPage()
	{
		return HasNextPage;
	}
protected:

private:
	BookPageInfo();
	int CurPage = 0;
	int CollisionCount = 0; // �������� �ִ� �浹 ����

	std::vector<FVector> AllCollsionLocation; // �浹ü���� ��ġ
	std::vector<int> MovePageInfo; 
	FVector CollsionLocation = { 0.0f,0.0f,0.0f };
	FVector CollisionScale = { 0.0f,0.0f,0.0f };
	FVector RenderLocation = { 0.0f,0.0f,0.0f };

	bool HasNextPage = false;

};

