#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat default constractor called" << std::endl;
}

WrongCat::WrongCat(std::string t) : WrongAnimal(t)
{
	std::cout << "WrongCat consturtor called" << std::endl;
	this->type = t;
}

WrongCat::WrongCat(WrongCat &c) : WrongAnimal (c)
{
}

WrongCat &WrongCat::operator=(WrongCat &c)
{
	if (this != &c)
	{
		WrongAnimal::operator=(c);
	}
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat sound" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat deconstructor called" << std::endl;
}