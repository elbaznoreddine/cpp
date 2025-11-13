#include "Fixed.hpp"

const int Fixed::fractional = 8;

Fixed::Fixed(void)
{
	value = 0;
	std::cout << "Default constructor called" <<std::endl;
}
Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" <<std::endl;
	this->value = value << 8;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" <<std::endl;
	this->value = value * 256;
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
	OUT << f.getRawBits();
	return (OUT);
}

int Fixed::getRawBits() const
{
	// std::cout << "getRawBits member function called" <<std::endl;
	return (value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "tRawBits member function called" <<std::endl;
	this->value = raw;
}

int Fixed::toInt(void) const
{
	return (value >> 8);
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