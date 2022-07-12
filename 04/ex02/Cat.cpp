#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat &cat) : Animal(cat)
{
	std::cout << "Cat copy constructor" << std::endl;
	this->brain = nullptr;
	*this = cat;
}

Cat	&Cat::operator=(const Cat &cat)
{
	if (this == &cat)
		return (*this);

	Animal::operator=(cat);

	std::cout << "Cat copy assigment operator" << std::endl;
	Brain	*brain = new Brain();
	*brain = *cat.brain;
	delete this->brain;
	this->brain = brain;
	return (*this);
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat destructor" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}

Brain	*Cat::getBrain() const
{
	return (this->brain);
}

void	Cat::setBrain(Brain *brain)
{
	this->brain = brain;
}
