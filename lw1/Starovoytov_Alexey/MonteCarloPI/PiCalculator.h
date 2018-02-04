#pragma once
#include <iostream>
#include <windows.h>
#include <vector>
#include <memory>
#include "ThreadPool.h"
#include "RandomHelper.h"
#include "MathHelper.h"
#include "DoubleHelper.h"

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

	static DWORD WINAPI PrintProgress(CONST LPVOID data);
	static DWORD WINAPI CalculateInCirclePointCount(CONST LPVOID data);
	static bool IsPointInCircle(Vector2d const& vect);
};