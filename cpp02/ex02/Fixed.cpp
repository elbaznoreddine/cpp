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
Fixed Fixed::operator+(const Fixed &f) const
{
	Fixed result;
	result.setRawBits(this->getRawBits() + f.getRawBits());
	return (result);
}
Fixed Fixed::operator-(const Fixed &f) const
{
	Fixed result;
	result.setRawBits(this->getRawBits() - f.getRawBits());
	return (result);
}
Fixed Fixed::operator*(const Fixed &f) const
{
	Fixed result;
	Fixed temp(this->toFloat() *   f.toFloat());
	result.setRawBits(temp.getRawBits());
	return (result);
}
Fixed Fixed::operator/(const Fixed &f) const
{
	Fixed result;
	Fixed temp(this->toFloat() / f.toFloat());
	result.setRawBits(temp.getRawBits());
	return (result);
}

bool Fixed::operator>(const Fixed &f) const
{
	return (this->getRawBits() > f.getRawBits());
}
bool Fixed::operator<(const Fixed &f) const
{
	return (this->getRawBits() < f.getRawBits());
}
bool Fixed::operator>=(const Fixed &f) const
{
	return (this->getRawBits() >= f.getRawBits());
}
bool Fixed::operator<=(const Fixed &f) const
{
	return (this->getRawBits() <= f.getRawBits());
}
bool Fixed::operator==(const Fixed &f) const
{
	return (this->getRawBits() == f.getRawBits());
}
bool Fixed::operator!=(const Fixed &f) const
{
	return (this->getRawBits() != f.getRawBits());
}
Fixed& Fixed::operator++()
{
	this->value++;
	return (*this);
}
Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->value++;
	return (temp);
}
Fixed& Fixed::operator--()
{
	this->value--;
	return (*this);
}
Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->value--;
	return (temp);
}
Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}
const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}
Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}
const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
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