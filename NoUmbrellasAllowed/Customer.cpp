#include "PreCompile.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include "Customer.h"
#include <EnginePlatform/EngineInput.h>

ACustomer::ACustomer()
{
    std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
    RootComponent = Default;
    // Hair Info
    {
        AllHairInfo.resize(11);
        AllHairSetInfo.resize(4);

        // Wonman 0st HairInfo
        AllHairInfo[0].Location = {0.0f, 50.0f, -80.0f };
        AllHairSetInfo[0].Location = { 0.0f, -10.0f, 30.0f };

        // Wonman 1st HairInfo
        AllHairInfo[1].Location = { 0.0f, 77.0f, -80.0f };
        AllHairSetInfo[1].Location = { 0.0f, 160.0f, 30.0f };

        // Wonman 1st HairInfo
        AllHairInfo[2].Location = { 0.0f, 70.0f, -80.0f };
        AllHairSetInfo[2].Location = { 0.0f, -10.0f, 30.0f };

        // Wonman 3st HairInfo
        AllHairInfo[3].Location = { 0.0f, 78.0f, -80.0f };
        AllHairSetInfo[3].Location = { 0.0f, -70.0f, 30.0f };

        AllHairInfo[4].Location = { 0.0f, 75.0f, -80.0f };
        AllHairInfo[5].Location = { 0.0f, 80.0f, -80.0f };
        AllHairInfo[6].Location = { 0.0f, 80.0f, -80.0f };
        AllHairInfo[7].Location = { 0.0f, 80.0f, -80.0f };
        AllHairInfo[8].Location = { 0.0f, 80.0f, -80.0f };
        AllHairInfo[9].Location = { 0.0f, 80.0f, -80.0f };

    }


    int HairNum = 1;
    HairRenderer2 = CreateDefaultSubObject<USpriteRenderer>();
    HairRenderer2->SetSprite("Set", HairNum);
    HairRenderer2->SetWorldLocation(AllHairSetInfo[HairNum].Location);
    HairRenderer2->SetupAttachment(RootComponent);
    HairRenderer2->SetActive(false);

    int Form = 2;

    BodyRenderer = CreateDefaultSubObject<USpriteRenderer>();
    BodyRenderer->SetSprite("Body", Form);
    BodyRenderer->SetAutoScaleRatio(3.0f);
    BodyRenderer->SetWorldLocation({ 0.0f, -210.0f, 20.0f });
    BodyRenderer->SetupAttachment(RootComponent);

    HeadRenderer = CreateDefaultSubObject<USpriteRenderer>();
    HeadRenderer->SetSprite("Head", Form);
    HeadRenderer->SetWorldLocation({ 0.0f, -11.0f, 10.0f });
    HeadRenderer->SetAutoScaleRatio(3.0f);
    HeadRenderer->SetupAttachment(RootComponent);


    RightEyeRenderer = CreateDefaultSubObject<USpriteRenderer>();

    CreateAnimation(RightEyeRenderer, "Idle_000", "000_neutral_loop.png", 3.1f, { 0,1,2, 3,4 }, { 0.1f,0.1f,0.1f, 0.1f,4.0f });
    CreateAnimation(RightEyeRenderer, "Idle_001", "001_neutral_loop.png", 3.1f, { 0,1,2, 3,4 }, { 0.1f,0.1f,0.1f, 0.1f,4.0f });
    CreateAnimation(RightEyeRenderer, "Idle_002", "002_neutral_loop.png", 3.1f, { 0,1,2, 3,4 }, { 0.1f,0.1f,0.1f, 0.1f,4.0f });
    CreateAnimation(RightEyeRenderer, "Idle_003", "003_neutral_loop.png", 3.1f, { 0,1,2, 3,4 }, { 0.1f,0.1f,0.1f, 0.1f,4.0f });
    CreateAnimation(RightEyeRenderer, "Idle_004", "004_neutral_loop.png", 3.1f, { 0,1,2, 3 ,4 }, { 0.1f,0.1f,0.1f, 0.1f,4.0f });
    CreateAnimation(RightEyeRenderer, "Idle_005", "005_neutral_loop.png", 3.1f, { 0,1,2, 3,4 }, { 0.1f,0.1f,0.1f, 0.1f,4.0f });
    CreateAnimation(RightEyeRenderer, "Idle_006", "006_neutral_loop.png", 3.1f, { 0,1,2, 3,4 }, { 0.1f,0.1f,0.1f, 0.1f,4.0f });
    CreateAnimation(RightEyeRenderer, "Idle_007", "007_neutral_loop.png", 3.1f, { 0,1,2, 3,4 }, { 0.1f,0.1f,0.1f, 0.1f,4.0f });
    RightEyeRenderer->ChangeAnimation("Idle_000");

    CreateAnimation(RightEyeRenderer, "Startled_000", "000_startled_entry.png", 3.1f, { 0,1,2, 3,4 }, { 0.1f,0.1f,0.1f, 0.1f,4.0f }, false);
    CreateAnimation(RightEyeRenderer, "Startled_001", "001_startled_entry.png", 3.1f, { 0,1,2, 3,4 }, { 0.1f,0.1f,0.1f, 0.1f,4.0f }, false);
    CreateAnimation(RightEyeRenderer, "Startled_002", "002_startled_entry.png", 3.1f, { 0,1,2, 3,4 }, { 0.1f,0.1f,0.1f, 0.1f,4.0f }, false);
    CreateAnimation(RightEyeRenderer, "Startled_003", "003_startled_entry.png", 3.1f, { 0,1,2, 3,4 }, { 0.1f,0.1f,0.1f, 0.1f,4.0f }, false);
    CreateAnimation(RightEyeRenderer, "Startled_004", "004_startled_entry.png", 3.1f, { 0,1,2, 3 ,4 }, { 0.1f,0.1f,0.1f, 0.1f,4.0f }, false);
    CreateAnimation(RightEyeRenderer, "Startled_005", "005_startled_entry.png", 3.1f, { 0,1,2, 3,4 }, { 0.1f,0.1f,0.1f, 0.1f,4.0f }, false);
    CreateAnimation(RightEyeRenderer, "Startled_006", "006_startled_entry.png", 3.1f, { 0,1,2, 3,4 }, { 0.1f,0.1f,0.1f, 0.1f,4.0f }, false);
    CreateAnimation(RightEyeRenderer, "Startled_007", "007_startled_entry.png", 3.1f, { 0,1,2, 3,4 }, { 0.1f,0.1f,0.1f, 0.1f,4.0f }, false);

    RightEyeRenderer->SetWorldLocation({ 27.0f, 63.0f, 2.0f });
    RightEyeRenderer->SetupAttachment(RootComponent);

    LeftEyeRenderer = CreateDefaultSubObject<USpriteRenderer>();
    CreateAnimation(LeftEyeRenderer, "Idle_000", "000_neutral_loop.png", 3.1f, { 0,1,2, 3,4 }, { 0.1f,0.1f,0.1f,0.1f, 4.0f });
    CreateAnimation(LeftEyeRenderer, "Idle_001", "001_neutral_loop.png", 3.1f, { 0,1,2, 3,4 }, { 0.1f,0.1f,0.1f,0.1f, 4.0f });
    CreateAnimation(LeftEyeRenderer, "Idle_002", "002_neutral_loop.png", 3.1f, { 0,1,2, 3,4 }, { 0.1f,0.1f,0.1f,0.1f, 4.0f });
    CreateAnimation(LeftEyeRenderer, "Idle_003", "003_neutral_loop.png", 3.1f, { 0,1,2, 3 ,4 }, { 0.1f,0.1f,0.1f, 0.1f,4.0f });
    CreateAnimation(LeftEyeRenderer, "Idle_004", "004_neutral_loop.png", 3.1f, { 0,1,2, 3 ,4 }, { 0.1f,0.1f,0.1f, 0.1f,4.0f });
    CreateAnimation(LeftEyeRenderer, "Idle_005", "005_neutral_loop.png", 3.1f, { 0,1,2, 3,4 }, { 0.1f,0.1f,0.1f, 0.1f,4.0f });
    CreateAnimation(LeftEyeRenderer, "Idle_006", "006_neutral_loop.png", 3.1f, { 0,1,2, 3,4 }, { 0.1f,0.1f,0.1f, 0.1f,4.0f });
    CreateAnimation(LeftEyeRenderer, "Idle_007", "007_neutral_loop.png", 3.1f, { 0,1,2, 3,4 }, { 0.1f,0.1f,0.1f, 0.1f,4.0f });

    LeftEyeRenderer->ChangeAnimation("Idle_000");
    CreateAnimation(LeftEyeRenderer, "Startled_000", "000_startled_entry.png", 3.1f, { 0,1,2, 3,4 }, { 0.1f,0.1f,0.1f,0.1f, 4.0f }, false);
    CreateAnimation(LeftEyeRenderer, "Startled_001", "001_startled_entry.png", 3.1f, { 0,1,2, 3,4 }, { 0.1f,0.1f,0.1f, 0.1f,4.0f }, false);
    CreateAnimation(LeftEyeRenderer, "Startled_002", "002_startled_entry.png", 3.1f, { 0,1,2, 3,4 }, { 0.1f,0.1f,0.1f, 0.1f,4.0f }, false);
    CreateAnimation(LeftEyeRenderer, "Startled_003", "003_startled_entry.png", 3.1f, { 0,1,2, 3,4 }, { 0.1f,0.1f,0.1f, 0.1f,4.0f }, false);
    CreateAnimation(LeftEyeRenderer, "Startled_004", "004_startled_entry.png", 3.1f, { 0,1,2, 3 ,4 }, { 0.1f,0.1f,0.1f, 0.1f,4.0f }, false);
    CreateAnimation(LeftEyeRenderer, "Startled_005", "005_startled_entry.png", 3.1f, { 0,1,2, 3,4 }, { 0.1f,0.1f,0.1f, 0.1f,4.0f }, false);
    CreateAnimation(LeftEyeRenderer, "Startled_006", "006_startled_entry.png", 3.1f, { 0,1,2, 3,4 }, { 0.1f,0.1f,0.1f, 0.1f,4.0f }, false);
    CreateAnimation(LeftEyeRenderer, "Startled_007", "007_startled_entry.png", 3.1f, { 0,1,2, 3,4 }, { 0.1f,0.1f,0.1f, 0.1f,4.0f }, false);

    LeftEyeRenderer->SetWorldLocation({ -27.0f, 63.0f, -2.0f });
    LeftEyeRenderer->SetRotation({ 0.0f, -180.0f, 0.0f });
    LeftEyeRenderer->SetupAttachment(RootComponent);

    RightEyebrowRenderer = CreateDefaultSubObject<USpriteRenderer>();
    RightEyebrowRenderer->SetSprite("Eyebrow", 1);
    RightEyebrowRenderer->SetWorldLocation({ 23.0f, 85.0f, 1.0f });
    RightEyebrowRenderer->SetAutoScaleRatio(3.0f);
    RightEyebrowRenderer->SetupAttachment(RootComponent);

    LeftEyebrowRenderer = CreateDefaultSubObject<USpriteRenderer>();
    LeftEyebrowRenderer->SetSprite("Eyebrow", 1);
    LeftEyebrowRenderer->SetAutoScaleRatio(3.0f);
    LeftEyebrowRenderer->SetRotation({ 0.0f, 180.0f, 0.0f });
    LeftEyebrowRenderer->SetWorldLocation({ -23.0f, 85.0f, -3.0f });
    LeftEyebrowRenderer->SetupAttachment(RootComponent);

    NoseRenderer = CreateDefaultSubObject<USpriteRenderer>();
    NoseRenderer->SetSprite("Nose", 0);
    NoseRenderer->SetWorldLocation({ 0.0f, 45.0f, 0.0f });
    NoseRenderer->SetAutoScaleRatio(3.0f);
    NoseRenderer->SetupAttachment(RootComponent);

    MouseRenderer = CreateDefaultSubObject<USpriteRenderer>();
    //MouseRenderer->SetSprite("MouseNeutral", 0);
    //MouseRenderer->SetAutoScaleRatio(3.0f);
    MouseRenderer->SetWorldLocation({ 0.0f, 10.0f, 2.0f });
    MouseRenderer->SetupAttachment(RootComponent);

    CreateAnimation(MouseRenderer, "Idle_000", "000_Mneutral_loop.png", 3.1f, { 0}, { 0.1f });
    CreateAnimation(MouseRenderer, "Idle_001", "001_Mneutral_loop.png", 3.1f, { 0}, { 0.1f });
    CreateAnimation(MouseRenderer, "Idle_002", "002_Mneutral_loop.png", 3.1f, { 0}, { 0.1f });
    CreateAnimation(MouseRenderer, "Idle_003", "003_Mneutral_loop.png", 3.1f, { 0}, { 0.1f });
    CreateAnimation(MouseRenderer, "Idle_004", "004_Mneutral_loop.png", 3.1f, { 0}, { 0.1f });
    CreateAnimation(MouseRenderer, "Idle_005", "005_Mneutral_loop.png", 3.1f, { 0}, { 0.1f });
    MouseRenderer->ChangeAnimation("Idle_000");


    CreateAnimation(MouseRenderer, "Startled_000", "000_Mstartled_entry.png", 3.1f, { 0, 1, 2, 3, 4 }, { 0.05f, 0.05f, 0.05f, 0.05f, 0.05f }, false);
    CreateAnimation(MouseRenderer, "Startled_001", "001_Mstartled_entry.png", 3.1f, { 0, 1, 2, 3, 4 }, { 0.05f, 0.05f, 0.05f, 0.05f, 0.05f }, false);
    CreateAnimation(MouseRenderer, "Startled_002", "002_Mstartled_entry.png", 3.1f, { 0, 1, 2, 3, 4 }, { 0.05f, 0.05f, 0.05f, 0.05f, 0.05f }, false);
    CreateAnimation(MouseRenderer, "Startled_003", "003_Mstartled_entry.png", 3.1f, { 0, 1, 2, 3, 4 }, { 0.05f, 0.05f, 0.05f, 0.05f, 0.05f }, false);
    CreateAnimation(MouseRenderer, "Startled_004", "004_Mstartled_entry.png", 3.1f, { 0, 1, 2, 3, 4 }, { 0.05f, 0.05f, 0.05f, 0.05f, 0.05f }, false);
    CreateAnimation(MouseRenderer, "Startled_005", "005_Mstartled_entry.png", 3.1f, { 0, 1, 2, 3, 4 }, { 0.05f, 0.05f, 0.05f, 0.05f, 0.05f }, false);

    HairRenderer = CreateDefaultSubObject<USpriteRenderer>();
    HairRenderer->SetSprite("MainHair", HairNum);
    HairRenderer->SetWorldLocation(AllHairInfo[HairNum].Location);
    HairRenderer->SetAutoScaleRatio(3.0f);
    HairRenderer->SetupAttachment(RootComponent);

    FSM.CreateState(CustomerFSM::Idle, std::bind(&ACustomer::Idle, this, std::placeholders::_1),
        [this]()
        {
            RightEyeRenderer->SetWorldLocation({ 27.0f, 63.0f, 2.0f });
            LeftEyeRenderer->SetWorldLocation({ -27.0f, 63.0f, -2.0f });
            RightEyeRenderer->ChangeAnimation("Idle_00" + std::to_string(CurEyesState));
            LeftEyeRenderer->ChangeAnimation("Idle_00" + std::to_string(CurEyesState));
            MouseRenderer->ChangeAnimation("Idle_00" + std::to_string(CurMouseState));
        }
    );

    FSM.CreateState(CustomerFSM::Startled, std::bind(&ACustomer::Startled, this, std::placeholders::_1),
        [this]()
        {
            Idle(0.0f);

            if (CurEyesState == 1)
            {
                RightEyeRenderer->AddWorldLocation({ 6.0f, 0.0f,0.0f });
                LeftEyeRenderer->AddWorldLocation({ -6.0f, 0.0f,0.0f });
            }
            else if (CurEyesState == 2)
            {
                RightEyeRenderer->AddWorldLocation({ 3.0f, -3.0f,0.0f });
                LeftEyeRenderer->AddWorldLocation({ -3.0f,-3.0f,0.0f });
            }
            else if (CurEyesState == 3)
            {
                RightEyeRenderer->AddWorldLocation({ 3.0f, -3.0f,0.0f });
                LeftEyeRenderer->AddWorldLocation({ -3.0f,-3.0f,0.0f });
            }
            else if (CurEyesState == 4)
            {
                RightEyeRenderer->AddWorldLocation({ 5.0f, 0.0f,0.0f });
                LeftEyeRenderer->AddWorldLocation({ -5.0f,0.0f,0.0f });
            }
            else if (CurEyesState == 5)
            {
                RightEyeRenderer->AddWorldLocation({ 4.0f, 0.0f,0.0f });
                LeftEyeRenderer->AddWorldLocation({ -4.0f,0.0f,0.0f });
            }
            RightEyeRenderer->ChangeAnimation("Startled_00" + std::to_string(CurEyesState));
            LeftEyeRenderer->ChangeAnimation("Startled_00" + std::to_string(CurEyesState));
            MouseRenderer->ChangeAnimation("Startled_00" + std::to_string(CurMouseState));
        }
    );

    FSM.CreateState(CustomerFSM::Angry, std::bind(&ACustomer::Angry, this, std::placeholders::_1),
        [this]()
        {
            //SpriteRenderer->ChangeAnimation("Run" + DirString);
        }
    );




    FSM.ChangeState(CustomerFSM::Idle);

}

