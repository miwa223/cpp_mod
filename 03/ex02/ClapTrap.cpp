#include "ClapTrap.hpp"

unsigned int	ClapTrap::max_attack_damage = 100000;

ClapTrap::ClapTrap()
{
	this->name = "";
	this->hit_points = k_hp;
	this->energy_points = k_ep;
	this->attack_damage = k_ad;
	this->max_hit_point = k_mhp;
	std::cout << "ClapTrap default constructor: hit points " << this->hit_points
		<< "p, energy points " << this->energy_points
		<< "p, attack damage " << this->attack_damage << "p" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hit_points = k_hp;
	this->energy_points = k_ep;
	this->attack_damage = k_ad;
	this->max_hit_point = k_mhp;
	std::cout << this->name << ": ClapTrap constructor: hit points " << this->hit_points
		<< "p, energy points " << this->energy_points
		<< "p, attack damage " << this->attack_damage << "p"<< std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << this->name << ": ClapTrap destructor: hit points "
		<< this->hit_points << "p, energy points " << this->energy_points
		<< "p, attack damage " << this->attack_damage << "p" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = claptrap;
}

ClapTrap		&ClapTrap::operator=(const ClapTrap &claptrap)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	this->name = claptrap.name;
	this->hit_points = claptrap.hit_points;
	this->energy_points = claptrap.energy_points;
	this->attack_damage = claptrap.attack_damage;
	this->max_hit_point = this->hit_points;
	return (*this);
}

void			ClapTrap::attack(const std::string& target)
{
	if (this->hit_points == 0)
	{
		std::cerr << this->name << ": No hit points left" << std::endl;
		return ;
	}
	if (this->energy_points == 0)
	{
		std::cerr << this->name << ": No energy points left" << std::endl;
		return ;
	}
	if (this->attack_damage + 5 <= max_attack_damage)
		this->attack_damage += 5;
	std::cout << "ClapTrap " << this->name << " attacks " << target
		<< ", causing " << this->attack_damage << " points of damage!" << std::endl;
	this->energy_points--;
}

void			ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " takes damage, losing "
		<< amount << " hit points!" << std::endl;
	if (this->hit_points <= amount)
	{
		this->hit_points = 0;
		std::cerr << this->name << ": No hit points left" << std::endl;
		return ;
	}
	this->hit_points -= amount;
}

void			ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hit_points == 0)
		std::cerr << this->name << ": No hit points left" << std::endl;
	else if (this->energy_points == 0)
		std::cerr << this->name << ": No energy points left" << std::endl;
	else if (this->hit_points == max_hit_point)
		std::cerr << this->name << ": Nothing to repair" << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->name << " repairs itself, recovering "
			<< amount << " hit points!" << std::endl;
		if (this->hit_points + amount > max_hit_point)
			this->hit_points = max_hit_point;
		else
			this->hit_points += amount;
		this->energy_points--;
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
