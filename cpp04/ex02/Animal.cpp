#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constractor called" << std::endl;
	type = "default type";
}

Animal::Animal(std::string t)
{
	std::cout << "Animal consturtor called" << std::endl;
	this->type = t;
}

Animal::Animal(const Animal &a)
{
	*this = a;
}

Animal &Animal::operator=(const Animal &a)
{
	if (this != &a)
	{
		this->type = a.type;
	}
	return (*this);
}
std::string Animal::getType() const
{
	return (type);
}

void Animal::setType(std::string new_type)
{
	this->type = new_type;
}

Animal::~Animal()
{
	std::cout << "Animal deconstructor called" << std::endl;
}