#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain	*brain;
	public:
		Cat();
		Cat(const Cat &cat);
		Cat &operator=(const Cat &cat);
		virtual ~Cat();
		virtual void	makeSound() const;
		virtual Brain	*getBrain() const;
		virtual void	setBrain(Brain *brain);
};

#endif
