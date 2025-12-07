#pragma once

#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;
class Form
{
	private :
		const std::string _name;
		bool _is_sign;
		const int _gradeToSign;
		const int _gradeToExec;
	public :
		Form();
		Form(std::string name, int gradeToSign, int gradeToExec);
		Form(const Form& f);
		Form& operator=(const Form& f);
		~Form();
		std::string getName() const;
		bool getSigned() const;
		int	getGradeToSign() const;
		int	getGradeToExec() const;
		void beSigned(Bureaucrat& b);
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
};

std::ostream& operator<<(std::ostream& OUT, const Form& f);