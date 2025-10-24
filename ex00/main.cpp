/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 13:04:34 by ajelloul          #+#    #+#             */
/*   Updated: 2025/10/24 09:33:35 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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

// resources : https://isocpp.org/wiki/faq/virtual-functions


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

int main()
{

	TestCorrectAnimals();

	TestWrongAnimals();

	std::cout << "\n\033[31m Leak Report 033[0m\n";
	system("leaks -q Polymorphism");

	return 0;
}
