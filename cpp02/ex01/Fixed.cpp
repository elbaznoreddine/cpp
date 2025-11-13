#include "Fixed.hpp"

const int Fixed::fractional = 8;

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" <<std::endl;
	value = 0;
}
Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" <<std::endl;
	this->value = value << fractional;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" <<std::endl;
	this->value = roundf(value * 256);
}
Fixed::Fixed(const Fixed& f)
{
	std::cout << "Copy constructor called" <<std::endl;
	*this = f;
}
Fixed& Fixed::operator=(const Fixed& f)
{
	std::cout << "Copy assignment operator called" <<std::endl;
	this->value = f.getRawBits();
	return(*this);
}

std::ostream& operator<<(std::ostream& OUT, const Fixed& f)
{
	OUT << f.toFloat();
	return (OUT);
}

int Fixed::getRawBits() const
{
	return (value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" <<std::endl;
	this->value = raw;
}

int Fixed::toInt(void) const
{
	return (value >> fractional);
}

float Fixed::toFloat(void) const
{
	float val = value;
	return (val / 256);
}
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}