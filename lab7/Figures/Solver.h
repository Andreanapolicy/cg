#pragma once
class Solver
{
public:
	Solver() = delete;

	std::vector<float> static Solve2(std::vector<float> coefs);
	std::vector<float> static Solve3(std::vector<float> coefs);
	std::vector<float> static Solve4(std::vector<float> coefs);

	bool static isZero(float number);
};
