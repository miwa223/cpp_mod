#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* wrong = new WrongCat();
	Cat	k;
	Cat *n = new Cat();

	k = *n;
	std::cout << "-----------------------" << std::endl;

	std::cout << "type: " << j->getType() << " " << std::endl;
	std::cout << "type: " << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << "-----------------------" << std::endl;

	std::cout << "type: " << meta->getType() << " " << std::endl;
	std::cout << "type: " << wrong->getType() << " " << std::endl;
	wrong->makeSound();
	std::cout << "type: " << k.getType() << " " << std::endl;
	k.makeSound();

	std::cout << "-----------------------" << std::endl;

	delete meta;
	delete j;
	delete i;
	delete wrong;
	return 0;
}
