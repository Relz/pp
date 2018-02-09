#pragma once
#include "DoubleHelper.h"
#include "MathHelper.h"
#include "RandomHelper.h"
#include "ThreadPool.h"
#include <iostream>
#include <memory>
#include <vector>
#undef min
#undef max
#include <windows.h>

using namespace std;

struct ProgressData
{
	shared_ptr<unsigned int> current;
	unsigned int total;
};

struct PiCalculatorData
{
	shared_ptr<unsigned int> inCirclePointCount;
	unsigned int iterationCount;
	shared_ptr<ProgressData> progressData;
};

class PiCalculator
{
public:
	explicit PiCalculator(unsigned int iterationCount, unsigned int threadCount);

	double GetPiValue() const;
	void Calculate();

private:
	static const unsigned int RADIUS = 1;
	static const unsigned int PROGRESS_BAR_UPDATE_DURATION = 100;

	unsigned int m_iterationCount;
	unsigned int m_threadCount;

	double m_piValue;

	unsigned int GetInCirclePointCount() const;
	unsigned int CalculateInThreads(ThreadPool& threadPool, vector<shared_ptr<PiCalculatorData>>& piCalculatorDataPointers, shared_ptr<unsigned int> const& inCirclePointCount, shared_ptr<ProgressData> const& progressData) const;

	static DWORD WINAPI PrintProgressThreadFunction(CONST LPVOID data);
	static void PrintProgress(ProgressData* progressData);
	static DWORD WINAPI CalculateInCirclePointCountThreadFunction(CONST LPVOID data);
	static void CalculateInCirclePointCount(PiCalculatorData* piCalculatorData);
	static bool IsPointInCircle(Vector2d const& vect);
};
