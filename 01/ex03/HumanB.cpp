#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string init_name)
{
	name = init_name;
}

HumanB::~HumanB() {}

void	HumanB::attack()
{
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &wtype)
{
	weapon = &wtype;
}
