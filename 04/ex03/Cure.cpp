#include "Cure.hpp"
#include "Character.hpp"

Cure::Cure() : AMateria()
{
	std::cout << "Cure default constructor" << std::endl;
	this->type = "cure";
}

Cure::Cure(const Cure &cure) : AMateria(cure)
{
	std::cout << "Cure copy constructor" << std::endl;
	*this = cure;
}

Cure	&Cure::operator=(const Cure &cure)
{
	if (this == &cure)
		return (*this);
	std::cout << "Cure copy assignment operator" << std::endl;
	this->type = cure.type;
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Cure destructor" << std::endl;
}

AMateria	*Cure::clone() const
{
	return (new Cure());
}

void		Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
