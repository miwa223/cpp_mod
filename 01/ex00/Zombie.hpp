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
		void	setName( std::string );
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif
