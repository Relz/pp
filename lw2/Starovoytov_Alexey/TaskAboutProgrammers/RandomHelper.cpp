#include "RandomHelper.h"

RandomHelper * RandomHelper::GetInstance()
{
	if (!m_instance)
	{
		m_instance = new RandomHelper();
	}
	return m_instance;
}

int RandomHelper::GetRandomInteger(int from, int to, unsigned int seed)
{
	srand(static_cast<unsigned int>(seed + time(0)));
	return rand() % to + from;
}

RandomHelper * RandomHelper::m_instance = nullptr;
