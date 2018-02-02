#pragma once
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <windows.h>
#include <vector>

using namespace std;

struct ProgressData
{
	size_t current;
	size_t total;
};

class PiCalculator
{
public:
	explicit PiCalculator(size_t iterationCount, size_t threadCount);

	double GetPiValue() const;
	void Calculate();

private:
	static const size_t RADIUS = 1;
	static const size_t PROGRESS_BAR_UPDATE_DURATION = 1000;

	size_t m_iterationCount;
	size_t m_threadCount;

	double m_piValue;

	size_t GetInCirclePointCount() const;
	void InitRandomizer() const;
	double GetRandomCoordinateInQuarter() const;
	double GetRandomCoefficient() const;
	bool IsPointInCircle(double x, double y) const;

	static HANDLE CreateSimpleThread(LPTHREAD_START_ROUTINE threadFunction, LPVOID data);
	static DWORD WINAPI PrintProgress(CONST LPVOID lpParam);
};
