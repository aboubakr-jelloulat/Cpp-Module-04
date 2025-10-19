#include "Animal.h"

#include <iostream>

Animal::Animal() : type("Animal")
{
	std::cout << "Default constructor of Animal called." << std::endl;
}

Animal::Animal(const Animal &src) : type(src.type)
{
	std::cout << "Copy constructor of Animal called." << std::endl;
}

Animal &Animal::operator=(const Animal &src)
{
	std::cout << "Copy assignment operator of Animal called." << std::endl;

	if (this != &src)
		this->type = src.type;

	return (*this);
}

Animal::~Animal()
{
	std::cout << "Destructor of Animal called." << std::endl;
}

const std::string &Animal::getType() const
{
	return type;
}



void Animal::makeSound() const
{
	std::cout << "Animal sound!" << std::endl;
}

