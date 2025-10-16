#pragma once

#include "WrongAnimal.h"

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	WrongCat(const WrongCat &src);
	virtual ~WrongCat();
	WrongCat &operator=(const WrongCat &src);

	void makeSound() const;
};
