#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
	private:
		std::string					name;
		unsigned int				hit_points;
		unsigned int				energy_points;
		unsigned int				attack_damage;
		unsigned int				max_hit_point;
		static unsigned int			max_attack_damage;
		static const unsigned int	k_hp = 10;
		static const unsigned int	k_ep = 10;
		static const unsigned int	k_ad = 0;
		static const unsigned int	k_mhp = 10;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &claptrap);
		ClapTrap &operator=(const ClapTrap &claptrap);
		virtual ~ClapTrap();
		virtual void	attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		std::string		getName(void);
		unsigned int	getAttackDamage(void);
};

#endif
