#include "PreCompile.h"

#include "Book.h"
#include "BookPageInfo.h"
#include "BookButton.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/Collision.h>

ABook::ABook()
{
    std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
    RootComponent = Default;

    BookMainRender = CreateDefaultSubObject<USpriteRenderer>();
    BookMainRender->SetSprite("BookMain", 0);
    //BookMainRender->SetAutoScaleRatio(3.0f);
    BookMainRender->SetWorldLocation({ 670.0f, -410.0f, -170.0f });
    BookMainRender->SetupAttachment(RootComponent);

    BookMainCollision = CreateDefaultSubObject<UCollision>();
    BookMainCollision->SetCollisionProfileName("BookMain");
    BookMainCollision->SetWorldLocation({ 0.0f, 0.5f, 0.0f });
    BookMainCollision->SetupAttachment(BookMainRender);

    BookMainCollision->SetCollisionEnter([this](UCollision* _This, UCollision* _Other)
        {
            this->OnCollisionEnter(_This, _Other);
        });
    BookMainCollision->SetCollisionEnd([this](UCollision* _This, UCollision* _Other)
        {
            this->OnCollisionEnd(_This, _Other);

        });


    for (int i = 0; i < 20; i++)
    {
        std::shared_ptr<class UCollision> BookPageCollision = CreateDefaultSubObject<UCollision>();
        BookPageCollision->SetCollisionProfileName("BookPage_" + std::to_string(i));

        BookPageCollision->SetupAttachment(RootComponent);

        BookPageCollision->SetCollisionEnter([this](UCollision* _This, UCollision* _Other)
            {
                this->OnCollisionEnter(_This, _Other);
            });
        BookPageCollision->SetCollisionEnd([this](UCollision* _This, UCollision* _Other)
            {
                this->OnCollisionEnd(_This, _Other);
            });

        AllBookPageCollision.push_back(BookPageCollision);
    }

    BookButtons = GetWorld()->SpawnActor<ABookButton>();
    BookButtons->SetActive(false);
    CollsionSetting(0);

}

ABook::~ABook()
{
}

void ABook::Tick(float _DeltaTime)
{
    AActor::Tick(_DeltaTime);

    SetBookButtonToPage();
    if (BookButtons->GetIsBack() == true)
    {
        for (int i = 0; i < AllBookPageCollision.size(); i++)
        {
            AllBookPageCollision[i]->SetActive(false);
        }


    }

    if (IsEnter == true)
    {
        if (UEngineInput::IsDown(MK_LBUTTON))
        {
            if (ClickBookPage == true && IsOff == false && BookPageInfo::GetInst().GetHasNextPage() == true)
            {

                for (int i = 0; i < AllBookPageCollision.size(); i++)
                {
                    AllBookPageCollision[i]->SetActive(false);
                }

                NextPage = BookPageInfo::GetInst().GetMovePageInfo(ClickNum);
                //BookPageInfo::GetInst().SetPageInfo(NextPage);
                BookMainRender->SetSprite("BookMain", NextPage);

                CollsionSetting(NextPage);

            }
        }
    }
}
void ABook::CollsionSetting(int _Page)
{
    BookPageInfo::GetInst().SetPageInfo(_Page);
    CurPage = _Page;

    int a = BookPageInfo::GetInst().GetCollsionCount();
    for (int i = 0; i < BookPageInfo::GetInst().GetCollsionCount(); i++)
    {
        AllBookPageCollision[i]->SetActive(true);
        AllBookPageCollision[i]->SetScale3D(BookPageInfo::GetInst().GetAllCollisionScale());
        AllBookPageCollision[i]->SetWorldLocation(BookPageInfo::GetInst().GetAllCollsionLocation(i));
        
    }
  
}

void ABook::OnCollisionEnter(UCollision* _This, UCollision* _Other)
{
    IsEnter = true;

    std::string ProfileName = _This->GetCollisionProfileName();
    if (ProfileName != "BOOKMAIN")
    {
        int Index = std::stoi(ProfileName.substr(9));
        ClickNum = Index;
        ClickBookPage = true;
    }
    else
    {
        ClickBookPage = false;
    }

}
void ABook::OnCollisionEnd(UCollision* _This, UCollision* _Other)
{
    IsEnter = false;
}

void ABook::SetButtonActive(bool IsActive)
{
    BookButtons->SetActive(IsActive);
}

void ABook::SetIsBack(bool IsActive)
{
    BookButtons->SetIsBack(IsActive);
}

bool ABook::GetIsBack()
{
    if (BookButtons->GetIsBack() == true)
    {
        BookButtons->SetActive(false);
    }

    return BookButtons->GetIsBack();
}


void ABook::SetPage0()
{
    for (int i = 0; i < AllBookPageCollision.size(); i++)
    {
        AllBookPageCollision[i]->SetActive(false);
    }
    ClickBookPage = false;

    BookPageInfo::GetInst().SetPageInfo(0);
    BookMainRender->SetSprite("BookMain", 0);
    CollsionSetting(0);
}


void ABook::SetBookButtonToPage()
{
    if (BookButtons->IsEnter == true && UEngineInput::IsUp(VK_LBUTTON))
    {
        if (BookButtons->IsMoveToIndex == true)
        {
            SetPage0();
        }

        else if (BookButtons->IsMoveToBackPage == true && CurPage >= 1)
        {
            for (int i = 0; i < AllBookPageCollision.size(); i++)
            {
                AllBookPageCollision[i]->SetActive(false);
            }

                BookMainRender->SetSprite("BookMain", CurPage - 1);

                CollsionSetting(CurPage - 1);

        }
        else if (BookButtons->IsMoveToNextPage == true && CurPage < 20)
        {
            for (int i = 0; i < AllBookPageCollision.size(); i++)
            {
                AllBookPageCollision[i]->SetActive(false);
            }


                BookMainRender->SetSprite("BookMain", CurPage + 1);

                CollsionSetting(CurPage + 1);


        }
    }

}