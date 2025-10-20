#pragma once

#include "AMateria.h"

class ICharacter;

class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure &src);
	Cure &operator=(const Cure &src);
	virtual ~Cure();

	AMateria *clone() const;
	void use(ICharacter &target);
};