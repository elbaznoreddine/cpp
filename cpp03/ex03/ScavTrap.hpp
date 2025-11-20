#ifndef __SCAVTRAP_HPP__
#define __SCAVTRAP_HPP__

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& s);
        ScavTrap& operator=(const ScavTrap& s);
        ~ScavTrap();
        void attack(const std::string& target);
        void guardGate();
        void takeDamage(unsigned int amount);
 		void beRepaired(unsigned int amount);
};

#endif