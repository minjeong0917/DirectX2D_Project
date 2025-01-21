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

protected:

private:
	std::shared_ptr<class USpriteRenderer> MerchandiseMaterialRender;

};

