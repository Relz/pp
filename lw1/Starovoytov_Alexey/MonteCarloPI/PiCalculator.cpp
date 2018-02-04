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
	shared_ptr<ProgressData> progressData = make_shared<ProgressData>(ProgressData({ make_shared<unsigned int>(0), m_iterationCount }));
	threadPool.Add(PrintProgress, progressData.get());

	vector<shared_ptr<PiCalculatorData>> piCalculatorDataPointers;
	shared_ptr<unsigned int> inCirclePointCount = make_shared<unsigned int>(0);
	unsigned int rest = m_iterationCount % m_threadCount;
	for (unsigned int i = 0; i < m_threadCount; ++i)
	{
		unsigned int threadIterationCount = m_iterationCount / m_threadCount;
		if (rest != 0)
		{
			++threadIterationCount;
			--rest;
		}
		shared_ptr<PiCalculatorData> piCalculatorData = make_shared<PiCalculatorData>(PiCalculatorData({ inCirclePointCount, threadIterationCount, progressData }));
		threadPool.Add(CalculateInCirclePointCount, piCalculatorData.get());
		piCalculatorDataPointers.emplace_back(piCalculatorData);
	}

	threadPool.Wait();
	threadPool.Close();
	cout << endl;
	return *inCirclePointCount;
}

DWORD WINAPI PiCalculator::PrintProgress(CONST LPVOID data)
{
	ProgressData *progressData = (ProgressData*)data;
	double progress = 0;
	while (!DoubleHelper::AreEqual(progress, 100))
	{
		progress = static_cast<double>(*progressData->current) / progressData->total * 100;
		cout << "Progress: [" << MathHelper::Round<2>(progress) << "% / 100%]   \r";
		Sleep(PROGRESS_BAR_UPDATE_DURATION);
	}
	return 0;
}

DWORD WINAPI PiCalculator::CalculateInCirclePointCount(CONST LPVOID data)
{
	PiCalculatorData *piCalculatorData = (PiCalculatorData*)data;
	RandomHelper randomHelper;
	for (unsigned int i = 0; i < piCalculatorData->iterationCount; ++i)
	{
		if (IsPointInCircle(randomHelper.GetRandomVector2d(0, RADIUS)))
		{
			InterlockedIncrement(piCalculatorData->inCirclePointCount.get());
		}
		InterlockedIncrement(piCalculatorData->progressData->current.get());
	}
	return 0;
}

bool PiCalculator::IsPointInCircle(Vector2d const& vect)
{
	return vect.GetU() * vect.GetU() + vect.GetV() * vect.GetV() <= RADIUS * RADIUS;
}
