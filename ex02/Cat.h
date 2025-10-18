#pragma once

#include "AAnimal.h"
#include "Brain.h"

class Cat : public AAnimal
{
	Brain *brain;

public:
	Cat();
	Cat(const Cat &src);
	Cat &operator=(const Cat &src);
	virtual ~Cat();

	void makeSound() const;

	void AddIdea(std::string idea);
	std::string &GetIdeaByIndex(int index);

};