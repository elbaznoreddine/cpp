#include "HumanB.hpp"

HumanB::HumanB(void){}

HumanB::HumanB(std::string n)
{
    name = n;
    weapon = NULL;
}

void HumanB::setWeapon(Weapon& w)
{
    weapon = &w;
}

void HumanB::attack(void)
{
    if (!weapon)
    {
        std::cout << name << " No Weapon to attacks with "
                    << std::endl;
        return;
    }
    std::cout << name << " attacks with their "
                << weapon->getType() << std::endl; 
}

HumanB::~HumanB(void){}