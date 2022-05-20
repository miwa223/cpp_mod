#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string init_name, Weapon &init_type) :
	name(init_name), weapon(init_type) {}

HumanA::~HumanA() {}

void	HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
