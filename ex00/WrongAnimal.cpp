#include "WrongAnimal.h"

#include <iostream>

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "Default constructor of WrongAnimal called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) : type(src.type)
{
	std::cout << "Copy constructor of WrongAnimal called." << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
	std::cout << "Copy assignment operator of WrongAnimal called." << std::endl;

	if (this != &src)
		type = src.type;

	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor of WrongAnimal called." << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound!" << std::endl;
}

const std::string &WrongAnimal::getType() const
{
	return type;
}