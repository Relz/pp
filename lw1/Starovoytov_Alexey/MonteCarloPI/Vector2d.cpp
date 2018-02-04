#include "Vector2d.h"

Vector2d::Vector2d(double u, double v)
{
	m_u = u;
	m_v = v;
}

double Vector2d::GetU() const
{
	return m_u;
}

double Vector2d::GetV() const
{
	return m_v;
}
