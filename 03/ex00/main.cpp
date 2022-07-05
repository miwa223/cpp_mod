#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	A("A");
	ClapTrap	B("B");

	A.attack(B.getName());
	B.takeDamage(A.getAttackDamage());

	B.beRepaired(5);

	A.attack(B.getName());
	B.takeDamage(A.getAttackDamage());

	A.beRepaired(5);
	return (0);
}
