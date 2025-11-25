#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private :
		Brain *brain;
	public :
		Cat();
		Cat(std::string t);
		Cat(Cat &c);
		Cat &operator=(Cat &c);
		virtual ~Cat();
		virtual void  makeSound() const;
		Brain* getBrain() const;
};