#include "AMateria.h"
#include "ICharacter.h"
#include "Cure.h"

#include <iostream>

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(const Cure &src) : AMateria(src)
{
	_type = "cure";
}

Cure &Cure::operator=(const Cure &src)
{
	if (this == &src)
		return (*this);

	/*
		Every Cure object is always "cure"
		becasue is enforced in the constractoe

	*/

	return (*this);
}

Cure::~Cure()
{
}

AMateria *Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
