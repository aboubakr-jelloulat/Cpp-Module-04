#include "Dog.h"

#include <iostream>

Dog::Dog() : brain(new Brain())
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
	this->brain = new Brain(*src.brain);
}


Dog &Dog::operator=(const Dog &src)
{
	std::cout << "Copy assignment operator of Dog called." << std::endl;

	if (this != &src)
	{
		type = src.type;
		*this->brain = *src.brain;
	}

	return (*this);
}


Dog::~Dog()
{
	std::cout << "Destructor of Dog called." << std::endl;
	delete brain;
}

void Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}

void Dog::AddIdea(std::string idea)
{
	brain->AddIdea(idea);
}

std::string &Dog::GetIdeaByIndex(int index)
{
	return brain->GetIdeaByIndex(index);
}
