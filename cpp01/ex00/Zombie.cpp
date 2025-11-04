#include "Zombie.hpp"

Zombie::Zombie(std::string n)
{
	name = n;
}

void Zombie::announce()
{
	std::cout << name << ": " << "BraiiiiiiinnnzzzZ...\n";
}

Zombie::~Zombie(void)
{
	std::cout << name << " is destroyed\n";
}