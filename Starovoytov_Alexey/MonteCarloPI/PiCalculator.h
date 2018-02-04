#pragma once
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <windows.h>
#include <vector>
#include "ThreadPool.h"

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
	void InitRandomizer() const;
	double GetRandomCoordinateInQuarter() const;
	double GetRandomCoefficient() const;
	bool IsPointInCircle(double x, double y) const;

	static DWORD WINAPI PrintProgress(CONST LPVOID lpParam);
};
