#include "Fixed.hpp"

const int Fixed::fractional = 8;

Fixed::Fixed(void)
{
	value = 0;
	std::cout << "Default constructor called" <<std::endl;
}
Fixed::Fixed(const Fixed& f)
{
	std::cout << "Copy constructor called" <<std::endl;
	*this = f;
}
Fixed& Fixed::operator=(const Fixed& f)
{
	std::cout << "Copy assignment operator called" <<std::endl;
	if (this != &f)
		this->value = f.getRawBits();
	return(*this);
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" <<std::endl;
	return (value);
}
void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" <<std::endl;
	this->value = raw;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}