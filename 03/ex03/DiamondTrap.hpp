#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string					name;
		static const unsigned int	k_hp = FragTrap::k_hp;
		static const unsigned int	k_ep = ScavTrap::k_ep;
		static const unsigned int	k_ad = FragTrap::k_ad;
		static const unsigned int	k_mhp = FragTrap::k_mhp;
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &diamondtrap);
		DiamondTrap &operator=(const DiamondTrap &diamondtrap);
		virtual ~DiamondTrap();
		virtual void	attack(const std::string &target);
		void			whoAmI();
};

#endif
