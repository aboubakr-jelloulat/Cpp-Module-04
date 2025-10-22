#include "AMateria.h"
#include "Character.h"



Character::Character() : _name("none") , _inventory()
{
	/*
		_inventory() : Call the default init for the array NULL
	*/
}

Character::Character(std::string name) : _name(name) , _inventory()
{
}

Character::Character(const Character &src) : _inventory()
{
	*this = src;
}


Character &Character::operator=(const Character &src)
{
	if (this == &src)
		return (*this);

	this->_name = src._name;

	/*
		subject :
			the Materias of a Character must be deleted before the new ones are added
				to their inventory

	*/

	// Delete currently held AMateria
	for (int i = 0; i < inventory_size; i++)
	{
		delete _inventory[i];
		_inventory[i] = NULL;
	}

	// Copy  _inventory's src
	for (int i = 0; i < inventory_size; i++)
	{
		if (src._inventory[i] != NULL)
		{
			_inventory[i] = src._inventory[i]->clone();
		}
	}

	return (*this);
}


Character::~Character()
{
	// subject :  the Materias must be deleted when a Character is destroyed
	for (int i = 0; i < inventory_size; i++)
	{
		delete _inventory[i];
		_inventory[i] = NULL;
	}
}


std::string const &Character::getName() const
{
	return _name;
}

/*
	subject : 
	They equip the Materias in the first empty
		slot they find, in the following order: from slot 0 to slot 3. If they try to add a Materia to
		a full inventory, or use/unequip a non-existent Materia, nothing should happen (but bugs
		are still forbidden)

*/

void Character::equip(AMateria *m)
{
	/*
		it prevents the same pointer from being stored twice = double free
	*/

	// for (int i = 0; i < inventory_size; i++)
	// {
	// 	if (_inventory[i] == m)
	// 	{
	// 		return;
	// 	}
	// }

	for (int i = 0; i < inventory_size; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			return;
		}
	}
}
/*
	subject : The unequip() member function must NOT delete the Materia!
*/

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= inventory_size)
		return;

	_inventory[idx] = NULL;
}

/*
	The use(int, ICharacter&) member function will have to use the Materia at the
		slot[idx], and pass the target parameter to the AMateria::use function.

*/

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= inventory_size)
		return;

	AMateria *materia = _inventory[idx];
	if (materia == NULL)
		return ;

	materia->use(target);
}
