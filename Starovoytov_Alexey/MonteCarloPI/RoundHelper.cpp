#include "RoundHelper.h"
#include <cmath>

double RoundHelper::Round2(double number)
{
	return round(number * 100) / 100;
}
