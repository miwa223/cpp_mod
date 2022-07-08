#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->name = "";
	this->hit_points = k_hp;
	this->energy_points = k_ep;
	this->attack_damage = k_ad;
	this->max_hit_point = k_mhp;
	std::cout << "FragTrap default constructor: hit points " << this->hit_points
		<< "p, energy points " << this->energy_points
		<< "p, attack damage " << this->attack_damage << "p" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->name = name;
	this->hit_points = k_hp;
	this->energy_points = k_ep;
	this->attack_damage = k_ad;
	this->max_hit_point = k_mhp;
	std::cout << this->name << ": FragTrap constructor: hit points " << this->hit_points
		<< "p, energy points " << this->energy_points
		<< "p, attack damage " << this->attack_damage << "p" << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragtrap) : ClapTrap(fragtrap)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = fragtrap;
}

FragTrap &FragTrap::operator=(const FragTrap &fragtrap)
{
	ClapTrap::operator=(fragtrap);
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << this->name << ": FragTrap destructor: hit points " << this->hit_points
		<< "p, energy points " << this->energy_points
		<< "p, attack damage " << this->attack_damage << "p" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "Highfive! Yay!" << std::endl;
}
