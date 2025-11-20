#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), ScavTrap(), FragTrap()
{
    std::cout << "DiamondTrap default constructor called" << std::endl;
    this->name = "default";
    this->hit_points = FragTrap::hit_points;
    this->energy_points = ScavTrap::energy_points;
    this->attack_damage = FragTrap::attack_damage;
}

DiamondTrap::DiamondTrap(std::string n) : ScavTrap(n), FragTrap(n)
{
    std::cout << "DiamondTrap constructor called" << std::endl;
    this->name = n;
	ClapTrap::name = n + "_clap_name";
    this->hit_points = FragTrap::hit_points;
    this->energy_points = ScavTrap::energy_points;
    this->attack_damage = FragTrap::attack_damage;
}
DiamondTrap::DiamondTrap(const DiamondTrap& s) : ClapTrap(s), ScavTrap(s), FragTrap(s)
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    *this = s;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& s) 
{
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this != &s)
	{
		this->name = s.name;
		ClapTrap::operator=(s); 
	}
	return *this;
}
void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::takeDamage(unsigned int amount)
{
	if (DiamondTrap::hit_points == 0 || DiamondTrap::energy_points == 0 || DiamondTrap::hit_points < amount)
	{
		std::cout << "DiamondTrap can't do anything" << std::endl;
		return;
	}
	DiamondTrap::hit_points -= amount;
	std::cout << "damage taking = " << amount << std::endl;
}

void DiamondTrap::beRepaired(unsigned int amount)
{
	if (DiamondTrap::hit_points == 0 || DiamondTrap::energy_points == 0)
	{
		std::cout << "DiamondTrap can't do anything" << std::endl;
		return;
	}
	DiamondTrap::hit_points += amount;
	DiamondTrap::energy_points--;
	std::cout << "DiamondTrap repairing it self" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap's name : " << DiamondTrap::name
				<< ", ClapTrap's name : " << ClapTrap::name << std::endl;
}
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap deconstructor called" << std::endl;
}