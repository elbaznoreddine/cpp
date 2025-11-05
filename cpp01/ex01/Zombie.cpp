#include "Zombie.hpp"

Zombie::Zombie(void){};

Zombie::Zombie(std::string n)
{
	name = n;
}

void Zombie::announce()
{
	std::cout << name << ": " << "BraiiiiiiinnnzzzZ...\n";
}
void Zombie::set_name(std::string name)
{
	this->name = name;
}
Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return (NULL);
	
	int i = 0;
	Zombie* z = new Zombie[N];
	if (!z)
	{
		std::cout << "Allocation failed" << std::endl;
		return (NULL);
	}
	while (i < N)
	{
		z[i].set_name(name);
		i++;
	}
	return (z);
}
Zombie::~Zombie(void)
{
	std::cout << name << " is destroyed\n";
}