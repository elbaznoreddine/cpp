#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>
#include <cmath>

class Fixed
{
	private :
		int value;
		static const int fractional;
	public :
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& f);
		~Fixed();
		Fixed &operator=(const Fixed &f);
		int getRawBits( void ) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};
std::ostream& operator<<(std::ostream& OUT, const Fixed& f);
#endif