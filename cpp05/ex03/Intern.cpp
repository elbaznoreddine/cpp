#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& i)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = i;
}

Intern &Intern::operator=(const Intern& i)
{
	std::cout << "Intern copy assignement operator called" << std::endl;
	if (this != &i)
	{
		return (*this);
	}
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

AForm* Intern::presidentialForm(const std::string target, const std::string name)
{
	std::cout << "Intern creates " << name << std::endl;
	return(new PresidentialPardonForm(target));
}
AForm* Intern::robotomyForm(const std::string target, const std::string name)
{
	std::cout << "Intern creates " << name << std::endl;
	return(new RobotomyRequestForm(target));
}
AForm* Intern::shrubberyForm(const std::string target, const std::string name)
{
	std::cout << "Intern creates " << name << std::endl;
	return(new ShrubberyCreationForm(target));
}

AForm* Intern::error(const std::string target, const std::string name)
{
	(void)target;
	throw std::invalid_argument("Form's name : '" + name + "' invalid");
}

AForm* Intern::makeForm(const std::string name, const std::string target)
{

    AForm* (Intern::*ptr[])(const std::string, const std::string) =
	{
        &Intern::error, 
        &Intern::presidentialForm, 
        &Intern::robotomyForm,
        &Intern::shrubberyForm
    };
    int i = (((name == "presidential pardon") * 1) + 
              ((name == "robotomy request") * 2) +
              ((name == "shrubbery creation") * 3));
    return (this->*ptr[i])(target, name); 
}