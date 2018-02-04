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
	ThreadPool threadPool;
	ProgressData *progressData = new ProgressData({ 0, m_iterationCount });
	threadPool.Add((LPTHREAD_START_ROUTINE)PrintProgress, progressData);
	RandomHelper randomHelper;
	unsigned int result = 0;
	for (unsigned int i = 0; i < m_iterationCount; ++i)
	{
		
		if (IsPointInCircle(randomHelper.GetRandomVector2d(0, RADIUS)))
		{
			++result;
		}
		progressData->current = i + 1;
	}
	threadPool.Wait();
	threadPool.Close();
	cout << endl;
	return result;
}

bool PiCalculator::IsPointInCircle(Vector2d const& vect) const
{
	return vect.GetU() * vect.GetU() + vect.GetV() * vect.GetV() <= RADIUS * RADIUS;
}

DWORD WINAPI PiCalculator::PrintProgress(CONST LPVOID lpParam)
{
	ProgressData *progressData = (ProgressData*)lpParam;
	double progress = 0;
	while (progress != 100)
	{
		progress = RoundHelper::Round2(static_cast<double>(progressData->current) / progressData->total * 100);
		cout << "Progress: [" << progress << "% / 100%]   \r";
		Sleep(PROGRESS_BAR_UPDATE_DURATION);
	}
	return 0;
}
