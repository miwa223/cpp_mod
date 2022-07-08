#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor" << std::endl;
}

void	makeSound()
{
	std::cout << "Animal is crying" << std::endl;
}
