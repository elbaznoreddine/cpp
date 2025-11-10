#include "Zombie.hpp"

Zombie::Zombie(void){};

Zombie::Zombie(std::string n)
{
	name = n;
}

void Zombie::announce(void)
{
	std::cout << name << ": " << "BraiiiiiiinnnzzzZ...\n";
}
void Zombie::set_name(std::string name)
{
	this->name = name;
}

Zombie::~Zombie(void)
{
	std::cout << name << " is destroyed\n";
}