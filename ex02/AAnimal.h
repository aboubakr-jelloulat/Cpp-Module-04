#pragma once

#include <iostream>
#include <string>

class AAnimal
{
public:
	AAnimal();
	AAnimal(const AAnimal &src);
	AAnimal &operator=(const AAnimal &src);
	virtual ~AAnimal();

	virtual void makeSound() const = 0; // pure virtual member function

	const std::string &getType() const;

protected:

	std::string type;
};
