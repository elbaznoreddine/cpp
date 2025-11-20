#ifndef __DIAMONDTRAP_HPP__
#define __DIAMONDTRAP_HPP__

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private :
		std::string name;
    public :
        DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap& s);
        DiamondTrap& operator=(const DiamondTrap& s);
        ~DiamondTrap();
        void attack(const std::string& target);
		void whoAmI();
        void takeDamage(unsigned int amount);
 		void beRepaired(unsigned int amount);
};

#endif