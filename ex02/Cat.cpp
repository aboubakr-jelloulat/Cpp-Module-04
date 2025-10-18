#include "Cat.h"

#include <iostream>

Cat::Cat() : brain(new Brain())
{
	std::cout << "Default constructor of Cat called." << std::endl;

	this->type = "Cat";
}

Cat::Cat(const Cat &src)   : AAnimal(src)
{
	std::cout << "Copy constructor of Cat called." << std::endl;

	type = src.type;

	brain = new Brain(*src.brain);
}

Cat &Cat::operator=(const Cat &src)
{
	std::cout << "Copy assignment operator of Cat called." << std::endl;

	if (this == &src)
		return (*this);

	this->type = src.type;
	*brain = *src.brain; // call Copy assignment operator of Brain called

	return (*this);
}


Cat::~Cat()
{
	std::cout << "Destructor of Cat called." << std::endl;
	delete brain;
}

void Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}

void Cat::AddIdea(std::string idea)
{
	brain->AddIdea(idea);
}

std::string &Cat::GetIdeaByIndex(int index)
{
	return brain->GetIdeaByIndex(index);
}
