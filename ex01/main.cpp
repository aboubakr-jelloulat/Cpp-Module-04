#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "Brain.h"

#include <iostream>


void	Subject()
{
	int size = 10;

	Animal *animals[size];

	std::cout << "\n\033[36m  create and fill an array of Animal objects  \033[0m\n";
	for (int i = 0; i < size; i++)
	{
		(i % 2 == 0) ? animals[i] = new Dog() : animals[i] = new Cat();

		std::cout << std::endl;
	}


	std::cout << "\n\033[36m  \ndelete every Animal  \033[0m\n";
	for (int i = 0; i < size; i++)
	{
		delete animals[i];

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
    original.AddIdea("I will go to Sweden.");
    original.AddIdea("I will go to Norway.");

    std::cout << "Original Cat idea #0: " << original.GetIdeaByIndex(0) << std::endl;
    std::cout << "Original Cat idea #1: " << original.GetIdeaByIndex(1) << std::endl;

    std::cout << "\n\t Copy Constructor Test ****  \n" << std::endl;
    Cat copyCtorCat(original); // copy constructor

    std::cout << "Original Cat idea #0: " << original.GetIdeaByIndex(0) << std::endl;
    std::cout << "CopyCtor Cat idea #0: " << copyCtorCat.GetIdeaByIndex(0) << std::endl;

    std::cout << "\n Adding a new idea to Original Cat **** " << std::endl;
    original.AddIdea("I will work at Ericsson.");

    std::cout << "Original Cat idea #2: " << original.GetIdeaByIndex(2) << std::endl;
    std::cout << "CopyCtor Cat idea #2: " << copyCtorCat.GetIdeaByIndex(2) << "  walo maytba3" << std::endl;

    std::cout << "\n\t Copy Assignment Test ****\n" << std::endl;
    Cat copyAssignCat;
    copyAssignCat = original; // copy assignment

    std::cout << "Original Cat idea #0: " << original.GetIdeaByIndex(0) << std::endl;
    std::cout << "Original Cat idea #1: " << original.GetIdeaByIndex(1) << std::endl;
    std::cout << "Original Cat idea #2: " << original.GetIdeaByIndex(2) << std::endl;

    std::cout << "\nCopyAssign Cat ideas:" << std::endl;
    std::cout << "CopyAssign Cat idea #0: " << copyAssignCat.GetIdeaByIndex(0) << std::endl;
    std::cout << "CopyAssign Cat idea #1: " << copyAssignCat.GetIdeaByIndex(1) << std::endl;
    std::cout << "CopyAssign Cat idea #2: " << copyAssignCat.GetIdeaByIndex(2) << "  (should match original at copy time)" << std::endl;

    std::cout << "\n\tDestructors will be called ****\n" << std::endl;
}



int main()
{

	Subject();

	DogIdeas();

	TestCopyAndAssignment();


	std::cout << "\n\033[31m Leak Report 033[0m\n";
	system("leaks -q fire");

	return (0);
}
