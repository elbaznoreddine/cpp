#include "Character.hpp"


AMateria* Character::floor[100] = {NULL};

int Character::num_floor = 0;

Character::Character() : name("Default")
{
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
}

Character::Character(std::string n) : name(n)
{
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
}

Character::Character(const Character &c) : name(c.name)
{
    for(int i = 0; i < 4; i++)
    {
        if (c.inventory[i])
            this->inventory[i] = c.inventory[i]->clone();
        else
            this->inventory[i] = NULL;
    }
}

Character &Character::operator=(const Character &c)
{
    if (this != &c)
    {
        this->name = c.name;
        for (size_t i = 0; i < 4; i++)
        {
            if (inventory[i])
            {
                delete inventory[i];
                inventory[i] = NULL;
            }
        }
        for (size_t j = 0; j < 4; j++)
        {
            if (c.inventory[j])
                inventory[j] = c.inventory[j]->clone();
            else
                inventory[j] = NULL;
        }
    }
    return (*this);
}

Character::~Character()
{
    for (size_t i = 0; i < 4; i++)
    {
        if (inventory[i])
            delete inventory[i];
        inventory[i] = NULL;
    }
}

std::string const &Character::getName() const
{
    return (name);
}

void Character::equip(AMateria *m)
{
    if (!m)
        return;
    for (size_t i = 0; i < 4; i++)
    {
        if (!inventory[i]) 
        {
            for (size_t j = 0; j < i; j++)
            {
                if (inventory[j] == m)
                    return;
            }
            
            inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx)
{
   if (idx >= 0 && idx < 4 && inventory[idx])
   {
        if (num_floor < 100)
        {
            floor[num_floor++] = inventory[idx];
        }
        inventory[idx] = NULL;
   }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && inventory[idx])
    {
        inventory[idx]->use(target);
    }
}

int Character::getNum()
{
    return num_floor;
}

AMateria* Character::getFloor()
{
    return *floor;
}
