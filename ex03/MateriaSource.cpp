#include "AMateria.h"
#include "MateriaSource.h"

#include <iostream>

MateriaSource::MateriaSource() : _held_materia_count() , _materias()
{
}

MateriaSource::MateriaSource(const MateriaSource &src) : _held_materia_count() , _materias()
{
	*this = src;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src)
{
	if (this == &src)
		return (*this);

	_held_materia_count = src._held_materia_count;

	// Delete currently held AMateria
	for (int i = 0; i < _held_materia_count; i++)
	{
		delete _materias[i];
		_materias[i] = NULL;
	}

	// Copy src's AMaterias
	for (int i = 0; i < _held_materia_count; i++)
	{
		_materias[i] = src._materias[i]->clone();
	}

	return (*this);
}

MateriaSource::~MateriaSource()
{
	// Delete AMateria from _inventory
	for (int i = 0; i < _held_materia_count; i++)
	{
		delete _materias[i];
		_materias[i] = NULL;
	}
}

void MateriaSource::learnMateria(AMateria *materia)
{
	if (materia == NULL || _held_materia_count >= max_materias)
		return;

	_materias[_held_materia_count] = materia;
	_held_materia_count++;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	AMateria *materia;

	for (int i = 0; i < _held_materia_count; i++)
	{
		materia = _materias[i];

		if (materia->getType() == type)
		{
			return materia->clone();
		}
	}

	return NULL;
}
