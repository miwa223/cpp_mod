#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor" << std::endl;
}

void	makeSound()
{
	std::cout << "Meow" << std::endl;
}
