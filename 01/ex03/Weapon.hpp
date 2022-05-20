#ifndef _WEAPON_H_
#define _WEAPON_H_

#include <string>
#include <iostream>

class Weapon
{
	private:
		std::string	type;
	public:
		Weapon(std::string init_type);
		~Weapon();
		const std::string	&getType(void);
		void				setType(std::string new_type);
};

#endif
