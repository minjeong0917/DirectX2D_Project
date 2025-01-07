#include "PreCompile.h"
#include "ContentsCore.h"
#include <EngineCore/Level.h>
#include "TitleGameMode.h"
#include "ShopGameMode.h"
#include <EngineCore/EngineTexture.h>
#include <EngineCore/EngineSprite.h>


CreateContentsCoreDefine(UContentsCore);


UContentsCore::UContentsCore()
{
}

UContentsCore::~UContentsCore()
{
}

void UContentsCore::EngineStart(UEngineInitData& _Data)
{

    //UEngineCore::MainWindow.SetWindowTitle("No Umbrellas Allowed");

    _Data.WindowPos = { -10, 0 };
    _Data.WindowSize = WindowSize;

    UEngineDirectory Dir;
    if (false == Dir.MoveParentToDirectory("NoUmbrellasAllowedResources"))
    {
        MSGASSERT("리소스 폴더를 찾지 못했습니다.");
        return;
    }

    // TitleImage
    LoadFile(Dir, "Images//TitleImage");

    UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
    UEngineSprite::CreateSpriteToMeta("plant_01_loop.png", ".sdata");
    UEngineSprite::CreateSpriteToMeta("plant_02_loop.png", ".sdata");
    UEngineSprite::CreateSpriteToMeta("plant_03_loop.png", ".sdata");
    UEngineSprite::CreateSpriteToMeta("holoDoor_loop.png", ".sdata");
    UEngineSprite::CreateSpriteToMeta("window02_light_loop.png", ".sdata");
    UEngineSprite::CreateSpriteToMeta("lamp_halo_loop.png", ".sdata");
    UEngineSprite::CreateSpriteToMeta("name_01_loop.png", ".sdata");
    UEngineSprite::CreateSpriteToMeta("name_02_loop.png", ".sdata");
    UEngineSprite::CreateSpriteToMeta("name_home_loop.png", ".sdata");


    // Logo
    LoadFile(Dir, "Images//Logo");


    // Shop
    {
        LoadFile(Dir, "Images//Shop");

        UEngineSprite::CreateSpriteToMeta("femaleCustomer_walk_01.png", ".sdata");
        UEngineSprite::CreateSpriteToMeta("femaleCustomer_walk_02.png", ".sdata");
        UEngineSprite::CreateSpriteToMeta("femaleCustomer_walk_03.png", ".sdata");
        UEngineSprite::CreateSpriteToMeta("femaleCustomer_walk_04.png", ".sdata");
        UEngineSprite::CreateSpriteToMeta("maleCustomer_walk_01.png", ".sdata");
        UEngineSprite::CreateSpriteToMeta("maleCustomer_walk_02.png", ".sdata");
        UEngineSprite::CreateSpriteToMeta("maleCustomer_walk_03.png", ".sdata");
        UEngineSprite::CreateSpriteToMeta("maleCustomer_walk_04.png", ".sdata");
        UEngineSprite::CreateSpriteToMeta("companion_idle_loop.png", ".sdata");


        // Ocean
        LoadFile(Dir, "Images//Shop//Ocean");

        // Main
        LoadFile(Dir, "Images//Shop//Main");

        // Table
        LoadFile(Dir, "Images//Shop//Table");
    }

    // Customer
    {
        LoadFile(Dir, "Images//Customer//Eyes");
        UEngineSprite::CreateSpriteToMeta("000_happy_loop.png", ".sdata");
        UEngineSprite::CreateSpriteToMeta("001_neutral_loop.png", ".sdata");
        UEngineSprite::CreateSpriteToMeta("002_neutral_loop.png", ".sdata");
        UEngineSprite::CreateSpriteToMeta("003_neutral_loop.png", ".sdata");
        UEngineSprite::CreateSpriteToMeta("004_neutral_loop.png", ".sdata");
        UEngineSprite::CreateSpriteToMeta("005_neutral_loop.png", ".sdata");
        UEngineSprite::CreateSpriteToMeta("006_neutral_loop.png", ".sdata");
        UEngineSprite::CreateSpriteToMeta("007_neutral_loop.png", ".sdata");

        // Head
        LoadFile(Dir, "Images//Customer//Head");
        // WomanHair
        LoadFile(Dir, "Images//Customer//Hair");
        LoadFile(Dir, "Images//Customer//Hair//Set");
        // Body
        LoadFile(Dir, "Images//Customer//Body");
        // Eyebrow
        LoadFile(Dir, "Images//Customer//Eyebrow");
        // Nose
        LoadFile(Dir, "Images//Customer//Nose");
        // Mouse
        LoadFile(Dir, "Images//Customer//Mouse");
    }
    // UI in the Shop
    {
        LoadFile(Dir, "Images//UIIntheShop//Calculator//Entity");
        LoadFile(Dir, "Images//UIIntheShop//Calculator//Buttons");


    }
    UEngineCore::CreateLevel<ATitleGameMode, APawn>("Titlelevel");
    UEngineCore::CreateLevel<AShopGameMode, APawn>("Shoplevel");
    UEngineCore::OpenLevel("Titlelevel");




}

void UContentsCore::EngineTick(float _DeltaTime)
{

}

void UContentsCore::EngineEnd()
{

}

void UContentsCore::LoadFile(UEngineDirectory& _Dir, std::string_view _Path)
{
    _Dir.MoveParentToDirectory("NoUmbrellasAllowedResources");
    _Dir.Append(_Path);
    std::vector<UEngineFile> ImageFiles = _Dir.GetAllFile(true, { ".PNG", ".BMP", ".JPG" });
    for (size_t i = 0; i < ImageFiles.size(); i++)
    {
        std::string FilePath = ImageFiles[i].GetPathToString();
        UEngineTexture::Load(FilePath);
    }
    UEngineSprite::CreateSpriteToFolder(_Dir.GetPathToString());

}