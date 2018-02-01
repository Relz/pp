#include "PICalculator.h"

PiCalculator::PiCalculator(size_t iterationCount, size_t threadCount)
	: m_iterationCount(iterationCount)
	, m_threadCount(threadCount)
{
}

double PiCalculator::GetPiValue() const
{
	return m_piValue;
}

void PiCalculator::Calculate()
{
	m_piValue = 0;
}
