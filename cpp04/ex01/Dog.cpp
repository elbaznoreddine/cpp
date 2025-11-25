#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog default constractor called" << std::endl;
	brain = new Brain();
}

Dog::Dog(std::string t) : Animal(t)
{
	std::cout << "Dog consturtor called" << std::endl;
	this->type = t;
	brain = new Brain();
}

Dog::Dog(Dog &d) : Animal (d)
{
	std::cout << "Dog Copy Constructor called" << std::endl;
    this->brain = new Brain();
    *(this->brain) = *(d.brain);
}

Dog &Dog::operator=(Dog &d)
{
	if (this != &d)
	{
		*(this->brain) = *(d.brain);
		Animal::operator=(d);
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