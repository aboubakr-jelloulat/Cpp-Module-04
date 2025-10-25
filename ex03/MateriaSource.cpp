#include "AMateria.h"
#include "MateriaSource.h"

#include <iostream>

MateriaSource::MateriaSource() : _materia_count() , _materias()
{
}

MateriaSource::MateriaSource(const MateriaSource &src) : _materia_count() , _materias()
{
	*this = src;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src)
{
	if (this == &src)
		return (*this);

	_materia_count = src._materia_count;

	for (int i = 0; i < _materia_count; i++)
	{
		delete _materias[i];
		_materias[i] = NULL;
	}

	for (int i = 0; i < _materia_count; i++)
	{
		if (!src._materias[i])
			_materias[i] = src._materias[i]->clone();
	}

	return (*this);
}

MateriaSource::~MateriaSource()
{
	// Delete AMateria from _inventory
	for (int i = 0; i < _materia_count; i++)
	{
		delete _materias[i];
		_materias[i] = NULL;
	}
}

void MateriaSource::learnMateria(AMateria *materia)
{
	if (!materia || _materia_count >= max_materias)
		return;

	_materias[_materia_count] = materia;
	_materia_count++;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	AMateria *materia;

	for (int i = 0; i < _materia_count; i++)
	{
		materia = _materias[i];

		if (materia->getType() == type)
		{
			return materia->clone();
		}
	}

	return NULL;
}
