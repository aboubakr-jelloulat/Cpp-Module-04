#include "AMateria.h"
#include "ICharacter.h"


AMateria::AMateria()
{

}

AMateria::AMateria(std::string const &type) : _type(type) {}

AMateria::AMateria(const AMateria &src)
{
	*this = src;
}

AMateria &AMateria::operator=(const AMateria &src)
{
	(void) src;
	// this->_type = src._type;

	/*
		While assigning a Materia to another, copying the type doesn’t make sense.

		That means:

			So even if you assign one Materia to another, you shouldn’t change its type.

	*/
	return (*this);
}



std::string const &AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter &target)
{
	std::cout << "Hej im " << target.getName() << std::endl;
}


AMateria::~AMateria()
{
}

