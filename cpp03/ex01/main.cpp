#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap c("omar");
	ScavTrap sss("nor");

	ScavTrap ss(sss);

	ScavTrap s = ss;

	c.attack("khalid");
	s.attack("ziko");

	c.takeDamage(1);
	s.takeDamage(10); 

	c.beRepaired(1);
	s.beRepaired(10);

	s.guardGate();


}