#pragma once

#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"
class Bureaucrat;
class AForm
{
	private :
		const std::string _name;
		const std::string _target;
		bool _is_sign;
		const int _gradeToSign;
		const int _gradeToExec;
	public :
		AForm();
		AForm(std::string name, int gradeToSign, int gradeToExec, std::string target);
		AForm(const AForm& f);
		AForm& operator=(const AForm& f);
		virtual ~AForm();
		std::string getName() const;
		std::string getTarget() const;
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
        class FormNotSignedException : public std::exception
        {
            public:
			const char  *what(void) const throw();
        };
		virtual void  execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& OUT, const AForm& f);