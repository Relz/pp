#pragma once
class Vector2d
{
public:
	Vector2d(double u = 0, double v = 0);
	
	double GetU() const;
	double GetV() const;

private:
	double m_u;
	double m_v;
};

