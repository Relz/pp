#include "RandomHelper.h"

RandomHelper::RandomHelper()
{
	InitRandomizer();
}

Vector2d RandomHelper::GetRandomVector2d(double from, double to) const
{
	return Vector2d(GetRandom(from, to), GetRandom(from, to));
}

void RandomHelper::InitRandomizer() const
{
	srand(static_cast<unsigned int>(time(0)));
}

double RandomHelper::GetRandom(double from, double to) const
{
	return static_cast<double>(rand()) / RAND_MAX * (to - from) + from;
}
