#include "Cat.h"

#include <iostream>

Cat::Cat()
{
	std::cout << "Default constructor of Cat called." << std::endl;

	this->type = "Cat";
}

Cat::Cat(const Cat &src)   : Animal(src)
{
	std::cout << "Copy constructor of Cat called." << std::endl;

	type = src.type;
}

Cat::~Cat()
{
	std::cout << "Destructor of Cat called." << std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
	std::cout << "Copy assignment operator of Cat called." << std::endl;

	if (this == &src)
		return (*this);

	this->type = src.type;

	return (*this);
}


void Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}
