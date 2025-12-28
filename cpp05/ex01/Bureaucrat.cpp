#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() :name("default"), grade(150)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string n, int g): name(n)
{
    std::cout << "Bureaucrat constructor called" << std::endl;
    makeGrade(g);
}
void Bureaucrat::makeGrade(int g)
{
    if (g > 150)
        throw Bureaucrat::GradeTooLowException();
    if (g < 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade = g;
}

Bureaucrat::Bureaucrat(const Bureaucrat& b): name(b.name)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
    *this = b;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b)
{
    std::cout << "Bureaucrat copy assingment operator called" << std::endl;
    if (this != &b)
    {
        this->grade = b.getGrade();
    }
    return (*this);
}

std::ostream& operator<<(std::ostream& OUT, const Bureaucrat& b)
{
    OUT << b.getName() << ", bureaucrat grade " << b.getGrade();
    return (OUT);
}

const std::string Bureaucrat::getName() const 
{
    return (name);
}

int Bureaucrat::getGrade() const 
{
    return (grade);
}

const char  *Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return "High Grade";
}

const char  *Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return "low Grade";
}
void Bureaucrat::incGrade()
{
    makeGrade(grade - 1);
}

void Bureaucrat::decGrade()
{
   makeGrade(grade + 1);
    
}
void Bureaucrat::signForm(Form& f)
{
	try
	{
		f.beSigned(*this);
		std::cout << *this << " signed " << f << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << *this << " couldn’t sign " << f << " because " << e.what() << std::endl;
	}
}
Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}