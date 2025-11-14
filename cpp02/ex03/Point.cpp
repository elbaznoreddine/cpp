#include "Point.hpp"

Point::Point(void){}

Point::Point(const float x, const float y):x(Fixed(x)), y(Fixed(y)){}

Point::Point(const Point& p) : x(p.x), y(p.y){}

Point& Point::operator=(const Point& p)
{
	*this = p;
	return(*this);
}

float Point::get_X(void) const
{
	return (x.toFloat());
}

float Point::get_Y(void) const
{
	return (y.toFloat());
}

Point::~Point(void){}


