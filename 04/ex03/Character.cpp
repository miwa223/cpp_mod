#include "Character.hpp"
#include "AMateria.hpp"

Character::Character()
{
	std::cout << "Character default constructor" << std::endl;
	this->name = "";
	this->has_space = true;
	for (int i = 0; i < 4; i++)
		this->materias[i] = nullptr;
	for (int i = 0; i < MAX_UNEQUIP; i++)
		this->materia_thrown[i] = nullptr;
}

Character::Character(std::string name)
{
	std::cout << "Character constructor" << std::endl;
	this->name = name;
	this->has_space = true;
	for (int i = 0; i < 4; i++)
		this->materias[i] = nullptr;
	for (int i = 0; i < MAX_UNEQUIP; i++)
		this->materia_thrown[i] = nullptr;
}

Character::Character(const Character &character)
{
	std::cout << "Character copy constructor" << std::endl;
	for (int i = 0; i < 4; i++)
		this->materias[i] = nullptr;
	for (int i = 0; i < MAX_UNEQUIP; i++)
		this->materia_thrown[i] = nullptr;
	*this = character;
}

Character	&Character::operator=(const Character &character)
{
	if (this == &character)
		return (*this);

	std::cout << "Character copy assignment operator" << std::endl;

	this->name = character.name;
	this->has_space = character.has_space;
	for (int i = 0; i < 4; i++)
		delete this->materias[i];
	for (int i = 0; i < MAX_UNEQUIP && this->materia_thrown[i]; i++)
		delete this->materia_thrown[i];
	for (int i = 0; i < 4; i++)
	{
		if (character.materias[i])
			this->materias[i] = character.materias[i]->clone();
	}
	for (int i = 0; i < MAX_UNEQUIP && character.materia_thrown[i]; i++)
		this->materias[i] = character.materia_thrown[i]->clone();
	return (*this);
}

Character::~Character()
{
	std::cout << "Character destructor" << std::endl;
	for (int i = 0; i < 4; i++)
		delete this->materias[i];
	for (int i = 0; i < MAX_UNEQUIP && this->materia_thrown[i]; i++)
		delete this->materia_thrown[i];
}

std::string const	&Character::getName() const
{
	return (this->name);
}

void				Character::equip(AMateria* m)
{
	if (m == 0)
	{
		std::cerr << "Error: invalid parameter" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!this->materias[i])
		{
			this->materias[i] = m;
			std::cout << "OK: " << this->materias[i]->getType()
				<< " equiped to slot " << i << std::endl;
			return ;
		}
	}
	std::cerr << "Error: can't equip anymore" << std::endl;
	delete m;
}

void				Character::unequip(int idx)
{
	if (!(0 <= idx && idx <= 3) || !this->materias[idx])
		std::cerr << "Error: can't unequip the unexisting materia"
			<< std::endl;
	else if (!this->has_space)
		std::cerr << "Error: can't unequip anymore!" << std::endl;
	else
	{
		for (int i = 0; i < MAX_UNEQUIP; i++)
		{
			if (!this->materia_thrown[i])
			{
				this->materia_thrown[i] = this->materias[idx];
				break ;
			}
		}
		this->materias[idx] = nullptr;
		if (this->materia_thrown[MAX_UNEQUIP - 1])
			this->has_space = false;
	}
}

void				Character::use(int idx, ICharacter& target)
{
	if (0 <= idx && idx <= 3 && this->materias[idx])
		this->materias[idx]->use(target);
	else
		std::cerr << "Error: can't use the unexisting materia" << std::endl;
}
