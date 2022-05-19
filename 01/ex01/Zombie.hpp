#ifndef _ZOMBIE_H_
#define _ZOMBIE_H_

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string	name;
	public:
		Zombie();
		~Zombie();
		void	announce( void );
		void	setName( std::string new_name );
};

Zombie*	zombieHorde( int N, std::string name );

#endif
