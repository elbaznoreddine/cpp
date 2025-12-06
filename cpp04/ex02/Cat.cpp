#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default constractor called" << std::endl;
	brain = new Brain();
}


Cat::Cat(const Cat &c) : Animal (c)
{
	std::cout << "Cat Copy Constructor called" <<std::endl;
	brain = NULL;
	*this = c;
}

Cat &Cat::operator=(const Cat &c)
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

std::string Cat::getIdea(int id)
{
    return this->brain->getIdea(id);
}
void Cat::setIdea(int id, std::string idea)
{
	this->brain->setIdea(id, idea);
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat deconstructor called" << std::endl;
}