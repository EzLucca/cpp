#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();

	// This leaks
	// 	src->learnMateria(new Ice());
	// 	src->learnMateria(new Cure());

	AMateria* ice = new Ice();
	AMateria* cure = new Cure();
	src->learnMateria(ice);
	src->learnMateria(cure);
	delete ice;
	delete cure;

	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
}
