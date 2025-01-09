#include "PreCompile.h"

#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/Collision.h>
#include "Tools.h"
#include "SelectedTool.h"

ATools::ATools()
{
    std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
    RootComponent = Default;

    FVector StartPos = { -205.0f,-525.0f,-153.0f };
    FVector IterPos = { 82.0f, 0.0f,0.0f };

    for (int i = 0; i < 6; i++)
    {
        ToolsRender = CreateDefaultSubObject<USpriteRenderer>();
        ToolsRender->SetAutoScaleRatio(3.0f);
        ToolsRender->SetWorldLocation({ StartPos.X + (IterPos.X * i),StartPos.Y , -153.0f });
        ToolsRender->SetupAttachment(RootComponent);
        AllToolsRenders.push_back(ToolsRender);

        ToolsCollision = CreateDefaultSubObject<UCollision>();
        ToolsCollision->SetCollisionProfileName("Tools_" + std::to_string(i));
        ToolsCollision->SetScale3D({ 60.0f,60.0f,0.0f });
        ToolsCollision->SetWorldLocation({ StartPos.X + 3 + ((IterPos.X - 1) * i), StartPos.Y + 22, -155.0f });
        ToolsCollision->SetupAttachment(RootComponent);

        ToolsCollision->SetCollisionStay([this](UCollision* _This, UCollision* _Other)
            {
                this->OnCollisionStay(_This, _Other);

            });
        ToolsCollision->SetCollisionEnd([this](UCollision* _This, UCollision* _Other)
            {
                this->OnCollisionEnd(_This, _Other);

            });

    }

    AllToolsRenders[0]->SetSprite("ItemShelf", 2);

    AllToolsRenders[1]->SetSprite("ItemShelf", 3);
    AllToolsRenders[1]->AddWorldLocation({ 2.0f, 0.0f,0.0f });

    AllToolsRenders[2]->SetSprite("ItemShelf", 4);
    AllToolsRenders[2]->AddWorldLocation({ 1.0f, 0.0f,0.0f });

    AllToolsRenders[3]->SetSprite("ItemShelf", 5);
    AllToolsRenders[3]->AddWorldLocation({ 0.0f, -3.0f,0.0f });

    AllToolsRenders[4]->SetSprite("ItemShelf", 6);
    AllToolsRenders[5]->SetSprite("ItemShelf", 7);
    AllToolsRenders[5]->AddWorldLocation({ -1.0f, 0.0f,0.0f });

    SelectedToolools = GetWorld()->SpawnActor<ASelectedTool>();
    SelectedToolools->SetActive(false);

}

ATools::~ATools()
{
}
void ATools::Tick(float _DeltaTime)
{
    AActor::Tick(_DeltaTime);
    if (IsEnter == false && IsToolClick == true && UEngineInput::IsDown(VK_LBUTTON))
    {
        IsToolClick = false;
        SelectedToolools->SetActive(false);
        AllToolsRenders[CurSpriteIndex - 2]->SetActive(true);
    }
}

void ATools::OnCollisionStay(UCollision* _This, UCollision* _Other)
{
    IsEnter = true;

    std::string ProfileName = _This->GetCollisionProfileName();

    if (UEngineInput::IsDown(VK_LBUTTON))
    {
        if ( IsToolClick == true)
        {
            size_t Index = std::stoi(ProfileName.substr(6));

            CurSpriteIndex = AllToolsRenders[Index]->GetCurIndex();
 
            AllToolsRenders[CurSpriteIndex - 2]->SetActive(true);
            AllToolsRenders[PrevSpriteIndex - 2]->SetActive(true);
            SelectedToolools->SetActive(false);
            IsToolClick = false;
      
            if (CurSpriteIndex != PrevSpriteIndex)
            {
                IsToolClick = true;
                AllToolsRenders[CurSpriteIndex - 2]->SetActive(false);
                PrevSpriteIndex = CurSpriteIndex;
                SelectedToolools->SetToolSprite(CurSpriteIndex - 2);
                SelectedToolools->SetActive(true);
            }
        }
        else if (IsToolClick == false)
        {
            size_t Index = std::stoi(ProfileName.substr(6));
            CurSpriteIndex = AllToolsRenders[Index]->GetCurIndex();

            IsToolClick = true;
            PrevSpriteIndex = CurSpriteIndex;
            
            AllToolsRenders[PrevSpriteIndex - 2]->SetActive(false);
            SelectedToolools->SetToolSprite(PrevSpriteIndex - 2);
            SelectedToolools->SetActive(true);
        }

    }


}
void ATools::OnCollisionEnd(UCollision* _This, UCollision* _Other)
{
    IsEnter = false;
}