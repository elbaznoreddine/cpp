#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public :
		WrongCat();
		WrongCat(std::string t);
		WrongCat(const WrongCat &a);
		WrongCat &operator=(const WrongCat &a);
		~WrongCat();
		void  makeSound() const;
};