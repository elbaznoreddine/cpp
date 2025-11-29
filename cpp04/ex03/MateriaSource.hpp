#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private :
        AMateria *materias[4];
    public :
        MateriaSource();
        MateriaSource(const MateriaSource& ms);
        MateriaSource &operator=(const MateriaSource& ms);
        ~MateriaSource();
        void learnMateria(AMateria* m);
        AMateria* createMateria(std::string const & type);
};