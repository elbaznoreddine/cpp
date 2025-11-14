#ifndef __POINT_HPP__
#define __POINT_HPP__

#include "Fixed.hpp"

class Point
{
	private :
		const Fixed x;
		const Fixed y;
	public :
		Point(void);
		Point(const float x, const float y);
		Point(const Point& p);
		Point &operator=(const Point& p);
		~Point(void);
		float get_X(void) const;
		float get_Y(void) const;
};
bool bsp( Point const a, Point const b, Point const c, Point const point);
#endif