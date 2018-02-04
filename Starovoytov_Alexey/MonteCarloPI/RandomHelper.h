#pragma once
#include <ctime>
#include <stdlib.h>
#include "Vector2d.h"

class RandomHelper
{
public:
	explicit RandomHelper();
	Vector2d GetRandomVector2d(double from, double to) const;
private:
	void InitRandomizer() const;
	double GetRandom(double from, double to) const;
};

