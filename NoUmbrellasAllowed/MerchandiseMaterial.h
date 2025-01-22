#pragma once

// Ό³Έν :
class AMerchandiseMaterial : public AActor
{
public:
	// constrcuter destructer
	AMerchandiseMaterial();
	~AMerchandiseMaterial();

	// delete Function
	AMerchandiseMaterial(const AMerchandiseMaterial& _Other) = delete;
	AMerchandiseMaterial(AMerchandiseMaterial&& _Other) noexcept = delete;
	AMerchandiseMaterial& operator=(const AMerchandiseMaterial& _Other) = delete;
	AMerchandiseMaterial& operator=(AMerchandiseMaterial&& _Other) noexcept = delete;
	void SetMerchandiseMat(int _Index);

protected:
	void Tick(float _DeltaTime);

private:
	std::shared_ptr<class USpriteRenderer> MerchandiseMaterialRender;
	FVector MatSize;
	FVector ViewSize;
};

