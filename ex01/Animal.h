#pragma once

#include <iostream>

class Animal
{
protected:
	std::string type;

public :
	Animal();
	Animal(const Animal &src);
	Animal &operator=(const Animal &src);
	virtual ~Animal();

	const std::string &getType() const;

	virtual void makeSound() const;

};
