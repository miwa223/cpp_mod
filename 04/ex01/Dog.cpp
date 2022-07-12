#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog &dog) : Animal(dog)
{
	std::cout << "Dog copy constructor" << std::endl;
	this->brain = nullptr;
	*this = dog;
}

Dog	&Dog::operator=(const Dog &dog)
{
	if (this == &dog)
		return (*this);

	Animal::operator=(dog);

	std::cout << "Dog copy assigment operator" << std::endl;
	Brain	*brain = new Brain();
	*brain = *dog.brain;
	delete this->brain;
	this->brain = brain;
	return (*this);
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog destructor" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Woof woof!!" << std::endl;
}

Brain	*Dog::getBrain() const
{
	return (this->brain);
}

void	Dog::setBrain(Brain *brain)
{
	this->brain = brain;
}
