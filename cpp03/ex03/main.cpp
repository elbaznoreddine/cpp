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
	DiamondTrap dd(d);

	dd.attack("abdo");
	dd.takeDamage(10);
	dd.beRepaired(20);
	dd.whoAmI();



}