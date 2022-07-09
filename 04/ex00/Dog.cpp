#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &dog) : Animal(dog)
{
	std::cout << "Dog copy constructor" << std::endl;
	*this = dog;
}

Dog &Dog::operator=(const Dog &dog)
{
	Animal::operator=(dog);
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor" << std::endl;
}

std::string	Dog::getType() const
{
	return (this->type);
}

void		Dog::makeSound() const
{
	std::cout << "Woof woof!!" << std::endl;
}
