#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int	main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	/*
	std::cout << "--------------------------------" << std::endl;
	me->unequip(0);
	me->unequip(4);
	MateriaSource	src2;
	src2.learnMateria(new Ice());
	MateriaSource	src3(src2);

	Character		brown("brown");
	tmp = src2.createMateria("cure");
	tmp = src2.createMateria("ice");
	brown.equip(tmp);
	Character		billy(brown);
	billy.use(0, brown);
	*/

	std::cout << "--------------------------------" << std::endl;
	delete bob;
	delete me;
	delete src;
	std::cout << "--------------------------------" << std::endl;
	return 0;
}
