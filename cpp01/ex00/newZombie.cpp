#include "Zombie.hpp"

 Zombie* newZombie( std::string name )
 {
	Zombie *z = new Zombie(name);
	if (!z)
	{
		std::cout << "Allocation failed" << std::endl;
		return (NULL);
	}
	return (z);
 }