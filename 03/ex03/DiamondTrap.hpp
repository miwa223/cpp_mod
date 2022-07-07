#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string	name;
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &diamondtrap);
		DiamondTrap &operator=(const DiamondTrap &diamondtrap);
		~DiamondTrap();
		virtual void	attack(const std::string &target);
		void			whoAmI();
};

#endif
