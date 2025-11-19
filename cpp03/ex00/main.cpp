#include "ClapTrap.hpp"

int main()
{
	ClapTrap c;
	ClapTrap c1("c1");
	ClapTrap c2 ("c2");

	c.attack("khalid");
	c1.attack("khalid");
	c2.attack("khalid");

	c.takeDamage(1);
	c1.takeDamage(1);
	c2.takeDamage(1);

	c.beRepaired(1);
	c1.beRepaired(1);
	c2.beRepaired(1);



}