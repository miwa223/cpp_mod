#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	A("A");
	ScavTrap	B("B");
	ScavTrap	C;
	C = A;

	A.guardGate();
	A.attack(B.getName());
	B.takeDamage(A.getAttackDamage());
	C.beRepaired(5);
	return (0);
}
