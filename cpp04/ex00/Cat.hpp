#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
	public :
		Cat();
		Cat(std::string t);
		Cat(Cat &a);
		Cat &operator=(Cat &a);
		~Cat();
		void  makeSound() const;
};