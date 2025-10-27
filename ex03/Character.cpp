#include "AMateria.h"
#include "Character.h"

Character::Character() : _name("none"), _inventory(), _listhead(NULL)
{
	/*
		_inventory() : Call the default init for the array NULL
	*/
}

Character::Character(std::string name) : _name(name), _inventory(), _listhead(NULL)
{
}

Character::Character(const Character &src) : _inventory(), _listhead(NULL)
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
	for (int i = 0; i < inventory_size; i++)
	{
		delete _inventory[i];
		_inventory[i] = NULL;
	}

	/*
		subject :
			Any copy (using copy constructor or copy assignment operator) of a Character must be deep.
	*/
	for (int i = 0; i < inventory_size; i++)
	{
		if (src._inventory[i] != NULL)
			_inventory[i] = src._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}

	/*
		Clear existing unequipped list and clone the source's list
	*/
	_ClearList();
	if (src._listhead)
	{
		t_materiaList *srcNode = src._listhead;
		while (srcNode)
		{
			_AddToList(srcNode->node->clone());
			srcNode = srcNode->next;
		}
	}

	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < inventory_size; i++)
	{
		delete _inventory[i];
		_inventory[i] = NULL;
	}

	// delete unequipped materias
	_ClearList();
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
    if (!m)
        return;

    // Check if already equipped
    for (int i = 0; i < inventory_size; i++)
        if (_inventory[i] == m)
            return;

    // Find empty slot and equip
    for (int i = 0; i < inventory_size; i++)
    {
        if (_inventory[i] == NULL)
        {
            _inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= inventory_size)
        return;

    if (_inventory[idx] == NULL)
        return;

    // Add to list of unequipped materias
    _AddToList(_inventory[idx]);
    _inventory[idx] = NULL;
}

/*
	subject :
		The use(int, ICharacter&) member function will have to use the Materia at the
			slot[idx], and pass the target parameter to the AMateria::use function.
*/

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= inventory_size)
		return;

	AMateria *materia = _inventory[idx];
	if (materia == NULL)
		return;

	materia->use(target);
}


// List Helper :


void Character::_AddToList(AMateria *m)
{
	if (!m)
		return;

	t_materiaList *newNode = new t_materiaList;
	newNode->node = m;
	newNode->next = NULL;

	if (!_listhead)
		_listhead = newNode;
	else
	{
		t_materiaList *tmp = _listhead;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = newNode;
	}
}

void Character::_ClearList()
{
	t_materiaList *tmp;
	while (_listhead)
	{
		tmp = _listhead;
		_listhead = _listhead->next;
		delete tmp->node;  // delete the unequipped materia
		tmp->node = NULL;
		delete tmp;
		tmp = NULL;
	}
}
