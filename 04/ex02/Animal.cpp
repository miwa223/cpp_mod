#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor" << std::endl;
	this->type = "";
}

Animal::Animal(const Animal &animal)
{
	std::cout << "Animal copy constructor" << std::endl;
	*this = animal;
}

Animal	&Animal::operator=(const Animal &animal)
{
	if (this == &animal)
		return (*this);
	std::cout << "Animal copy assignment operator" << std::endl;
	this->type = animal.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor" << std::endl;
}

std::string	Animal::getType() const
{
	return (this->type);
}
