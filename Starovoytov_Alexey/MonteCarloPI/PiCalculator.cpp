#include "PICalculator.h"



PiCalculator::PiCalculator(size_t iterationCount, size_t threadCount)
	: m_iterationCount(iterationCount)
	, m_threadCount(threadCount)
{
}

size_t PiCalculator::GetIterationCount()
{
	return m_iterationCount;
}

size_t PiCalculator::GetThreadCount()
{
	return m_threadCount;
}
