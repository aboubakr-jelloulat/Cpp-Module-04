#pragma once

#include "Animal.h"

class Dog : public Animal
{
public:
	Dog();
	Dog(const Dog &src);
	Dog &operator=(const Dog &src);
	virtual ~Dog();

	void makeSound() const;

};