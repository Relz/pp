#pragma once
#include <iostream>
#include <windows.h>
#include <vector>
#include "ThreadPool.h"
#include "RandomHelper.h"
#include "RoundHelper.h"

using namespace std;

struct ProgressData
{
	unsigned int current;
	unsigned int total;
};

class PiCalculator
{
public:
	explicit PiCalculator(unsigned int iterationCount, unsigned int threadCount);

	double GetPiValue() const;
	void Calculate();

private:
	static const unsigned int RADIUS = 1;
	static const unsigned int PROGRESS_BAR_UPDATE_DURATION = 1000;

	unsigned int m_iterationCount;
	unsigned int m_threadCount;

	double m_piValue;

	unsigned int GetInCirclePointCount() const;
	bool IsPointInCircle(Vector2d const& vect) const;

	static DWORD WINAPI PrintProgress(CONST LPVOID lpParam);
};
