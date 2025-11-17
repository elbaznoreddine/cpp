#include "Fixed.hpp"

const int Fixed::fractional = 8;

Fixed::Fixed(void)
{
	value = 0;
}
Fixed::Fixed(const int value)
{
	this->value = value << fractional;
}

Fixed::Fixed(const float value)
{
	this->value = roundf(value * 256);
}
Fixed::Fixed(const Fixed& f)
{
	*this = f;
}
Fixed& Fixed::operator=(const Fixed& f)
{
	if (this != &f)
		this->value = f.getRawBits();
	return(*this);
}
Fixed Fixed::operator+(const Fixed &f) const
{
	return (Fixed(this->toFloat() + f.toFloat()));
}
Fixed Fixed::operator-(const Fixed &f) const
{
	return (Fixed(this->toFloat() - f.toFloat()));
}
Fixed Fixed::operator*(const Fixed &f) const
{
	return (Fixed(this->toFloat() * f.toFloat()));
}
Fixed Fixed::operator/(const Fixed &f) const
{
	return (Fixed(this->toFloat() / f.toFloat()));
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
}