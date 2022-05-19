#include "Zombie.hpp"

Zombie::Zombie() {
	std::cout << "A zombie emerged" << std::endl;
}

Zombie::~Zombie() {
	std::cout << "A zombie destroyed" << std::endl;
}

void	Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string new_name)
{
	name = new_name;
}
