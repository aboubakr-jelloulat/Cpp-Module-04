#pragma once

#include "Animal.h"
#include "Brain.h"

class Dog : public Animal
{
	Brain *brain;

public:
	Dog();
	Dog(const Dog &src);
	Dog &operator=(const Dog &src);
	virtual ~Dog();

	void makeSound() const;

	void AddIdea(std::string idea);
	std::string &GetIdeaByIndex(int index);

};