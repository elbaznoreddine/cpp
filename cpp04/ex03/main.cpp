#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"


	int main()
{
	// IMateriaSource* src = new MateriaSource();
	// for (int i = 0; i < 1000; i++)
	// {
	// 	src->learnMateria(new Ice());
	// 	src->learnMateria(new Cure());
	// }
	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());
	// ICharacter* me = new Character("me");
	// AMateria* tmp;
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	// for (int i = 0; i < 1000; i++)
	// {
	// 	tmp = src->createMateria("ice");
	// 	me->equip(tmp);
	// 	tmp = src->createMateria("cure");
	// 	me->equip(tmp);	tmp = src->createMateria("ice");
	// 	me->equip(tmp);
	// 	tmp = src->createMateria("cure");
	// 	me->equip(tmp);
	// }
	// ICharacter* bob = new Character("bob");
	// me->use(0, *bob);
	// me->use(1, *bob);
	// delete bob;
	// delete me;
	// delete src;

	MateriaSource src1;
	for (int i = 0; i < 1000; i++)
	{
		src1.learnMateria(new Ice());
		src1.learnMateria(new Cure());
	}
	Character me1("me1");
	AMateria* tmp1;
	for (int i = 0; i < 1000; i++)
	{
		tmp1 = src1.createMateria("ice");
		me1.equip(tmp1);
		tmp1 = src1.createMateria("cure");
		me1.equip(tmp1);
	}
	Character bob1("bob");
	me1.use(0, bob1);
	me1.use(1, bob1);

	MateriaSource src2 = src1;
	MateriaSource src3 = src2;
	src2 = src3;
	src3 = src1;
	src1 = src1;

	Character me2 = me1;
	Character me3 = me2;
	me2 = me3;
	me3 = me1;
	me1 = me1;

	Character bob2 = bob1;
	bob2 = bob1;

	return 0;
}