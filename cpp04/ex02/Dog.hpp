#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private :
		Brain* brain;
	public :
		Dog();
		Dog(const Dog &d);
		Dog &operator=(const Dog &d);
		~Dog();
		void  makeSound() const;
		std::string getIdea(int id);
		void setIdea(int id, std::string idea);
};