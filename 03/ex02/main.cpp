#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	A("A");
	FragTrap	B("B");
	FragTrap	C;
	C = A;

	A.attack(B.getName());
	B.takeDamage(A.getAttackDamage());
	C.beRepaired(5);
	A.highFivesGuys();
	return (0);
}
