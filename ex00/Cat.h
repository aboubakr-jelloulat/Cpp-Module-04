#pragma once

#include "Animal.h"

class Cat : public Animal
{
public:
	Cat();
	Cat(const Cat &src);
	Cat &operator=(const Cat &src);
	virtual ~Cat();

	void makeSound() const;

};