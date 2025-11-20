#ifndef __FRAGTRAP_HPP__
#define __FRAGTRAP_HPP__

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap& s);
        FragTrap& operator=(const FragTrap& s);
        ~FragTrap();
        void attack(const std::string& target);
        void highFivesGuys(void);
        void takeDamage(unsigned int amount);
 		void beRepaired(unsigned int amount);
};

#endif