#include "Point.hpp"

int main( void )
{
	Point a(0, 0);
	Point b(4, 0);
	Point c(0, 10);
	Point d;
	Point p(0.19f, 7.005f);
	d = p;
	std::cout << " the point : "<< bsp(a, b, c, p) << std::endl;

	return 0;
}