#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
	private:
		std::string			name;
		unsigned int		hit_point;
		unsigned int		energy_point;
		unsigned int		attack_damage;
		static unsigned int	max_hit_point;
		static unsigned int	max_attack_damage;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &claptrap);
		ClapTrap &operator=(const ClapTrap &claptrap);
		~ClapTrap();
		void			attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		std::string		getName(void);
		unsigned int	getAttackDamage(void);
};

#endif
