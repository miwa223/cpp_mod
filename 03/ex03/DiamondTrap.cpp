#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap()
{
	ClapTrap::name = "_clap_name";
	this->name = "";
	this->hit_points = FragTrap::hit_points;
	this->energy_points = ScavTrap::energy_points;
	this->attack_damage = FragTrap::attack_damage;
	std::cout << "DiamondTrap default constructor: hit points " << this->hit_points
		<< "p, energy points " << this->energy_points
		<< "p, attack damage " << this->attack_damage << "p" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name), FragTrap(name)
{
	ClapTrap::name = name + "_clap_name";
	this->name = name;
	this->hit_points = FragTrap::hit_points;
	this->energy_points = ScavTrap::energy_points;
	this->attack_damage = FragTrap::attack_damage;
	std::cout << "DiamondTrap constructor: hit points " << this->hit_points
		<< "p, energy points " << this->energy_points
		<< "p, attack damage " << this->attack_damage << "p" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondtrap) : ScavTrap(diamondtrap), FragTrap(diamondtrap)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = diamondtrap;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondtrap)
{
	ScavTrap::operator=(diamondtrap);
	FragTrap::operator=(diamondtrap);
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	this->name = diamondtrap.name;
	this->hit_points = diamondtrap.hit_points;
	this->energy_points = diamondtrap.energy_points;
	this->attack_damage = diamondtrap.attack_damage;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << this->name << ": DiamondTrap destructor: hit points " << this->hit_points
		<< "p, energy points " << this->energy_points
		<< "p, attack damage " << this->attack_damage << "p" << std::endl;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << this->name
		<< ", ClapTrap name: " << ClapTrap::name << std::endl;
}
