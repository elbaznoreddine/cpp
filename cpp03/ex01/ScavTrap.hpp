#ifndef __SCAVTRAP_HPP__
#define __SCAVTRAP_HPP__

#include "ClapTrap.hpp"

class ScavTrap : private ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(ScavTrap& s);
        ScavTrap& operator=(ScavTrap& s);
        ~ScavTrap();
        void attack(const std::string& target);
        void guardGate();
        void takeDamage(unsigned int amount);
 		void beRepaired(unsigned int amount);
};

#endif