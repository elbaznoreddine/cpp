#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain Default Constructor called" << std::endl;
    for (int i = 0; i < NUM_IDEAS; ++i) {
        this->ideas[i] = std::string("Initial thought ");
    }
}
const std::string& Brain::getIdea(int index) const
{
    if (index >= 0 && index < NUM_IDEAS)
        return this->ideas[index];
    return this->ideas[0]; 
}

void Brain::setIdea(int index, const std::string& idea)
{
    if (index >= 0 && index < NUM_IDEAS)
        this->ideas[index] = idea;
}

Brain::~Brain()
{
    std::cout << "Brain Destructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
    std::cout << "Brain Copy Constructor called" << std::endl;
    for (int i = 0; i < NUM_IDEAS; ++i) {
        this->ideas[i] = other.ideas[i];
    }
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Brain Assignment Operator called" << std::endl;
    if (this != &other) {
        for (int i = 0; i < NUM_IDEAS; ++i) {
            this->ideas[i] = other.ideas[i];
        }
    }
    return *this;
}
