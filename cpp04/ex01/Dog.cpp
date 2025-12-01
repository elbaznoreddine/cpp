#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default constractor called" << std::endl;
	brain = new Brain();
}


Dog::Dog(Dog &d) : Animal (d)
{
	std::cout << "Dog Copy Constructor called" << std::endl;
    this->brain = NULL;
	*this = d;
}

Dog &Dog::operator=(Dog &d)
{
	if (this != &d)
	{
		Animal::operator=(d);
		delete brain;
		brain = new Brain(*d.brain);
	}
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Dog sound" << std::endl;
}

Brain* Dog::getBrain() const
{
    return this->brain;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog deconstructor called" << std::endl;
}