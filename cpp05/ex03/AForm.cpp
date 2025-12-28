#include "AForm.hpp"

AForm::AForm() : _name("default"), _target("Default"), _is_sign(false), _gradeToSign(150), _gradeToExec(150)
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExec, std::string target) : _name(name), _target(target), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	std::cout << "AForm Constructor called" << std::endl;
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

AForm::AForm(const AForm &f) : _name(f._name), _target(f._target), _gradeToSign(f._gradeToSign), _gradeToExec(f._gradeToExec)
{
	std::cout << "AForm copy constructor called" << std::endl;
	*this = f; 
}

AForm& AForm::operator=(const AForm& f)
{
	std::cout << "AForm assignement operator called" << std::endl;
	if (this != &f)
	{
		this->_is_sign = f._is_sign;
	}
	return (*this);
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

std::string AForm::getName() const
{
	return (_name);
}

std::string AForm::getTarget() const
{
	return (_target);
}

bool AForm::getSigned() const
{
	return (_is_sign);
}

int AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int AForm::getGradeToExec() const
{
	return (_gradeToExec);
}

const char  *AForm::GradeTooHighException::what(void) const throw()
{
    return "High Grade";
}

const char  *AForm::GradeTooLowException::what(void) const throw()
{
    return "low Grade";
}

const char  *AForm::FormNotSignedException::what(void) const throw()
{
    return "form not signed";
}

void AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	_is_sign = true;
}

std::ostream& operator<<(std::ostream& OUT, const AForm& f)
{
	OUT << f.getName() << ", require grade to sign = " << f.getGradeToSign()
		<< ", require grade to execute = " << f.getGradeToExec()
		<< ", signed = " << f.getSigned();
	return (OUT);
}