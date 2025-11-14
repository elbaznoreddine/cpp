#include <iostream>
#include "Point.hpp"

int main( void )
{
	Point a(0, 10);
	Point b(0, 0);
	Point c(5, 0);
	
	Point p(3.99f, 2);
	std::cout << "p inside ?" << bsp(a, b, c, p) << std::endl;

	return 0;
}