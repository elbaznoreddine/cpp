#ifndef __WEAPON_HPP__
#define __WEAPON_HPP__

#include <iostream>

class Weapon
{
    private :
        std::string type;
    public :
        Weapon(void);
        Weapon(std::string t);
        const std::string& getType(void);
        void setType(std::string t);
        ~Weapon(void);
};
#endif