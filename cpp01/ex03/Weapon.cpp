#include "Weapon.hpp"

Weapon::Weapon(std::string t)
{
    type = t;
}
const std::string& Weapon::getType(void)
{
    return (type);
}

void Weapon::setType(std::string t)
{
    type = t;
}

Weapon::~Weapon(void){}