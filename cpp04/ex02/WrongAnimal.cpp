#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal default constractor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string t)
{
	std::cout << "WrongAnimal consturtor called" << std::endl;
	this->type = t;
}

WrongAnimal::WrongAnimal(WrongAnimal &a)
{
	*this = a;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal &a)
{
	if (this != &a)
	{
		this->type = a.type;
	}
	return (*this);
}
std::string WrongAnimal::getType() const
{
	return (type);
}

void WrongAnimal::setType(std::string new_type)
{
	this->type = new_type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal deconstructor called" << std::endl;
}