#pragma once

#include "AAnimal.h"
#include "Brain.h"

class Dog : public AAnimal
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