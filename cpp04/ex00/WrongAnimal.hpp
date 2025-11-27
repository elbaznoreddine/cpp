#pragma once 

#include <iostream>

class WrongAnimal
{
	protected :
		std::string type;
	public : 
		WrongAnimal();
		WrongAnimal(std::string t);
		WrongAnimal(WrongAnimal &a);
		WrongAnimal &operator=(WrongAnimal &a);
		virtual ~WrongAnimal();
		void  makeSound() const;
		std::string getType() const;
		void setType(std::string new_type);
};