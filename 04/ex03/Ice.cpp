#include "Ice.hpp"
#include "Character.hpp"

Ice::Ice() : AMateria()
{
	std::cout << "Ice default constructor" << std::endl;
	this->type = "ice";
}

Ice::Ice(const Ice &ice) : AMateria(ice)
{
	std::cout << "Ice copy constructor" << std::endl;
	*this = ice;
}

Ice	&Ice::operator=(const Ice &ice)
{
	if (this == &ice)
		return (*this);
	std::cout << "Ice copy assignment operator" << std::endl;
	this->type = ice.type;
	return (*this);
}

Ice::~Ice()
{
	std::cout << "Ice destructor" << std::endl;

}

AMateria	*Ice::clone() const
{
	return (new Ice());
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at "
		<< target.getName() << " *" << std::endl;
}
