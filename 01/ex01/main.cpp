#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombies;
	int		N = 3;

	zombies = zombieHorde(N, "ZB");
	for (int i = 0; i < N; i++)
	{
		zombies[i].announce();
	}
	delete[] zombies;
	return (0);
}
