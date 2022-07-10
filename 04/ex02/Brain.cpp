#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "Zzz...";
}
Brain::Brain(const Brain &brain)
{
	std::cout << "Brain copy constructor" << std::endl;
	*this = brain;
}

Brain	&Brain::operator=(const Brain &brain)
{
	if (this == &brain)
		return (*this);
	std::cout << "Brain copy assigment operator" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = brain.ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor" << std::endl;
}
