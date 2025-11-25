#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog default constractor called" << std::endl;
}

Dog::Dog(std::string t) : Animal(t)
{
	std::cout << "Dog consturtor called" << std::endl;
	this->type = t;
}

Dog::Dog(Dog &a) : Animal (a)
{
}

Dog &Dog::operator=(Dog &a)
{
	if (this != &a)
	{
		Animal::operator=(a);
	}
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Dog sound" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog deconstructor called" << std::endl;
}