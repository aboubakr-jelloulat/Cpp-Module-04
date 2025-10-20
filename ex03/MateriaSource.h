#pragma once

#include "IMateriaSource.h"

class AMateria;

class MateriaSource : public IMateriaSource
{
	static const int max_materias = 4;

	int _held_materia_count;
	AMateria *_materias[max_materias];

public:
	MateriaSource();
	MateriaSource(const MateriaSource &src);
	virtual ~MateriaSource();
	MateriaSource &operator=(const MateriaSource &src);

	void learnMateria(AMateria *materia);
	AMateria *createMateria(std::string const &type);

};