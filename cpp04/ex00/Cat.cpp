#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat default constractor called" << std::endl;
}

Cat::Cat(std::string t) : Animal(t)
{
	std::cout << "Cat consturtor called" << std::endl;
	this->type = t;
}

Cat::Cat(Cat &c) : Animal (c)
{
}

Cat &Cat::operator=(Cat &c)
{
	if (this != &c)
	{
		Animal::operator=(c);
	}
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Cat sound" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat deconstructor called" << std::endl;
}