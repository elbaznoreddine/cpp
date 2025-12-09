#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("Robotomy Request Form", 72, 45, "default")
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy Request Form", 72, 45, target)
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	std::cout << "RobotomyRequestForm copy assignement operator called" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
		{throw AForm::FormNotSignedException();}
    if (executor.getGrade() > this->getGradeToExec())
        {throw AForm::GradeTooLowException();}
	std::cout << "ZNNNNNNNNNNNNNN" << std::endl;

    if (rand() % 2 == 0)
    {
        std::cout << this->getTarget() << " has been successfully robotomized." << std::endl;
    }
    else
    {
        std::cout << "The robotomy of " << this->getTarget() << " failed." << std::endl;
    }
}
