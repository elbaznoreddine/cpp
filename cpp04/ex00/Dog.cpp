#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default constractor called" << std::endl;
}


Dog::Dog(const Dog &d) : Animal (d)
{
}

Dog &Dog::operator=(const Dog &d)
{
	if (this != &d)
	{
		Animal::operator=(d);
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