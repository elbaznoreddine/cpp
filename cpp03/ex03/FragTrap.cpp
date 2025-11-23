#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap default constructor called" << std::endl;
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
}

FragTrap::FragTrap(std::string n) : ClapTrap(n)
{
    std::cout << "FragTrap constructor called" << std::endl;
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap& s) : ClapTrap(s)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}
FragTrap& FragTrap::operator=(const FragTrap& s)
{
    std::cout << "FragTrap copy assignment constructor called" << std::endl;
    if (this != &s)
    {
        ClapTrap::operator=(s);
    }
    return (*this);
}


void FragTrap::takeDamage(unsigned int amount)
{
	if (hit_points == 0 || energy_points == 0)
	{
		std::cout << "FragTrap can't do anything" << std::endl;
		return;
	}
	if (hit_points < amount)
		hit_points = 0;
	else
		hit_points -= amount;
	std::cout << "damage taking = " << amount << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (hit_points == 0 || energy_points == 0)
	{
		std::cout << "FragTrap can't do anything" << std::endl;
		return;
	}
	hit_points += amount;
	energy_points--;
	std::cout << "FragTrap repairing it self" << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap positive high-fives" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (hit_points == 0 || energy_points == 0)
	{
		std::cout << "FragTrap can't do anything" << std::endl;
		return;
	}
	std::cout << "FragTrap " << name << " attacks " << target << " causing " << attack_damage << " points of damage! " << std::endl;
	energy_points--;
}
FragTrap::~FragTrap()
{
    std::cout << "FragTrap deconstructor called" << std::endl;
}