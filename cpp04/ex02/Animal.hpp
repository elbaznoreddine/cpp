#pragma once 

#include <iostream>

class Animal
{
	protected :
		std::string type;
	public : 
		Animal();
		Animal(std::string t);
		Animal(const Animal &a);
		Animal &operator=(const Animal &a);
		virtual ~Animal();
		virtual void  makeSound() const = 0;
		std::string getType() const;
		void setType(std::string new_type);
};