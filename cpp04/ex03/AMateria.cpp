#include "AMateria.hpp"


AMateria::AMateria()
{}
AMateria::AMateria(std::string const &type)
{
    this->type = type;
}

AMateria::AMateria(const AMateria& am)
{
    *this = am;
}

AMateria &AMateria::operator=(const AMateria& am)
{
    if (this != &am)
    {
        this->type = am.type;
    }
    return (*this);
}
std::string const& AMateria::getType() const
{
    return (type);
}
AMateria::~AMateria(){}