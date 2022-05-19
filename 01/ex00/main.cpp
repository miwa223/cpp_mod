#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombie;

	zombie = newZombie("Emliy");
	zombie->announce();
	randomChump("Zac");
	delete	zombie;
	return (0);
}
