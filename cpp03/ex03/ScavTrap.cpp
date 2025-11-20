#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap default constructor called" << std::endl;
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
}

ScavTrap::ScavTrap(std::string n) : ClapTrap(n)
{
    std::cout << "ScavTrap constructor called" << std::endl;
    this->name = n;
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& s) : ClapTrap(s)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}
ScavTrap& ScavTrap::operator=(const ScavTrap& s)
{
    std::cout << "ScavTrap copy assignment constructor called" << std::endl;
    if (this != &s)
    {
        ClapTrap::operator=(s);
    }
    return (*this);
}


void ScavTrap::takeDamage(unsigned int amount)
{
	if (hit_points == 0 || energy_points == 0 || hit_points < amount)
	{
		std::cout << "ScavTrap can't do anything" << std::endl;
		return;
	}
	hit_points -= amount;
	std::cout << "damage taking = " << amount << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (hit_points == 0 || energy_points == 0)
	{
		std::cout << "ScavTrap can't do anything" << std::endl;
		return;
	}
	hit_points += amount;
	energy_points--;
	std::cout << "ScavTrap repairing it self" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (hit_points == 0 || energy_points == 0)
	{
		std::cout << "ScavTrap can't do anything" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << name << " attacks " << target << " causing " << attack_damage << " points of damage! " << std::endl;
	energy_points--;
}
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap deconstructor called" << std::endl;
}