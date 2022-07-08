#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
	protected:
		static const unsigned int	k_hp = 100;
		static const unsigned int	k_ep = 100;
		static const unsigned int	k_ad = 30;
		static const unsigned int	k_mhp = 100;
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &fragtrap);
		FragTrap &operator=(const FragTrap &fragtrap);
		virtual ~FragTrap();
		void	highFivesGuys(void);
};

#endif
