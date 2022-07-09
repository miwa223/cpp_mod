#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat &wrong_cat);
		WrongCat &operator=(const WrongCat &wrong_cat);
		virtual ~WrongCat();
		std::string		getType() const;
		void	makeSound() const;
};

#endif
