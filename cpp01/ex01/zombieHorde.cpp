#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return (NULL);
	
	int i = 0;
	Zombie* z = new Zombie[N];
	while (i < N)
	{
		z[i].set_name(name);
		i++;
	}
	return (z);
}