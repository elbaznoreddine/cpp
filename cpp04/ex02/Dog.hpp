#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private :
		Brain* brain;
	public :
		Dog();
		Dog(std::string t);
		Dog(Dog &d);
		Dog &operator=(Dog &d);
		virtual ~Dog();
		virtual void  makeSound() const;
		Brain* getBrain() const;
};