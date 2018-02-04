#pragma once
#include <cstdlib>

using namespace std;

class DoubleHelper
{
public:
	static bool AreEqual(double lhs, double rhs);

private:
	static const double EPSILON;
};

