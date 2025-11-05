#include "Zombie.hpp"

int main()
{
	int N = 1;
	int i = 0; 
	Zombie* z = zombieHorde(N, "omar");
	if (!z)
		return (1);
	while (i < N)
	{
		z[i].announce();
		i++;
	}
	delete []z;
}