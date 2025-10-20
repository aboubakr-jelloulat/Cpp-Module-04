#pragma once

/*
	#pragma once
		tells the compiler to include this header only once per translation unit
*/


// #include "ICharacter.h"
#include <iostream>
#include <string>

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
