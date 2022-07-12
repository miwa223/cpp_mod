#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int	main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice()); //newしたiceは、materia source(レシピみたいなもの)の中に保存される
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice"); //ここでiceがnewされる
	me->equip(tmp); //meにiceが武装される(上と同一)
	tmp = src->createMateria("cure"); //ここでnewされる
	me->equip(tmp); //meにcureが武装される(上と同一)

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	/*
	me->unequip(0);
	me->unequip(4);
	*/

	delete bob;
	delete me;
	delete src;
	return 0;
}
