#include "Form.hpp"

Form::Form() : _name("default"), _is_sign(false), _gradeToSign(150), _gradeToExec(150)  
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExec) : 
_name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	std::cout << "Form Constructor called" << std::endl;
	_is_sign = false;
	if (_gradeToSign > 150)
        throw ( GradeTooLowException() );
    if (_gradeToSign < 1)
        throw ( GradeTooHighException() );
    
    if (_gradeToExec > 150)
        throw ( GradeTooLowException() );
    if (_gradeToExec < 1)
        throw ( GradeTooHighException() );
}

Form::Form(const Form &f) : 
_name(f._name), _gradeToSign(f._gradeToSign), _gradeToExec(f._gradeToExec)
{
	std::cout << "Form copy constructor called" << std::endl;
	*this = f; 
}

Form& Form::operator=(const Form& f)
{
	std::cout << "Form assignement operator called" << std::endl;
	if (this != &f)
	{
		this->_is_sign = f._is_sign;
	}
	return (*this);
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

std::string Form::getName() const
{
	return (_name);
}

bool Form::getSigned() const
{
	return (_is_sign);
}

int Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int Form::getGradeToExec() const
{
	return (_gradeToExec);
}
const char  *Form::GradeTooHighException::what(void) const throw()
{
    return "High Grade";
}

const char  *Form::GradeTooLowException::what(void) const throw()
{
    return "low Grade";
}
void Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	_is_sign = true;
}

std::ostream& operator<<(std::ostream& OUT, const Form& f)
{
	OUT << f.getName() << ", require grade to sign = " << f.getGradeToSign()
		<< ", require grade to execute = " << f.getGradeToExec()
		<< ", signed = " << f.getSigned();
	return (OUT);
}