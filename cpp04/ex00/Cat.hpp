#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
	public :
		Cat();
		Cat(std::string t);
		Cat(Cat &c);
		Cat &operator=(Cat &c);
		~Cat();
		void  makeSound() const;
};