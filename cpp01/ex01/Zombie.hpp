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
		void set_name(std::string name);
		void announce( void );
		~Zombie();
};
Zombie* zombieHorde( int N, std::string name );
#endif