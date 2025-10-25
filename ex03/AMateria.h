#pragma once



// #include "ICharacter.h"
#include <iostream>
#include <string>
#include "ICharacter.h"


/*
	circular dependency : AMateria -> ICharacter -> AMateria

		then when the compiler starts including files, it goes into an infinite include loop

	The solution: forward declaration

		There is a class named X, but I don’t need to know all its details right now

	
*/

class ICharacter;

class AMateria
{
	
	AMateria();

protected:
	std::string _type;

public:

	AMateria(std::string const &type);
	AMateria(const AMateria &src);
	AMateria &operator=(const AMateria &src);
	virtual ~AMateria();

	std::string const &getType() const;
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);

};
