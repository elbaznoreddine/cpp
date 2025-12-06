#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default constractor called" << std::endl;
	brain = new Brain();
}

Dog::Dog(const Dog &d) : Animal (d)
{
	std::cout << "Dog Copy Constructor called" << std::endl;
	brain = NULL;
    *this = d;
}

Dog &Dog::operator=(const Dog &d)
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

std::string Dog::getIdea(int id)
{
    return this->brain->getIdea(id);
}

void Dog::setIdea(int id, std::string idea)
{
	this->brain->setIdea(id, idea);
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog deconstructor called" << std::endl;
}