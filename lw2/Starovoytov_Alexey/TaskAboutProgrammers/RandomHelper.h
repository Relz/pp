#pragma once

#include <ctime>
#include <stdlib.h>

class RandomHelper
{
public:
	static RandomHelper * GetInstance();
	int GetRandomInteger(int from, int to, unsigned int seed);

private:
	static RandomHelper * m_instance;

	explicit RandomHelper() = default;
};
