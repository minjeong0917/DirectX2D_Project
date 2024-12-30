#include "PreCompile.h"
#include "ContentsCore.h"
#include <EngineCore/Level.h>
#include "TitleGameMode.h"
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

	_Data.WindowPos = { 100, 100 };
	_Data.WindowSize = { 1280, 720 };


	{
		UEngineDirectory Dir;
		if (false == Dir.MoveParentToDirectory("ContentsResources"))
		{
			MSGASSERT("리소스 폴더를 찾지 못했습니다.");
			return;
		}
		Dir.Append("Images");
		std::vector<UEngineFile> ImageFiles = Dir.GetAllFile(true, { ".PNG", ".BMP", ".JPG" });
		for (size_t i = 0; i < ImageFiles.size(); i++)
		{
			std::string FilePath = ImageFiles[i].GetPathToString();
			UEngineTexture::Load(FilePath);
		}
	}

	UEngineSprite::CreateSpriteToMeta("plant_01_loop.png", ".sdata");

	UEngineCore::CreateLevel<ATitleGameMode, APawn>("Titlelevel");
	UEngineCore::OpenLevel("Titlelevel");

}

void UContentsCore::EngineTick(float _DeltaTime)
{

}

void UContentsCore::EngineEnd()
{

}