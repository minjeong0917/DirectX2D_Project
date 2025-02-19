#include "PreCompile.h"
#include "ContentsCore.h"
#include <EngineCore/Level.h>
#include "TitleGameMode.h"
#include "ShopGameMode.h"
#include <EngineCore/EngineTexture.h>
#include <EngineCore/EngineSprite.h>
#include <EngineCore/EngineFont.h>
#include <EngineCore/HUD.h>
#include "ShopHUD.h"
#include "TitleHUD.h"
#include "Bob.h"
#include <EnginePlatform/EngineSound.h>

CreateContentsCoreDefine(UContentsCore);


UContentsCore::UContentsCore()
{
}

UContentsCore::~UContentsCore()
{
}

void UContentsCore::EngineStart(UEngineInitData& _Data)
{

    UEngineCore::GetMainWindow().SetWindowTitle("No Umbrellas Allowed");

    _Data.WindowPos = { -10, 0 };
    _Data.WindowSize = WindowSize;

    // Font
    {
        {
            UEngineDirectory Dir;
            if (false == Dir.MoveParentToDirectory("NoUmbrellasAllowedResources"))
            {
                MSGASSERT("리소스 폴더를 찾지 못했습니다.");
                return;
            }
            Dir.Append("Fonts");

            UEngineFile FontFiles = Dir.GetFile("PFStardust.ttf");

            UEngineFont::Load("PFttf", FontFiles.GetPathToString());
        }

        UEngineFont::Load("PF", "PF Stardust");
        UEngineFont::Load("PFEXBold", "PF Stardust ExtraBold");
        UEngineFont::Load("OrangeKid", "Orange Kid");
        UEngineFont::Load("DungGeunMo", "DungGeunMo");
    }
    {
        UEngineDirectory Dir;
        if (false == Dir.MoveParentToDirectory("NoUmbrellasAllowedResources"))
        {
            MSGASSERT("리소스 폴더를 찾지 못했습니다.");
            return;
        }
        Dir.Append("Sounds");
        std::vector<UEngineFile> ImageFiles = Dir.GetAllFile(true, { ".wav", ".mp3" });

        for (size_t i = 0; i < ImageFiles.size(); i++)
        {
            std::string FilePath = ImageFiles[i].GetPathToString();
            UEngineSound::Load(FilePath);
        }
    }


    UEngineDirectory Dir;
    if (false == Dir.MoveParentToDirectory("NoUmbrellasAllowedResources"))
    {
        MSGASSERT("리소스 폴더를 찾지 못했습니다.");
        return;
    }

    // TitleImage
    LoadFile(Dir, "Images//TitleImage");

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
        LoadFile(Dir, "Images//Shop//UI");

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

        // Balloons
        LoadFile(Dir, "Images//Shop//Balloons");

        // Main
        LoadFile(Dir, "Images//Shop//Main");

        // Table
        LoadFile(Dir, "Images//Shop//Table");

        // Merchandise
        LoadFile(Dir, "Images//Shop//Merchandise//Bag");
        LoadFile(Dir, "Images//Shop//Merchandise//Umbrella");
        LoadFile(Dir, "Images//Shop//Merchandise//Material"); 

    }

    // Customer
    {
        LoadFile(Dir, "Images//Customer//Eyes");
        //UEngineSprite::CreateSpriteToMeta("000_happy_loop.png", ".sdata");
        for (int i = 0; i < 8; i++)
        {
            UEngineSprite::CreateSpriteToMeta("00" + std::to_string(i) + "_neutral_loop.png", ".sdata");
            UEngineSprite::CreateSpriteToMeta("00" + std::to_string(i) + "_startled_entry.png", ".sdata");
            UEngineSprite::CreateSpriteToMeta("00" + std::to_string(i) + "_happy_entry.png", ".sdata");
        }


        // Head
        LoadFile(Dir, "Images//Customer//Head");
        // WomanHair
        LoadFile(Dir, "Images//Customer//Hair//MainHair");
        LoadFile(Dir, "Images//Customer//Hair//Set");
        // Body
        LoadFile(Dir, "Images//Customer//Body");
        // Eyebrow
        LoadFile(Dir, "Images//Customer//Eyebrow");
        // Nose
        LoadFile(Dir, "Images//Customer//Nose");
        // Mouse
        LoadFile(Dir, "Images//Customer//Mouse//MouseNeutral");
        for (int i = 0; i < 6; i++)
        {
            UEngineSprite::CreateSpriteToMeta("00" + std::to_string(i) + "_Mneutral_loop.png", ".sdata");
        }

        LoadFile(Dir, "Images//Customer//Mouse//MouseStartled");
        for (int i = 0; i < 6; i++)
        {
            UEngineSprite::CreateSpriteToMeta("00" + std::to_string(i) + "_Mstartled_entry.png", ".sdata");
        }

        LoadFile(Dir, "Images//Customer//Mouse//MouseHappy");
        for (int i = 0; i < 6; i++)
        {
            UEngineSprite::CreateSpriteToMeta("00" + std::to_string(i) + "_Mhappy_entry.png", ".sdata");
        }

    }
    // UI
    {
        LoadFile(Dir, "Images//UI//Cursor");

    }
    // UI in the Shop
    {
        LoadFile(Dir, "Images//UIIntheShop//Tools//ItemShelf");
        LoadFile(Dir, "Images//UIIntheShop//Tools//SelectedTool");
        LoadFile(Dir, "Images//UIIntheShop//Calculator//Entity");
        LoadFile(Dir, "Images//UIIntheShop//Calculator//Buttons");
        LoadFile(Dir, "Images//UIIntheShop//Card//CardCase");
        LoadFile(Dir, "Images//UIIntheShop//Card//CardType//Blue");
        LoadFile(Dir, "Images//UIIntheShop//Card//CardType//Gray");
        LoadFile(Dir, "Images//UIIntheShop//Card//CardType//Green");
        LoadFile(Dir, "Images//UIIntheShop//Book//BookMain");
        LoadFile(Dir, "Images//UIIntheShop//Book//BookButton");
        LoadFile(Dir, "Images//UIIntheShop//Book//BookSmall");
        LoadFile(Dir, "Images//UIIntheShop//Book//BookIcon");
        LoadFile(Dir, "Images//UIIntheShop//Inventory");


    }
    UEngineCore::CreateLevel<ATitleGameMode, APawn, ATitleHUD>("Titlelevel");
    UEngineCore::CreateLevel<AShopGameMode, ABob, AShopHUD>("Shoplevel");
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