#pragma once 

#include <iostream>

class WrongAnimal
{
	protected :
		std::string type;
	public : 
		WrongAnimal();
		WrongAnimal(std::string t);
		WrongAnimal(const WrongAnimal &a);
		WrongAnimal &operator=(const WrongAnimal &a);
		virtual ~WrongAnimal();
		void  makeSound() const;
		std::string getType() const;
		void setType(std::string new_type);
};