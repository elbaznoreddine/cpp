#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default constractor called" << std::endl;
	brain = new Brain();
}

Cat::Cat(Cat &c) : Animal (c)
{
	std::cout << "Cat Copy Constructor called" <<std::endl;
	this->brain = NULL;
	*this = c;
}

Cat &Cat::operator=(Cat &c)
{
	if (this != &c)
	{
		Animal::operator=(c);
		delete brain;
		brain = new Brain(*c.brain);
	}
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Cat sound" << std::endl;
}

Brain* Cat::getBrain() const {
    return this->brain;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat deconstructor called" << std::endl;
}