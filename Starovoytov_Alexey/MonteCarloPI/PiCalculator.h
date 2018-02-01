#pragma once
class PiCalculator
{
public:
	explicit PiCalculator(size_t iterationCount, size_t threadCount);
	
	size_t GetIterationCount();
	size_t GetThreadCount();

private:
	size_t m_iterationCount;
	size_t m_threadCount;
};

