#pragma once

#include "Animal.hpp"

class Dog : public Animal
{
	public :
		Dog();
		Dog(std::string t);
		Dog(Dog &a);
		Dog &operator=(Dog &a);
		~Dog();
		void  makeSound() const;
};