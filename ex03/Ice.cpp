#include "AMateria.h"
#include "ICharacter.h"
#include "Ice.h"

#include <iostream>

Ice::Ice() : AMateria("ice") { }

Ice::Ice(const Ice &src) : AMateria(src)
{
	_type = "ice";
}

Ice &Ice::operator=(const Ice &src)
{
	if (this == &src)
		return (*this);

		/*
			Every Cure object is always "ice"
			becasue is enforced in the constractoe

		*/

	return (*this);
}

Ice::~Ice()
{
}

AMateria *Ice::clone() const
{
	return new Ice(*this);
}

/*
	this	Pointer to the current object
	*this	The current object itself (dereferenced from pointer)
*/

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
