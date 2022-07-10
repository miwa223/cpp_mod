#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Animal	*animals[4];

	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		std::cout << "type: " << animals[i]->getType() << std::endl;
	}
	std::cout << "---------------------------" << std::endl;
	Cat		copyCat;
	std::cout << "    brain_-: " << copyCat.getBrain() << std::endl;
	std::cout << "    ideas_-: " << copyCat.getBrain()->ideas[0] << std::endl;
	std::cout << "    ideas_-: " << &(copyCat.getBrain()->ideas[0]) << std::endl;
	((Cat *)animals[2])->getBrain()->ideas[0] = "I want cheese";
	copyCat = *(Cat *)(animals[2]);
	std::cout << "---------------------------" << std::endl;
	std::cout << "    brain_+: " << copyCat.getBrain() << std::endl;
	std::cout << "    brain_animals[2]: " << ((Cat *)animals[2])->getBrain() << std::endl;
	std::cout << "    ideas_+: " << copyCat.getBrain()->ideas[0] << std::endl;
	std::cout << "    ideas_+: " << &(copyCat.getBrain()->ideas[0]) << std::endl;
	std::cout << "    ideas_animals[2]: " << &(((Cat *)animals[2])->getBrain()->ideas[0])
		 << std::endl;
	std::cout << "---------------------------" << std::endl;

	for (int i = 0; i < 4; i++)
		delete animals[i];
	return (0);
}
