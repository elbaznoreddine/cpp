#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (size_t i = 0; i < 4; i++)
    {
        materias[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource &ms)
{
    for (size_t i = 0; i < 4; i++)
    {
        if (ms.materias[i])
            materias[i] = ms.materias[i]->clone();
        else
            materias[i] = NULL;
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &ms)
{
    if (this != &ms)
    {
        for (size_t i = 0; i < 4; i++)
        {
            if (materias[i])
            {
                delete materias[i];
                materias[i] = NULL;
            }
        }

        for (size_t j = 0; j < 4; j++)
        {
            if (ms.materias[j])
                materias[j] = ms.materias[j]->clone();
            else
                materias[j] = NULL;
        }
    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
        return;
    for (size_t i = 0; i < 4; i++)
    {
        if (!materias[i])
        {
            materias[i] = m;
            return;
        }
    }
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
    for (size_t i = 0; i < 4; i++)
    {
		if (materias[i])
        	if (materias[i]->getType() == type)
           		return materias[i]->clone();
    }
    return (0);
}

MateriaSource::~MateriaSource()
{
    for (size_t i = 0; i < 4; i++)
    {
        if (materias[i])
            delete materias[i];
    }
}