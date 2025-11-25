#pragma once 

#include <iostream>

class Animal
{
	protected :
		std::string type;
	public : 
		Animal();
		Animal(std::string t);
		Animal(Animal &a);
		Animal &operator=(Animal &a);
		virtual ~Animal();
		virtual void  makeSound() const;
		std::string getType() const;
		void setType(std::string new_type);
};