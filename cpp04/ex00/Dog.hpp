#pragma once

#include "Animal.hpp"

class Dog : public Animal
{
	public :
		Dog();
		Dog(Dog &d);
		Dog &operator=(Dog &d);
		~Dog();
		void  makeSound() const;
};