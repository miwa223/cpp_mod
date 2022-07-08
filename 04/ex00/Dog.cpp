#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor" << std::endl;
}

void	makeSound()
{
	std::cout << "Woof woof!!" << std::endl;
}
