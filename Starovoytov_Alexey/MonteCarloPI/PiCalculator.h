#pragma once
#include <iostream>
#include <windows.h>
#include <vector>
#include <unordered_map>
#include "ThreadPool.h"
#include "RandomHelper.h"
#include "MathHelper.h"
#include "DoubleHelper.h"

using namespace std;

struct ProgressData
{
	unsigned int *current;
	unsigned int total;
};

struct PiCalculatorData
{
	unsigned int *inCirclePointCount;
	unsigned int iterationCount;
	ProgressData *progressData;
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
