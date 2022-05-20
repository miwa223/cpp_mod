#ifndef _HUMANB_H_
#define _HUMANB_H_

#include <string>
#include <iostream>

class Weapon;

class HumanB
{
	private:
		std::string	name;
		Weapon		*weapon;
	public:
		HumanB(std::string init_name);
		~HumanB();
		void	attack();
		void	setWeapon(Weapon &wtype);
};

#endif
