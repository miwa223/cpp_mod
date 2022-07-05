#include "ClapTrap.hpp"

unsigned int	ClapTrap::max_hit_point = 10;
unsigned int	ClapTrap::max_attack_damage = 100000;

ClapTrap::ClapTrap()
{
	this->name = "";
	this->hit_point = 10;
	this->energy_point = 10;
	this->attack_damage = 0;
	std::cout << "Default constructor: hit points " << this->hit_point
		<< "p, energy points " << this->energy_point
		<< "p, attack damage " << this->attack_damage << "p" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hit_point = 10;
	this->energy_point = 10;
	this->attack_damage = 0;
	std::cout << this->name << ": Constructor: hit points " << this->hit_point
		<< "p, energy points " << this->energy_point
		<< "p, attack damage " << this->attack_damage << "p"<< std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << this->name << ": Destructor: hit points "
		<< this->hit_point << "p, energy points " << this->energy_point
		<< "p, attack damage " << this->attack_damage << "p" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = claptrap;
}

ClapTrap		&ClapTrap::operator=(const ClapTrap &claptrap)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->name = claptrap.name;
	this->hit_point = claptrap.hit_point;
	this->energy_point = claptrap.energy_point;
	this->attack_damage = claptrap.attack_damage;
	return (*this);
}

void			ClapTrap::attack(const std::string& target)
{
	if (this->hit_point == 0)
	{
		std::cerr << this->name << ": No hit points left" << std::endl;
		return ;
	}
	if (this->energy_point == 0)
	{
		std::cerr << this->name << ": No energy points left" << std::endl;
		return ;
	}
	if (this->attack_damage + 5 <= max_attack_damage)
		this->attack_damage += 5;
	std::cout << "ClapTrap " << this->name << " attacks " << target
		<< ", causing " << this->attack_damage << " points of damage!" << std::endl;
	this->energy_point--;
}

void			ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " takes damage, losing "
		<< amount << " hit points!" << std::endl;
	if (this->hit_point <= amount)
	{
		this->hit_point = 0;
		std::cerr << this->name << ": No hit points left" << std::endl;
		return ;
	}
	this->hit_point -= amount;
}

void			ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hit_point == 0)
		std::cerr << this->name << ": No hit points left" << std::endl;
	else if (this->energy_point == 0)
		std::cerr << this->name << ": No energy points left" << std::endl;
	else if (this->hit_point == max_hit_point)
		std::cerr << this->name << ": Nothing to repair" << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->name << " repairs itself, recovering "
			<< amount << " hit points!" << std::endl;
		if (this->hit_point + amount > max_hit_point)
			this->hit_point = max_hit_point;
		else
			this->hit_point += amount;
		this->energy_point--;
	}
}

std::string		ClapTrap::getName(void)
{
	return (this->name);
}

unsigned int	ClapTrap::getAttackDamage(void)
{
	return (this->attack_damage);
}