ACustomer::~ACustomer()
{
}
void ACustomer::Tick(float _DeltaTime)
{
    AActor::Tick(_DeltaTime);

    if (UEngineInput::IsDown('H'))
    {
        FSM.ChangeState(CustomerFSM::Startled);
    }
    if (UEngineInput::IsDown('I'))
    {
        FSM.ChangeState(CustomerFSM::Idle);
    }

    FSM.Update(_DeltaTime);

}

void ACustomer::CustomerFSMChange(CustomerFSM _FSM)
{
    FSM.ChangeState(_FSM);
}

void ACustomer::Idle(float _DeltaTime)
{
    StartledTime = 0.0f;

    if (CurHairState < 4)
    {
        HairRenderer2->SetWorldLocation(AllHairSetInfo[CurHairState].Location);
    }

    HairRenderer->SetWorldLocation(AllHairInfo[CurHairState].Location);

    BodyRenderer->SetWorldLocation({ 0.0f, -210.0f, 20.0f });
    HeadRenderer->SetWorldLocation({ 0.0f, -11.0f, 10.0f });

    RightEyeRenderer->SetWorldLocation({ 27.0f, 63.0f, 2.0f });
    LeftEyeRenderer->SetWorldLocation({ -27.0f, 63.0f, -2.0f });

    RightEyebrowRenderer->SetWorldLocation({ 23.0f, 85.0f, 1.0f });
    LeftEyebrowRenderer->SetWorldLocation({ -23.0f, 85.0f, -3.0f });

    NoseRenderer->SetWorldLocation({ 0.0f, 45.0f, 0.0f });

    MouseRenderer->SetWorldLocation({ 0.0f, 10.0f, 2.0f });


}
void ACustomer::Angry(float _DeltaTime)
{

}
void ACustomer::Startled(float _DeltaTime)
{
    FVector DownLoc = { 0.0f,-2.0f,0.0f };
    FVector UPLoc = {0.0f,3.0f,0.0f};
    StartledTime += _DeltaTime;

    if (StartledTime < 0.1f)
    {
        HeadRenderer->AddWorldLocation(DownLoc * _DeltaTime * StartledSpeed);
        BodyRenderer->AddWorldLocation(DownLoc * _DeltaTime * StartledSpeed);

        HairRenderer->AddWorldLocation(DownLoc * _DeltaTime * StartledSpeed);
        if (CurHairState < 4)
        {
            HairRenderer2->AddWorldLocation(DownLoc * _DeltaTime * StartledSpeed);
        }
        RightEyeRenderer->AddWorldLocation(DownLoc * _DeltaTime * StartledSpeed);
        LeftEyeRenderer->AddWorldLocation(DownLoc * _DeltaTime * StartledSpeed);
        RightEyebrowRenderer->AddWorldLocation(DownLoc * _DeltaTime * StartledSpeed);
        LeftEyebrowRenderer->AddWorldLocation(DownLoc * _DeltaTime * StartledSpeed);
        NoseRenderer->AddWorldLocation(DownLoc * _DeltaTime * StartledSpeed);
        MouseRenderer->AddWorldLocation(DownLoc * _DeltaTime * StartledSpeed);
    }

    else if (StartledTime >= 0.1f && StartledTime < 0.3f)
    {
        HeadRenderer->AddWorldLocation(UPLoc * _DeltaTime * StartledSpeed);
        BodyRenderer->AddWorldLocation(UPLoc * _DeltaTime * StartledSpeed);

        HairRenderer->AddWorldLocation(UPLoc * _DeltaTime * StartledSpeed);
        if (CurHairState < 4)
        {
            HairRenderer2->AddWorldLocation(UPLoc * _DeltaTime * StartledSpeed);
        }
        RightEyeRenderer->AddWorldLocation(UPLoc * _DeltaTime * StartledSpeed);
        LeftEyeRenderer->AddWorldLocation(UPLoc * _DeltaTime * StartledSpeed);
        RightEyebrowRenderer->AddWorldLocation(UPLoc * _DeltaTime * StartledSpeed);
        LeftEyebrowRenderer->AddWorldLocation(UPLoc * _DeltaTime * StartledSpeed);
        NoseRenderer->AddWorldLocation(UPLoc * _DeltaTime * StartledSpeed);
        MouseRenderer->AddWorldLocation(UPLoc * _DeltaTime * StartledSpeed);
    }
}

