#ifndef __HUMAN_A_HPP__
#define __HUMAN_A_HPP__

#include "Weapon.hpp"

class HumanA
{
    private :
        std::string name;
        Weapon& weapon;
    public :
        HumanA(std::string n, Weapon& w);
        void attack(void);
        ~HumanA(void);
};
#endif