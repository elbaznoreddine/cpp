#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain Default Constructor called" << std::endl;
    for (int i = 0; i < 100; ++i)
    {
        this->ideas[i] = std::string("Initial idea");
    }
}
std::string Brain::getIdea(int index)
{
    if (index >= 0 && index < 100)
        return this->ideas[index];
    return this->ideas[0]; 
}

void Brain::setIdea(int index, std::string idea)
{
    if (index >= 0 && index < 100)
        this->ideas[index] = idea;
}

Brain::~Brain()
{
    std::cout << "Brain Destructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
    std::cout << "Brain Copy Constructor called" << std::endl;
    for (int i = 0; i < 100; ++i)
    {
        this->ideas[i] = other.ideas[i];
    }
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Brain Assignment Operator called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; ++i)
        {
            this->ideas[i] = other.ideas[i];
        }
    }
    return *this;
}
