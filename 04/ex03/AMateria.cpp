#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria()
{
	std::cout << "AMateria default constractor" << std::endl;
	this->type = "";
}

AMateria::AMateria(std::string const &type)
{
	std::cout << "AMateria constractor" << std::endl;
	this->type = type;
}

AMateria::AMateria(const AMateria &materia)
{
	std::cout << "AMateria copy constractor" << std::endl;
	*this = materia;
}

AMateria	&AMateria::operator=(const AMateria &materia)
{
	if (this == &materia)
		return (*this);
	std::cout << "AMateria copy assignment operator" << std::endl;
	this->type = materia.type;
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor" << std::endl;
}

std::string const	&AMateria::getType() const
{
	return (this->type);
}

void				AMateria::use(ICharacter& target)
{
	std::cout << "* Some materia is used at " << target.getName()
		<< " *" << std::endl;
}
