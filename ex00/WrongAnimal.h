#pragma once

#include <string>

class WrongAnimal
{
protected:
	std::string type;

public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &src);
	WrongAnimal &operator=(const WrongAnimal &src);
	virtual ~WrongAnimal();

	void makeSound() const;

	const std::string &getType() const;


};
