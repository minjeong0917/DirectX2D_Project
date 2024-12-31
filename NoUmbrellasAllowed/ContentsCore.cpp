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
	if (false == Dir.MoveParentToDirectory("ContentsResources"))
	{
		MSGASSERT("리소스 폴더를 찾지 못했습니다.");
		return;
	}


	{
		Dir.MoveParentToDirectory("ContentsResources");
		Dir.Append("Images//TitleImage");

		LoadFile(Dir);

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
	}

	// Logo
	{
		Dir.MoveParentToDirectory("ContentsResources");
		Dir.Append("Images//Logo");

		LoadFile(Dir);

		UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
	}

	// Shop
	{
		Dir.MoveParentToDirectory("ContentsResources");
		Dir.Append("Images//Shop");

		LoadFile(Dir);


		UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
	}

	// Ocean
	{
		Dir.MoveParentToDirectory("ContentsResources");
		Dir.Append("Images//Shop//Ocean");
		LoadFile(Dir);
		UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
	}

	// Main
	{
		Dir.MoveParentToDirectory("ContentsResources");
		Dir.Append("Images//Shop//Main");
		LoadFile(Dir);
		UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
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

void UContentsCore::LoadFile(UEngineDirectory& _Dir)
{
	std::vector<UEngineFile> ImageFiles = _Dir.GetAllFile(true, { ".PNG", ".BMP", ".JPG" });
	for (size_t i = 0; i < ImageFiles.size(); i++)
	{
		std::string FilePath = ImageFiles[i].GetPathToString();
		UEngineTexture::Load(FilePath);
	}

}