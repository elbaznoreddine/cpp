#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery Creation Form", 145, 137, "default")
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrubbery Creation Form", 145, 137, target)
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	std::cout << "ShrubberyCreationForm copy assignement operator called" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
        {throw AForm::FormNotSignedException();}
    if (executor.getGrade() > this->getGradeToExec())
        {throw AForm::GradeTooLowException();}
	std::string name_file = this->getTarget() + "_shrubbery";
	std::ofstream ofile(name_file.c_str());
	if (!ofile.is_open())
    {
		throw std::ios_base::failure("Could not open file");
    }
	ofile <<
			"              v .   ._, |_  .,\n"
			"           `-._\\/  .  \\ /    |/_\n"
			"               \\\\  _\\, y | \\\\\n"
			"         _\\_.___\\\\, \\\\/ -.\\||\n"
			"           `7-,--.`._||  / / ,\n"
			"           /'     `-. `./ / |/_.'\n"
			"                     |    |//\n"
			"                     |_    /\n"
			"                     |-   |\n"
			"                     |   =|\n"
			"                     |    |\n"
			"--------------------/ ,  . \\--------._\n"
			<< std::endl;
	ofile.close();
}
