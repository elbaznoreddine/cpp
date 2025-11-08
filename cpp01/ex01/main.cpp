#include "Zombie.hpp"

int main()
{
	int N = 1;
	int i = 0; 
	Zombie* z = zombieHorde(N, "omar");
	while (i < N)
	{
		z[i].announce();
		i++;
	}
	delete []z;
}