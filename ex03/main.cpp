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
	*a_materia2 = *a_materia2;
	assert(a_materia2->getType() == "ice"); // doesn’t make sense 

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


void ice_cure()
{
    std::cout << std::endl << "*** ICE & Cure ***" << std::endl;

    MateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    AMateria *ice = src->createMateria("ice");
    assert(ice->getType() == "ice");

    AMateria *cure = src->createMateria("cure");
    assert(cure->getType() == "cure");



    delete src;
    delete ice;
    delete cure;
}


void	materia_source_test1()
{

	std::cout << std::endl << "**** MATERIA_SOURCE TEST 1  ****" << std::endl;

    MateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Ice());

    src->learnMateria(new Cure());
   	src->learnMateria(new Ice());

	/*
		subject :
			The latter is a copy of the Materia previously learned by
				the MateriaSource whose type equals the one passed as parameter.
	*/
	AMateria *first_cure = src->createMateria("cure"); // ila makanch 9bel maydozchi
	assert(first_cure && first_cure->getType() == "cure");

	delete src;
	delete first_cure;

	
}


void materia_source()
{
    std::cout << std::endl << "**** MATERIA_SOURCE  ****" << std::endl;

	{
		MateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());

		src->learnMateria(new Cure());
		src->learnMateria(new Ice());

		AMateria *external_ice = new Ice();
		src->learnMateria(external_ice); // Should not be added source full

		src->learnMateria(NULL); // Should be ignored

		// Try creating a non existent materia type

		/*
			subject : . Returns 0 if the type is unknown.
		*/
		AMateria *unknown_materia = src->createMateria("fire");
		assert(unknown_materia == NULL);

		delete src;
		delete external_ice;
	}

  
    MateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
    src->learnMateria(new Cure());
	/*
		subject : In a nutshell, your MateriaSource must be able to learn "templates" of Materias to
			create them when needed.
	*/
	AMateria *ice = new Ice();
	src->learnMateria(ice);
    src->learnMateria(new Cure());

	AMateria *external_ice = new Ice();
	src->learnMateria(external_ice); 



	//src->learnMateria(new Cure()); // kaydiro leaks ha9ach mat add f src You need a pointer to delete them
	// src->learnMateria(new Cure());
	// src->learnMateria(new Ice());


    // Create multi materia 
    AMateria *first_ice = src->createMateria("ice");
    AMateria *first_cure = src->createMateria("cure");
    AMateria *second_ice = src->createMateria("ice");
    AMateria *second_cure = src->createMateria("cure");
    AMateria *should_be_null = src->createMateria("fire"); 

    assert(first_ice && first_ice->getType() == "ice");
    assert(first_cure && first_cure->getType() == "cure");
    assert(second_ice && second_ice->getType() == "ice");
    assert(second_cure && second_cure->getType() == "cure");
    assert(should_be_null == NULL);


    

    delete src;
	delete external_ice; // delete ha9ach can buffer full omadkhlchi l src bash delete f destractor
    delete first_ice;
    delete first_cure;
    delete second_ice;
    delete second_cure;

}


void character()
{
	Character *me = new Character("me");
	AMateria *ice = new Ice();

	me->equip(NULL);
	me->equip(ice);
	me->equip(ice); // handle no double free

	AMateria *cure = new Cure();
	me->equip(NULL);
	me->equip(cure);
	me->equip(cure);


	me->use(5, *me); // out of range
	me->use(-1, *me); // less
	me->use(0, *me); // ice
	me->use(1, *me); // cure
	me->use(3, *me); // NULL
	
	me->unequip(-1);
	me->unequip(0);
	me->unequip(4);

	me->use(0, *me); // NULL delete ice
	me->use(1, *me); // cure

	Character none;
	assert(none.getName() == "none");
	

	delete me;
	delete ice; // only affect NULL no delete , you need to delete it manual 
	// delete cure; // destructor runs and already deletes the ice and cure
}


int main()
{
	
	SubjectTestes();

	Amateria_Tests();

	ice_cure();

	materia_source_test1();

	materia_source();

	character();


	std::cout << "\nDone" << std::endl;
	system("leaks -q interface");

	return 0;
}
