#pragma once

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class AForm;

class Intern
{
	private:
		AForm* robotomyForm(const std::string target, const std::string name);
		AForm* presidentialForm(const std::string target, const std::string name);
		AForm* shrubberyForm(const std::string target, const std::string name);
		AForm* error(const std::string target, const std::string name);

	public :
		Intern();
		Intern(const Intern& i);
		Intern &operator=(const Intern& i);
		~Intern();
		AForm* makeForm(const std::string name, const std::string target);
};