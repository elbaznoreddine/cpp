#include <iostream>
#include "Point.hpp"

int main( void )
{
	Point a(0, 10);
	Point b(0, 0);
	Point c(5, 0);
	Point d;
	Point p(1.25f, 8);
	d = p;
	std::cout << "P("<< p.get_X()<<", " << p.get_Y() << ")"<< bsp(a, b, c, p) << std::endl;

	return 0;
}