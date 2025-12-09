#pragma once

#include <iostream>
#include "AForm.hpp"
class AForm;
class Bureaucrat
{
    private :
        const std::string name;
        int grade;
    public :
        Bureaucrat();
        Bureaucrat(const std::string n, int g);
        Bureaucrat(const Bureaucrat& b);
        Bureaucrat& operator=(const Bureaucrat& b);
        ~Bureaucrat();
        const std::string getName() const ;
        int getGrade() const;
        class GradeTooHighException : public std::exception
        {
            public:
                const char  *what(void) const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char  *what(void) const throw();
        };
        void makeGrade(int g);
        void incGrade();
        void decGrade();
		void signForm(AForm& f);
		void executeForm(AForm const & form) const;
};
std::ostream &operator<<(std::ostream& OUT, const Bureaucrat& b);