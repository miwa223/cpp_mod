#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Animal *animals[4];

	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		std::cout << "type: " << animals[i]->getType() << std::endl;
	}
	std::cout << "---------------------------" << std::endl;
	Cat	cat_cp;
	std::cout << "    brain_-: " << cat_cp.getBrain() << std::endl;
	std::cout << "    ideas_-: " << cat_cp.getBrain()->ideas[0] << std::endl;
	std::cout << "    ideas_-: " << &(cat_cp.getBrain()->ideas[0]) << std::endl;
	animals[2]->getBrain()->ideas[0] = "I want cheese";
	cat_cp = *(Cat *)(animals[2]);
	std::cout << "---------------------------" << std::endl;
	std::cout << "    brain_+: " << cat_cp.getBrain() << std::endl;
	std::cout << "    brain_animals[2]: " << animals[2]->getBrain() << std::endl;
	std::cout << "    ideas_+: " << cat_cp.getBrain()->ideas[0] << std::endl;
	std::cout << "    ideas_+: " << &(cat_cp.getBrain()->ideas[0]) << std::endl;
	std::cout << "    ideas_animals[2]: " << &(animals[2]->getBrain()->ideas[0]) << std::endl;
	std::cout << "---------------------------" << std::endl;

	for (int i = 0; i < 4; i++)
		delete animals[i];
	return (0);
}
