#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal
{
	protected:
		std::string	type;
	public:
		Animal();
		Animal(const Animal &animal);
		Animal &operator=(const Animal &animal);
		virtual ~Animal();
		std::string		getType() const;
		virtual void	makeSound() const;
		virtual Brain	*getBrain() const = 0;
		virtual void	setBrain(Brain *brain) = 0;
};

#endif
