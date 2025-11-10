#include "Zombie.hpp"

Zombie::Zombie(std::string n)
{
	name = n;
}

Zombie::Zombie(void){}

void Zombie::announce(void)
{
	std::cout << name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << name << " is destroyed" << std::endl;
}