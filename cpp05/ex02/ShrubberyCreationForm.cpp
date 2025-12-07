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
	std::string name_file = this->getTarget() + "_shrubbery";
	std::ofstream ofile(name_file.c_str());
	if (!ofs.is_open())
    {
        std::cerr << "Could not open file " << name_file << std::endl;
        return;
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
