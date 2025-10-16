#pragma once

#include <iostream>

class Animal
{
protected:
	std::string type;

public :
	Animal();
	Animal(const Animal &src);
	virtual ~Animal();
	Animal &operator=(const Animal &src);

	const std::string &getType() const;

	virtual void makeSound() const;

};
