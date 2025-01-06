#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class AUI : public AActor
{
public:
    // constrcuter destructer
    AUI();
    ~AUI();

    // delete Function
    AUI(const AUI& _Other) = delete;
    AUI(AUI&& _Other) noexcept = delete;
    AUI& operator=(const AUI& _Other) = delete;
    AUI& operator=(AUI&& _Other) noexcept = delete;

    std::shared_ptr<class USpriteRenderer> GetRenderer()
    {
        return UIRenderer;
    }
    void SetUISprite(std::string _Name, int _Index);
    void SetAutoScale(float _Value);
    void SetUIScale3D(const FVector& _Value);
    void CreateAnimation(std::string_view _AnimationName, std::string_view _SpriteName, float _Scale, int _Start, int _End, float Time = 0.1f, bool _Loop = true);
    void CreateAnimation(std::string_view _AnimationName, std::string_view _SpriteName, float _Scale, std::vector<int> _Indexs, std::vector<float> _Frame, bool _Loop = true);
    void ChangeAnimation(std::string_view _AnimationName, bool _Force = false);
    void SetRelativeLocation(const FVector& _Value);
    float4 GetLocation();


    float CurApearTime = 0.0f;
    float ApearTime = 3.0f;
    bool IsApear = false;

protected:
    void BeginPlay() override;
    void Tick(float _DeltaTime) override;
private:
    std::shared_ptr<class USpriteRenderer> UIRenderer;

};

