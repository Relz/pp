#include "stdafx.h"
#include "Constant.h"
#include "PiCalculator.h"

using namespace std;

int main(int argc, char *argv[])
{
	size_t iterationCount = stoi(argv[1]);
	size_t threadCount = stoi(argv[2]);

	PiCalculator piCalculator(iterationCount, threadCount);

	return EXIT_SUCCESS;
}