#pragma once
#include <EngineBase/Object.h>
#include <memory>

// ���� :
class UActorComponent : public UObject
{
public:
	friend class AActor;
	// constrcuter destructer
	UActorComponent();
	~UActorComponent();

	// delete Function
	UActorComponent(const UActorComponent& _Other) = delete;
	UActorComponent(UActorComponent&& _Other) noexcept = delete;
	UActorComponent& operator=(const UActorComponent& _Other) = delete;
	UActorComponent& operator=(UActorComponent&& _Other) noexcept = delete;

	ENGINEAPI class AActor* GetActor();
	ENGINEAPI virtual void InitializeComponent() {}
	ENGINEAPI virtual void BeginPlay() {}
	ENGINEAPI virtual void ComponentTick(float _DeltaTime) {};

	class ULevel* GetWorld();
	ENGINEAPI bool IsActive() override;

	ENGINEAPI bool IsDestroy() override;

protected:

private:
	class AActor* Actor;
};

