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
	threadPool.Add(PrintProgressThreadFunction, progressData.get());

	shared_ptr<unsigned int> inCirclePointCount = make_shared<unsigned int>(0);

	vector<shared_ptr<PiCalculatorData>> piCalculatorDataPointers;
	unsigned int rest = CalculateInThreads(threadPool, piCalculatorDataPointers, inCirclePointCount, progressData);
	unsigned int restThreadIterationCount = m_iterationCount / m_threadCount + rest;
	shared_ptr<PiCalculatorData> restPiCalculatorData = make_shared<PiCalculatorData>(PiCalculatorData({ inCirclePointCount, restThreadIterationCount, progressData }));
	CalculateInCirclePointCount(restPiCalculatorData.get());

	threadPool.Wait();
	threadPool.Close();
	cout << "\n";
	return *inCirclePointCount;
}

unsigned int PiCalculator::CalculateInThreads(ThreadPool& threadPool, vector<shared_ptr<PiCalculatorData>>& piCalculatorDataPointers, shared_ptr<unsigned int> const& inCirclePointCount, shared_ptr<ProgressData> const& progressData) const
{
	unsigned int rest = m_iterationCount % m_threadCount;
	for (unsigned int i = 0; i < m_threadCount - 1; ++i)
	{
		unsigned int threadIterationCount = m_iterationCount / m_threadCount;
		if (rest != 0)
		{
			++threadIterationCount;
			--rest;
		}
		shared_ptr<PiCalculatorData> piCalculatorData = make_shared<PiCalculatorData>(PiCalculatorData({ inCirclePointCount, threadIterationCount, progressData }));
		threadPool.Add(CalculateInCirclePointCountThreadFunction, piCalculatorData.get());
		piCalculatorDataPointers.emplace_back(piCalculatorData);
	}
	return rest;
}

DWORD WINAPI PiCalculator::PrintProgressThreadFunction(CONST LPVOID data)
{
	ProgressData* progressData = (ProgressData*)data;
	PrintProgress(progressData);
	return 0;
}

void PiCalculator::PrintProgress(ProgressData* progressData)
{
	double progress = 0;
	while (!DoubleHelper::AreEqual(progress, 100))
	{
		progress = static_cast<double>(*progressData->current) / progressData->total * 100;
		cout << "Progress: [" << MathHelper::Round<2>(progress) << "% / 100%]   \r";
		Sleep(PROGRESS_BAR_UPDATE_DURATION);
	}
}

DWORD WINAPI PiCalculator::CalculateInCirclePointCountThreadFunction(CONST LPVOID data)
{
	PiCalculatorData* piCalculatorData = (PiCalculatorData*)data;
	CalculateInCirclePointCount(piCalculatorData);
	return 0;
}

void PiCalculator::CalculateInCirclePointCount(PiCalculatorData* piCalculatorData)
{
	RandomHelper randomHelper;
	for (unsigned int i = 0; i < piCalculatorData->iterationCount; ++i)
	{
		if (IsPointInCircle(randomHelper.GetRandomVector2d(0, RADIUS)))
		{
			InterlockedIncrement(piCalculatorData->inCirclePointCount.get());
		}
		InterlockedIncrement(piCalculatorData->progressData->current.get());
	}
}

bool PiCalculator::IsPointInCircle(Vector2d const& vect)
{
	return vect.GetU() * vect.GetU() + vect.GetV() * vect.GetV() <= RADIUS * RADIUS;
}
