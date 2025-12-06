#pragma once

#include "ICharacter.hpp"

class Character : public ICharacter
{
    private : 
        std::string name;
        AMateria *inventory[4];
        static AMateria* floor[100];
        static int num_floor;
		void deleteInventory();
    public :
		Character();
        Character(std::string n);
        Character(const Character &c);
        Character &operator=(const Character& c);
        ~Character();
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		static void cleanupFloor();
};