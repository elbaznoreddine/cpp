#include "Zombie.hpp"

int main()
{
	Zombie z = Zombie("foo");
	Zombie z1 = Zombie("Bar");
	Zombie *z2 = newZombie("test1");
	z.announce();
	z1.announce();
	z2->announce();
	randomChump("test2");
	delete z2;

}