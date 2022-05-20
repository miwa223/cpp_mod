#ifndef _HUMANA_H_
#define _HUMANA_H_

#include <string>
#include <iostream>

class Weapon;

class HumanA
{
	private:
		std::string	name;
		Weapon		&weapon;
	public:
		HumanA(std::string init_name, Weapon &init_type);
		~HumanA();
		void	attack();
};

#endif
