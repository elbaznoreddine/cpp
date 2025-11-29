#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

int main()
{
    AMateria* a = new Ice();
    AMateria* b = new Cure();
    Character* c = new Character("bob");
    Character* d = new Character("bob");

    ICharacter* c1 = new Character("hh");

    a->use(*c);
    b->use(*c);


    c->equip(b);
    d->equip(b);

    c->unequip(0);///b delete

    d->use(0, *c1);


    c->equip(b);
    
    c->unequip(0);
    c->unequip(1);
    c->use(1, *c1);

    
    // delete b;
    delete c;
    delete c1;

    // MateriaSource* m = new MateriaSource();
    // m->learnMateria(a);
    // m->learnMateria(b);

    // AMateria* aa= m->createMateria("bob");

    // aa->use(*c);
    

}