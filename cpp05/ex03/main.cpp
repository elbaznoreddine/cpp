#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    try
    {
        Bureaucrat              Alfred("Alfred", 10);
        ShrubberyCreationForm   Plant("Garden");
        ShrubberyCreationForm   copy(Plant);
        std::cout << std::endl;
        std::cout << copy << std::endl;
        Alfred.signForm(copy);
        Alfred.executeForm(copy);
    }
    catch( std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat          Doc("Doc", 40);
        RobotomyRequestForm Robot("Alfred");
        RobotomyRequestForm copy(Robot);
        std::cout << std::endl;
        std::cout << copy << std::endl;
        srand(time(NULL));
        Doc.signForm(copy);
        Doc.executeForm(copy);
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat              President("President", 5);
        PresidentialPardonForm  Fool("The Fool");
        PresidentialPardonForm  copy(Fool);
        std::cout << std::endl;
        std::cout << copy << std::endl;
        President.signForm(copy);
        President.executeForm(copy);
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {    
        Bureaucrat  Alfred("Alfred", 5);
        Intern  intern;
        Intern  copy(intern);
        AForm* form1 = copy.makeForm("shrubbery creation", "Garden");
        if (form1)
        {
            std::cout << "Shrubbery form created successfully" << std::endl;
            Alfred.signForm(*form1);
            Alfred.executeForm(*form1);
            delete (form1);
        }
        AForm* form2 = intern.makeForm("robotomy request", "Bender");
        if (form2)
        {
            std::cout << "Robotomy form created successfully" << std::endl;
            Alfred.signForm(*form2);
            Alfred.executeForm(*form2);
            delete (form2);
        }
        AForm* form3 = intern.makeForm("presidential pardon", "Fool");
        if (form3)
        {
            std::cout << "Presidential form created successfully" << std::endl;
            Alfred.signForm(*form3);
            Alfred.executeForm(*form3);
            delete (form3);
        }
        AForm* form4 = intern.makeForm("invalid Form", "Target");
        if (!form4)
            std::cout << "Invalid form" << std::endl;
        
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}