#pragma once

#include <iostream>

#define PCG32_INC 105

class LuauRandom
{
private:
	uint64_t m_State;

	uint32_t pcg32_random();
	void pcg32_seed(uint64_t seed);

public:
	double NextNumber();
	double NextNumber(double l, double u);
	int NextInteger(int l, int u);

	LuauRandom(uint64_t seed);
};

