#include "AAnimal.h"
#include "Cat.h"
#include "Dog.h"
#include "Brain.h"

#include <iostream>


void	Subject()
{
	int size = 4;

	AAnimal *animals[size];

	std::cout << "\n  create and fill an array of Animal objects  \n";
	for (int i = 0; i < size; i++)
	{
		(i % 2 == 0) ? animals[i] = new Dog() : animals[i] = new Cat();

		std::cout << std::endl;
	}


	std::cout << "\n  delete every Animal  \n";
	for (int i = 0; i < size; i++)
	{
		delete animals[i];

		std::cout << std::endl;
	}

}

void	DogIdeas()
{	

	Dog* d = new Dog();

	for (int i = 0; i < 100; i++)
		d->AddIdea("I will go to Sweden.");
	
	d->AddIdea("I will go to Norway.");
	d->AddIdea("I will go to Norway.");

	std::cout << std::endl;

	std::cout << "\nIdea #99: " << d->GetIdeaByIndex(99) << std::endl;
	std::cout << "Idea #101 (out of range): " << d->GetIdeaByIndex(101) << std::endl;


	std::cout << std::endl;
	delete d;

}

void	TestCpAndAssign()
{
	Dog* d = new Dog();

	d->AddIdea("hej");
	d->AddIdea("hello");

	Dog cp(*d);
	std::cout << cp.GetIdeaByIndex(0) << std::endl;
	std::cout << cp.GetIdeaByIndex(1) << std::endl;

	delete d;

}

int main()
{

	Subject();

	DogIdeas();

	
	TestCpAndAssign();


	std::cout << "\n";
	system("leaks -q abstract"); 

	return (0);
}
