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
	m_piValue = 4.0 * GetInCirclePointCount() / m_iterationCount;
}

size_t PiCalculator::GetInCirclePointCount() const
{
	InitRandomizer();
	size_t result = 0;
	for (size_t i = 0; i < m_iterationCount; ++i)
	{
		double randomX = GetRandomCoordinateInQuarter();
		double randomY = GetRandomCoordinateInQuarter();
		if (IsPointInCircle(randomX, randomY))
		{
			++result;
		}
	}
	return result;
}

void PiCalculator::InitRandomizer() const
{
	srand(static_cast<unsigned int>(time(0)));
}

double PiCalculator::GetRandomCoordinateInQuarter() const
{
	return GetRandomCoefficient() * RADIUS;
}

double PiCalculator::GetRandomCoefficient() const
{
	return static_cast<double>(rand()) / RAND_MAX;
}

bool PiCalculator::IsPointInCircle(double x, double y) const
{
	return x * x + y * y <= RADIUS * RADIUS;
}
