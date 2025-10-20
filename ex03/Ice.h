#pragma once

#include "AMateria.h"

class ICharacter;

class Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice &src);
	Ice &operator=(const Ice &src);
	virtual ~Ice();

	AMateria *clone() const;
	void use(ICharacter &target);
};
