#pragma once

#include "ICharacter.h"
#include <iostream>
#include <string>

class AMateria;

class Character : public ICharacter
{
	std::string _name;

	static const int inventory_size = 4;

	AMateria *_inventory[inventory_size];

public :
	Character();
	Character(std::string name);
	Character(const Character &src);
	Character &operator=(const Character &src);
	virtual ~Character();

	std::string const & getName() const;
	void	equip(AMateria* m);
	void	unequip(int idx);
	void 	use(int idx, ICharacter& target);
};
