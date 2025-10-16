#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "WrongAnimal.h"
#include "WrongCat.h"

#include <iostream>

void	TestCorrectAnimals()
{
	std::cout << "\n\033[36m  Correct Animal Tests \033[0m\n";

	const Animal* baseAnimal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << "\nTypes:\n";
	std::cout << "- Dog: " << dog->getType() << std::endl;
	std::cout << "- Cat: " << cat->getType() << std::endl;

	std::cout << "\nSounds:\n";
	baseAnimal->makeSound();
	dog->makeSound();
	cat->makeSound();

	std::cout << std::endl;
	delete baseAnimal;
	delete dog;
	delete cat;

	std::cout << std::endl;
}

void	TestWrongAnimals()
{
	std::cout << "\n\033[33m Wrong Animal Tests \033[0m\n";

	const WrongAnimal* baseWrong = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << "\nTypes:\n";
	std::cout << "- WrongAnimal: " << baseWrong->getType() << std::endl;
	std::cout << "- WrongCat: " << wrongCat->getType() << std::endl;

	std::cout << "\nSounds:\n";
	baseWrong->makeSound();
	wrongCat->makeSound();

	std::cout << std::endl;
	delete baseWrong;
	delete wrongCat;

	std::cout << std::endl;
}

void	TestCopyAndAssignment()
{
	std::cout << "\n\033[35m Copy Constructor & Assignment Operator  \033[0m\n";

	std::cout << "\n- Dog Copy Test -\n";
	Dog dog1;
	Dog dog2(dog1);

	std::cout << "\n- Dog Assignment Test -\n";
	Dog dog3;
	dog3 = dog1;

	std::cout << "\n- Des   -\n";
}

int main()
{

	TestCorrectAnimals();

	TestWrongAnimals();

	TestCopyAndAssignment();



	std::cout << "\n\033[31m Leak Report 033[0m\n";
	system("leaks -q Polymorphism");

	return 0;
}
