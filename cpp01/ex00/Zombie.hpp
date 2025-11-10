#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__

#include <iostream>
#include <new>

class Zombie
{
	private :
		std::string name;
	public :
		Zombie(void);
		Zombie(std::string name);
		void announce( void );
		~Zombie(void);
};
Zombie* newZombie( std::string name );
void randomChump( std::string name);
#endif