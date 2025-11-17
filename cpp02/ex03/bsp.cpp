#include "Point.hpp"

float my_abs(float x)
{
	if (x < 0)
		return (x * -1);
	return (x);
}
float calcul(Point const a, Point const b, Point const c)
{
	float abc = 0.5f * my_abs(a.get_X()*(b.get_Y() - c.get_Y()) + 
							b.get_X()*(c.get_Y() - a.get_Y()) +
							c.get_X()*(a.get_Y() - b.get_Y()));
	return (abc);
}
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float abc = calcul(a, b, c);
	float a1 = calcul(a, point, c);
	float a2 = calcul(point, a, b);
	float a3 = calcul(b, point, c);
	
	if (!a1 || !a2 || !a3)
		return (0);
	if (abc == (a1 + a2 + a3))
		return (1);
	return (0);
}