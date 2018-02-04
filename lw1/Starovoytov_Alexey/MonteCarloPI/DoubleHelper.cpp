#include "DoubleHelper.h"

bool DoubleHelper::AreEqual(double lhs, double rhs)
{
	return abs(lhs - rhs) < EPSILON;
}

const double DoubleHelper::EPSILON = 0.001;
