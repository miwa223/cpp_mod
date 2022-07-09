#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal default constructor" << std::endl;
	this->type = "";
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrong_animal)
{
	std::cout << "WrongAnimal copy constructor" << std::endl;
	*this = wrong_animal;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wrong_animal)
{
	if (this == &wrong_animal)
		return (*this);
	std::cout << "WrongAnimal copy assignment operator" << std::endl;
	this->type = wrong_animal.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (this->type);
}

void		WrongAnimal::makeSound() const
{
	std::cout << "Some wrong_animal is crying" << std::endl;
}
