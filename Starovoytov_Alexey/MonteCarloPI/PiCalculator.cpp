#include "PICalculator.h"

PiCalculator::PiCalculator(unsigned int iterationCount, unsigned int threadCount)
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

unsigned int PiCalculator::GetInCirclePointCount() const
{
	ProgressData *progressData = new ProgressData({ 0, m_iterationCount });
	vector<HANDLE> threadHandles;
	threadHandles.emplace_back(ThreadHelper::CreateSimpleThread((LPTHREAD_START_ROUTINE)PrintProgress, progressData));
	InitRandomizer();
	unsigned int result = 0;
	for (unsigned int i = 0; i < m_iterationCount; ++i)
	{
		double randomX = GetRandomCoordinateInQuarter();
		double randomY = GetRandomCoordinateInQuarter();
		if (IsPointInCircle(randomX, randomY))
		{
			++result;
		}
		progressData->current = i + 1;
	}
	ThreadHelper::WaitThreads(threadHandles);
	ThreadHelper::CloseThreads(threadHandles);
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

DWORD WINAPI PiCalculator::PrintProgress(CONST LPVOID lpParam)
{
	ProgressData *progressData = (ProgressData*)lpParam;
	double progress = 0;
	while (progress != 100)
	{
		progress = static_cast<double>(progressData->current) / progressData->total * 100;
		cout << "Progress: [" << progress << "% / 100%]   \r";
		Sleep(PROGRESS_BAR_UPDATE_DURATION);
	}
	return 0;
}
