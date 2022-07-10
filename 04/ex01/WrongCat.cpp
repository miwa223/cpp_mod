#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat default constructor" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &wrong_cat) : WrongAnimal(wrong_cat)
{
	std::cout << "WrongCat copy constructor" << std::endl;
	*this = wrong_cat;
}

WrongCat &WrongCat::operator=(const WrongCat &wrong_cat)
{
	WrongAnimal::operator=(wrong_cat);
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor" << std::endl;
}

void		WrongCat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}
