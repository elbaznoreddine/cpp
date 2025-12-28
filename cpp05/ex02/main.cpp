#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

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
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat          Doc("Doc", 40);
        Bureaucrat          Doc1("Doc", 40);
        Bureaucrat          Doc2("Doc", 40);


        RobotomyRequestForm Robot("Alfred");
        RobotomyRequestForm Robot1("Alfred");
        RobotomyRequestForm Robot2("Alfred");
        RobotomyRequestForm copy(Robot);

        std::cout << std::endl;
        std::cout << copy << std::endl;
		srand(time(NULL));
        Doc.signForm(copy);
        Doc.executeForm(copy);
        Doc1.signForm(Robot1);
        Doc1.executeForm(Robot1);
        Doc2.signForm(Robot2);
        Doc2.executeForm(Robot2);
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
    return (0);
}