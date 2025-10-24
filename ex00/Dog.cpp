#include "Dog.h"

#include <iostream>

Dog::Dog()
{
	std::cout << "Default constructor of Dog called." << std::endl;
	this->type = "Dog";
}
/*
	If you want to call the Animal copy constructor (not its default constructor)
	you must explicitly chain it in the Dog copy constructo
*/

Dog::Dog(const Dog &src)
{
	std::cout << "Copy constructor of Dog called." << std::endl;

	this->type = src.type;
}


Dog &Dog::operator=(const Dog &src)
{
	std::cout << "Copy assignment operator of Dog called." << std::endl;

	if (this != &src)
		type = src.type;

	return (*this);
}


Dog::~Dog()
{
	std::cout << "Destructor of Dog called." << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}
