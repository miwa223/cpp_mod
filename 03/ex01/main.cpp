#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	A("A");
	ScavTrap	B("B");

	A.guardGate();
	A.attack(B.getName());
	B.takeDamage(A.getAttackDamage());
	return (0);
}