void ACustomer::CreateAnimation(std::shared_ptr<class USpriteRenderer>& _Render, std::string_view _AnimationName, std::string_view _SpriteName, float _Scale, std::vector<int> _Indexs, std::vector<float> _Frame, bool _Loop)
{
    _Render->CreateAnimation(_AnimationName, _SpriteName, _Indexs, _Frame, _Loop);
    _Render->SetAutoScaleRatio(_Scale);
}

void ACustomer::RandomCustomer(int _Gender, int _HairRand, int _Head, int _Body, int _Eyes, int _EyeBrow, int _Nose, int _Mouse)
{
    UEngineDebug::OutPutString("_EyeBrow : " + std::to_string(_EyeBrow));

    int Test = 1;

    CurMouseState = _Mouse;
    //CurMouseState = Test;

    if (_Gender == 0)
    {
        CurEyesState = _Eyes;
        CurHairState = _HairRand;

        HairRenderer->SetSprite("MainHair", _HairRand);
        HairRenderer->SetWorldLocation(AllHairInfo[_HairRand].Location);
        HeadRenderer->SetSprite("Head", _Head);
        BodyRenderer->SetSprite("Body", _Body);

        if (_HairRand < 4)
        {
            HairRenderer2->SetActive(true);
            HairRenderer2->SetSprite("Set", _HairRand);
            HairRenderer2->SetWorldLocation(AllHairSetInfo[_HairRand].Location);
        }
        else
        {
            HairRenderer2->SetActive(false);
        }
        //CurEyesState = Test;
        FSM.ChangeState(CustomerFSM::Idle);
    }

    if (_Gender == 1)
    {
        int ManNum = 4;
        _HairRand += ManNum + 1;
        _Head += ManNum;
        _Body += ManNum;
        _Eyes += ManNum;
        CurEyesState = _Eyes;
        CurHairState = _HairRand;

        UEngineDebug::OutPutString("ManHair : " + std::to_string(_HairRand));
        HairRenderer->SetSprite("MainHair", _HairRand);
        HairRenderer->SetWorldLocation(AllHairInfo[_HairRand].Location);
        HairRenderer2->SetActive(false);
        HeadRenderer->SetSprite("Head", _Head);
        BodyRenderer->SetSprite("Body", _Body);

        //CurEyesState = Test;

        FSM.ChangeState(CustomerFSM::Idle);
    }



    //MouseRenderer->SetSprite("MouseNeutral", _Mouse);
    NoseRenderer->SetSprite("Nose", _Nose);

    RightEyebrowRenderer->SetSprite("Eyebrow", _EyeBrow);
    LeftEyebrowRenderer->SetSprite("Eyebrow", _EyeBrow);

}