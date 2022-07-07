#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->name = "";
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << "FragTrap default constructor: hit points " << this->hit_points
		<< "p, energy points " << this->energy_points
		<< "p, attack damage " << this->attack_damage << "p" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->name = name;
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
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
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	this->name = fragtrap.name;
	this->hit_points = fragtrap.hit_points;
	this->energy_points = fragtrap.energy_points;
	this->attack_damage = fragtrap.attack_damage;
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
