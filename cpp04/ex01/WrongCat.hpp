#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public :
		WrongCat();
		WrongCat(std::string t);
		WrongCat(WrongCat &a);
		WrongCat &operator=(WrongCat &a);
		~WrongCat();
		void  makeSound() const;
};