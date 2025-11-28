#include "AMateria.hpp"


AMateria::AMateria()
{}
AMateria::AMateria(std::string const &type)
{
    this->type = type;
}

AMateria::AMateria(const AMateria& am) : type(am.type)
{
}

AMateria &AMateria::operator=(const AMateria& am)
{
    // if (this != &am)
    // {
    //     this->type = am.type;
    // }
	(void)am;
    return (*this);
}
std::string const& AMateria::getType() const
{
    return (type);
}
void AMateria::use(ICharacter& target)
{
	std::cout << "* AMateria uses its power on " << target.getName() << " *" << std::endl;
}
AMateria::~AMateria()
{}