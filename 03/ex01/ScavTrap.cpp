#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->name = "";
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << "ScavTrap efault constructor: hit points " << this->hit_points
		<< "p, energy points " << this->energy_points
		<< "p, attack damage " << this->attack_damage << "p" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->name = name;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << this->name << ": ScavTrap constructor: hit points " << this->hit_points
		<< "p, energy points " << this->energy_points
		<< "p, attack damage " << this->attack_damage << "p" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavtrap) : ClapTrap(scavtrap)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = scavtrap;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &scavtrap)
{
	ClapTrap::operator=(scavtrap);
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	this->name = scavtrap.name;
	this->hit_points = scavtrap.hit_points;
	this->energy_points = scavtrap.energy_points;
	this->attack_damage = scavtrap.attack_damage;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << this->name << ": ScavTrap destructor: hit points " << this->hit_points
		<< "p, energy points " << this->energy_points
		<< "p, attack damage " << this->attack_damage << "p" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->hit_points == 0)
	{
		std::cerr << this->name << ": ScavTrap no hit points left" << std::endl;
		return ;
	}
	if (this->energy_points == 0)
	{
		std::cerr << this->name << ": ScavTrap no energy points left" << std::endl;
		return ;
	}
	if (this->attack_damage + 5 <= max_attack_damage)
		this->attack_damage += 5;
	std::cout << "ScavTrap " << this->name << " attacks " << target
		<< ", causing " << this->attack_damage << " points of damage!" << std::endl;
	this->energy_points--;
}
