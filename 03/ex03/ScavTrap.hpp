#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
	protected:
		static const unsigned int	k_hp = 100;
		static const unsigned int	k_ep = 50;
		static const unsigned int	k_ad = 20;
		static const unsigned int	k_mhp = 100;
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &scavtrap);
		ScavTrap &operator=(const ScavTrap &scavtrap);
		virtual ~ScavTrap();
		virtual void	attack(const std::string& target);
		void			guardGate();
};

#endif
