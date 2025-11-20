#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	ClapTrap c("omar");
	ScavTrap s("nor");
	FragTrap f("avatar");
	DiamondTrap d("ziko");

	d.attack("CHEL7");
	d.takeDamage(10);
	d.beRepaired(20);
	d.whoAmI();



}