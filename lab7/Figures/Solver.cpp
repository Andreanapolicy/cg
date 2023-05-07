#include "stdafx.h"
#include "Solver.h"

namespace
{
constexpr float EQN_EPS = 1e-9f;
}

std::vector<float> Solver::Solve2(std::vector<float> coefs)
{
	assert(coefs.size() == 3);
	// x^2 + px + q = 0
	const auto p = coefs[1] / (2.0f * coefs[2]);
	const auto q = coefs[0] / coefs[2];

	const auto D = p * p - q;
	if (isZero(D))
	{
		return { -p };
	}
	else if (D < 0)
	{
		return {};
	}

	const auto sqrtD = sqrt(D);

	return { sqrtD - p, -sqrtD - p};
}

std::vector<float> Solver::Solve3(std::vector<float> coefs)
{
	return std::vector<float>();
}

std::vector<float> Solver::Solve4(std::vector<float> coefs)
{
	return std::vector<float>();
}

bool Solver::isZero(float number)
{
	return (number > -EQN_EPS && number < EQN_EPS);
}
