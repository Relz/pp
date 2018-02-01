#pragma once
#include <ctime>
#include <stdlib.h>

class PiCalculator
{
public:
	explicit PiCalculator(size_t iterationCount, size_t threadCount);
	
	double GetPiValue() const;
	void Calculate();

private:
	static const size_t RADIUS = 1;

	size_t m_iterationCount;
	size_t m_threadCount;

	double m_piValue;

	void InitRandomizer() const;
	size_t GetInCirclePointCount() const;
	bool IsPointInCircle(double x, double y) const;
	double GetRandomCoordinateInQuarter() const;
	double GetRandomCoefficient() const;
};

