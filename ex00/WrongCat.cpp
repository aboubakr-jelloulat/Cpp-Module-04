#include "WrongCat.h"

#include <iostream>

WrongCat::WrongCat()
{
	std::cout << "Default constructor of WrongCat called." << std::endl;

	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &src)
{
	std::cout << "Copy constructor of WrongCat called." << std::endl;

	this->type = src.type;
}


WrongCat &WrongCat::operator=(const WrongCat &src)
{
	std::cout << "Copy assignment operator of WrongCat called." << std::endl;

	if (this != &src)
		this->type = src.type;

	return (*this);
}


WrongCat::~WrongCat()
{
	std::cout << "Destructor of WrongCat called." << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}
