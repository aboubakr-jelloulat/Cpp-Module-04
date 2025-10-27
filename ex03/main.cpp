#include "AMateria.h"
#include "Cure.h"
#include "Character.h"
#include "ICharacter.h"
#include "Ice.h"
#include "MateriaSource.h"
#include <iostream>
#include <cstdlib>
#include <cassert>


static void SubjectTestes()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);

	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

}



void Amateria_Tests()
{
	std::cout << std::endl << "**** AMATERIA ****" << std::endl;

	MateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	AMateria *a_materia;
	a_materia = src->createMateria("ice");

	AMateria *a_materia2;
	a_materia2 = a_materia->clone(); // assign
	assert(a_materia2->getType() == "ice");

	AMateria *a_materia3;
	a_materia3 = src->createMateria("cure");

	*a_materia2 = *a_materia3;
	assert(a_materia2->getType() == "ice");
	/*
		subject : While assigning a Materia to another, copying the type doesn’t make sense.
	*/ 

	ICharacter *bob = new Character("bob");
	a_materia->use(*bob);

	ICharacter *none = new Character();
	a_materia->use(*none);

	delete src;
	delete a_materia;
	delete a_materia2;
	delete a_materia3;
	delete bob;
	delete none;
}


void character() {
    Character *me = new Character("me");
    AMateria *ice = new Ice();
    AMateria *cure = new Cure();

    me->equip(ice);
    me->equip(ice); // handle no double equip
    
    me->equip(cure);
    me->equip(cure);
    
    me->use(0, *me); // ice
    me->use(1, *me); // cure
    
    me->unequip(0); 
    me->unequip(1);  
    
    me->use(0, *me);
    me->use(1, *me); 

    delete me;  // This will delete all unequipped materias via _ClearList()
}


int main()
{
	
	
	SubjectTestes();

	Amateria_Tests();


	character();


	std::cout << std::endl;

	system("leaks -q interface");

	return 0;
}




