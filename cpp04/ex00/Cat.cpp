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

Cat::Cat(Cat &a) : Animal (a)
{
}

Cat &Cat::operator=(Cat &a)
{
	if (this != &a)
	{
		Animal::operator=(a);
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