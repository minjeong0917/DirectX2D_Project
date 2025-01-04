#pragma once
#include <random>

// Ό³Έν :
class ContentsRandom
{
public:
	// constrcuter destructer
	ContentsRandom();
	~ContentsRandom();

	// delete Function
	ContentsRandom(const ContentsRandom& _Other) = delete;
	ContentsRandom(ContentsRandom&& _Other) noexcept = delete;
	ContentsRandom& operator=(const ContentsRandom& _Other) = delete;
	ContentsRandom& operator=(ContentsRandom&& _Other) noexcept = delete;
	void SetSeed(__int64 _Seed)
	{
		MtGen = std::mt19937_64(_Seed);
	}

	int RandomInt(int _Min, int _Max)
	{

		std::uniform_int_distribution<int> RandomCreate(_Min, _Max);

		return RandomCreate.operator()(MtGen);
	}

	float Randomfloat(float _Min, float _Max)
	{
		std::uniform_real_distribution<float> RandomCreate(_Min, _Max);
		return RandomCreate.operator()(MtGen);
	}

protected:

private:
	std::mt19937_64 MtGen = std::mt19937_64(time(nullptr));
};

