#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombie;

	zombie = newZombie("Emily");
	zombie->announce();
	randomChump("Zac");
	delete	zombie;
	return (0);
}
