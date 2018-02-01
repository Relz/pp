#pragma once

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
};

