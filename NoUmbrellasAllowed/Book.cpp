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


    for (int i = 0; i < 3; i++)
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

    if (BookButtons->GetIsBack() == true)
    {
        for (int i = 0; i < AllBookPageCollision.size(); i++)
        {
            AllBookPageCollision[i]->SetActive(false);
        }

        BookPageInfo::GetInst().SetPageInfo(0);
        BookMainRender->SetSprite("BookMain", 0);
        CollsionSetting(0);
    }

    if (IsEnter == true)
    {
        if (UEngineInput::IsDown(MK_LBUTTON))
        {
            if (ClickBookPage == true)
            {
                for (int i = 0; i < AllBookPageCollision.size(); i++)
                {
                    AllBookPageCollision[i]->SetActive(false);
                }

                NextPage = BookPageInfo::GetInst().GetMovePageInfo(ClickNum);
                BookPageInfo::GetInst().SetPageInfo(NextPage);
                BookMainRender->SetSprite("BookMain", NextPage);

                CollsionSetting(NextPage);
            }
        }
    }
}
void ABook::CollsionSetting(int _Page)
{
    BookPageInfo::GetInst().SetPageInfo(_Page);
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
        size_t Index = std::stoi(ProfileName.substr(9));
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
