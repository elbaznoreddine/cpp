#include "Point.hpp"

float calcul(Point const a, Point const b, Point const c)
{
	float abc = 0.5f * fabsf(a.get_X()*(b.get_Y() - c.get_Y()) + 
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
	
	// if (!a1 || !a2 || a3)
	// 	return (1);
	std::cout << " All area = " << abc << std::endl;
	std::cout << " a1 area = " << a1 << std::endl;
	std::cout << " a2 area = " << a2 << std::endl;
	std::cout << " a3 area = " << a3 << std::endl;
	std::cout << " The 3 area = " << a1+a2+a3 << std::endl;


	if (abc == (a1 + a2 + a3))
		return (1);
	return (0);
}