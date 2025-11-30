#include "Character.hpp"


AMateria* Character::floor[100] = {NULL};

int Character::num_floor = 0;


void Character::deleteInventory()
{
    for (int i = 0; i < 4; i++)
	{
        if (this->inventory[i] != NULL)
		{
            delete this->inventory[i];
            this->inventory[i] = NULL;
        }
    }
}
void Character::cleanupFloor()
{
    for (int i = 0; i < num_floor; i++)
	{
        if (floor[i] != NULL)
		{
            delete floor[i];
            floor[i] = NULL;
        }
    }
    num_floor = 0;
}
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
	 for (int j = 0; j < 4; j++)
        this->inventory[j] = NULL;
    for(int i = 0; i < 4; i++)
    {
        if (c.inventory[i])
            this->inventory[i] = c.inventory[i]->clone();
    }
}

Character &Character::operator=(const Character &c)
{
    if (this != &c)
    {
        this->name = c.name;
        deleteInventory();
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
    deleteInventory();
}

std::string const &Character::getName() const
{
    return (name);
}

void Character::equip(AMateria *m)
{
    if (!m)
        return;
   for (int j = 0; j < 4; j++)
   {
        if (inventory[j] == m)
            return;
    }
    for (int i = 0; i < 4; i++)
	{
        if (!inventory[i])
		{
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

int Character::getNFloor()
{
    return num_floor;
}
