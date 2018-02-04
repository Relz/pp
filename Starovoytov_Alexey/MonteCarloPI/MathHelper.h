#pragma once
#include <cmath>

class MathHelper
{
public:
	template <unsigned int precision>
	static double Round(double number)
	{
		unsigned int a = pow(10, precision);
		return round(number * a) / a;
	}
};
