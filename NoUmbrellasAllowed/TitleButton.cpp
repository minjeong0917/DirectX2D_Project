#include "PreCompile.h"

#include "TitleButton.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/FontRenderer.h>
#include <EngineCore/Collision.h>

ATitleButton::ATitleButton()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	 StartText = CreateDefaultSubObject<UFontRenderer>();
	 StartText->SetFont("PF", 50.0f, TColor<unsigned char>(255, 255, 255, 255));
     StartText->SetText("»õ °ÔÀÓ");
	 StartText->SetupAttachment(RootComponent);



     CardCollision = CreateDefaultSubObject<UCollision>();
     CardCollision->SetCollisionProfileName("TitleButton");
     CardCollision->SetRelativeLocation({ 70.f,-25.f,1.0f });
     CardCollision->SetScale3D({ 150.f,60.f,1.0f });
     CardCollision->SetupAttachment(RootComponent);


     CardCollision->SetCollisionEnter([this](UCollision* _This, UCollision* _Other)
         {
             this->OnCollisionEnter(_This, _Other);
         });
     CardCollision->SetCollisionEnd([this](UCollision* _This, UCollision* _Other)
         {
             this->OnCollisionEnd(_This, _Other);

         });
}

ATitleButton::~ATitleButton()
{
}
void ATitleButton::OnCollisionEnter(UCollision* _This, UCollision* _Other)
{
    IsEnter = true;

}

void ATitleButton::OnCollisionEnd(UCollision* _This, UCollision* _Other)
{
    IsEnter = false;
}

