#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "Brain.h"

#include <iostream>


void	Subject()
{
	int size = 10;

	Animal *animals[size];

	std::cout << " create and fill an array of Animal objects  \n";
	for (int i = 0; i < size; i++)
	{
		(i % 2 == 0) ? animals[i] = new Dog() : animals[i] = new Cat();

		std::cout << std::endl;
	}


	std::cout << "\n \ndelete every Animal  \n";
	for (int i = 0; i < size; i++)
	{
		delete animals[i];
		animals[i] = NULL;

		std::cout << std::endl;
	}

}

void	DogIdeas()
{	
	/*
		You declared the pointer as const Dog* dog, meaning:
			You promise not to modify the Dog object through this pointer.
	*/

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
void TestCopyAndAssignment()
{
    std::cout << "\n\t Original Cat \n" << std::endl;

    Cat original;
    original.AddIdea("I will go to Sweden");
    original.AddIdea("I will go to Norway");

    Cat copy(original); // copy constructor

    std::cout << "Copy #0: " << copy.GetIdeaByIndex(0) << std::endl;
    std::cout << "Copy #1: " << copy.GetIdeaByIndex(1) << std::endl;


    Cat Assgin;
    Assgin = original; // copy assignment


    std::cout << "Assign #0: " << Assgin.GetIdeaByIndex(0) << std::endl;
    std::cout << "Assign  #1: " << Assgin.GetIdeaByIndex(1) << std::endl;

}



int main()
{

	Subject();

	DogIdeas();

	TestCopyAndAssignment();


	std::cout << std::endl;
	system("leaks -q fire");

	return (0);
}
