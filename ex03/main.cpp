#include "AMateria.h"
#include "Cure.h"
#include "Character.h"
#include "ICharacter.h"
#include "Ice.h"
#include "MateriaSource.h"
#include <iostream>
#include <cstdlib>
#include <cassert>





// static void SubjectTestes()
// {
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());

// 	ICharacter* me = new Character("me");
// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");

// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);

// 	ICharacter* bob = new Character("bob");
// 	me->use(0, *bob);
// 	me->use(1, *bob);

// 	delete bob;
// 	delete me;
// 	delete src;

// }



// void Amateria_Tests()
// {
// 	std::cout << std::endl << "**** AMATERIA ****" << std::endl;

// 	MateriaSource *src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());

// 	AMateria *a_materia;
// 	a_materia = src->createMateria("ice");

// 	AMateria *a_materia2;
// 	a_materia2 = a_materia->clone(); // assign
// 	assert(a_materia2->getType() == "ice");

// 	AMateria *a_materia3;
// 	a_materia3 = src->createMateria("cure");

// 	*a_materia2 = *a_materia3;
// 	*a_materia2 = *a_materia2;
// 	assert(a_materia2->getType() == "ice"); // doesn’t make sense 

// 	ICharacter *bob = new Character("bob");
// 	a_materia->use(*bob);

// 	ICharacter *none = new Character();
// 	a_materia->use(*none);

// 	delete src;
// 	delete a_materia;
// 	delete a_materia2;
// 	delete a_materia3;
// 	delete bob;
// 	delete none;
// }


// void ice_cure()
// {
//     std::cout << std::endl << "*** ICE & Cure ***" << std::endl;

//     MateriaSource *src = new MateriaSource();
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());

//     AMateria *ice = src->createMateria("ice");
//     assert(ice->getType() == "ice");

//     AMateria *cure = src->createMateria("cure");
//     assert(cure->getType() == "cure");



//     delete src;
//     delete ice;
//     delete cure;
// }



void materia_source()
{
    std::cout << std::endl << "**** MATERIA_SOURCE  ****" << std::endl;

    MateriaSource *source_main = new MateriaSource();
    source_main->learnMateria(new Ice());
    source_main->learnMateria(new Ice());
    source_main->learnMateria(new Ice());
    source_main->learnMateria(new Ice());

    AMateria *external_ice = new Ice();
    source_main->learnMateria(external_ice); // Should not be added source full

    source_main->learnMateria(NULL); // Should be ignored

    // Try creating a non-existent materia type
    AMateria *unknown_materia = source_main->createMateria("fire");
    assert(unknown_materia == NULL);

    // Copy constructor test for MateriaSource
    MateriaSource source_copy(*source_main);
    AMateria *copied_ice = source_copy.createMateria("ice");
    assert(copied_ice && copied_ice->getType() == "ice");


    MateriaSource *source_challenge = new MateriaSource();
	source_challenge->learnMateria(new Ice());
    source_challenge->learnMateria(new Cure());
    source_challenge->learnMateria(new Ice());
    source_challenge->learnMateria(new Cure());

    // Create multiple materia and check their types
    AMateria *first_ice = source_challenge->createMateria("ice");
    AMateria *first_cure = source_challenge->createMateria("cure");
    AMateria *second_ice = source_challenge->createMateria("ice");
    AMateria *second_cure = source_challenge->createMateria("cure");
    AMateria *should_be_null = source_challenge->createMateria("fire"); 

    assert(first_ice && first_ice->getType() == "ice");
    assert(first_cure && first_cure->getType() == "cure");
    assert(second_ice && second_ice->getType() == "ice");
    assert(second_cure && second_cure->getType() == "cure");
    assert(should_be_null == NULL);


    delete source_main;
    delete external_ice;
    delete unknown_materia;
    delete copied_ice;

    delete source_challenge;
    delete first_ice;
    delete first_cure;
    delete second_ice;
    delete second_cure;

}


int main()
{
	
	// SubjectTestes();

	// Amateria_Tests();

	// ice_cure();

	materia_source();




	std::cout << std::endl;
	system("leaks -q interface");

	return 0;
}
