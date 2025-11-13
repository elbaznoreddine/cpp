#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>

class Fixed
{
	private :
		int value;
		static const int fractional;
	public :
		Fixed();
		Fixed(const Fixed& f);
		~Fixed();
		Fixed &operator=(const Fixed &f);
		int getRawBits( void ) const;
		void setRawBits(int const raw);

};

#endif