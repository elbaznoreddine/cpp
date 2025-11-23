#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name(""), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string n): name(n), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &c)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = c;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& c)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &c)
	{
		name = c.name;
		hit_points =c.hit_points;
		energy_points = c.energy_points;
		attack_damage = c.attack_damage;
	}
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (hit_points == 0 || energy_points == 0)
	{
		std::cout << "ClapTrap can't do anything" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << name << " attacks " << target << " causing " << attack_damage << " points of damage! " << std::endl;
	energy_points--;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (hit_points == 0 || energy_points == 0)
	{
		std::cout << "ClapTrap can't do anything" << std::endl;
		return;
	}
	if (hit_points < amount)
		hit_points = 0;
	else
		hit_points -= amount;
	std::cout << "damage taking = " << amount << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hit_points == 0 || energy_points == 0)
	{
		std::cout << "ClapTrap can't do anything" << std::endl;
		return;
	}
	hit_points += amount;
	energy_points--;
	std::cout << "ClapTrap repairing it self" << std::endl;
}
ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called" << std::endl;
}