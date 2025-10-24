#include "Brain.h"

#include <iostream>

Brain::Brain() : _idea_count(0)
{
	std::cout << "Default constructor of Brain called." << std::endl;
}

Brain::Brain(const Brain &src)
{
	std::cout << "Copy constructor of Brain called." << std::endl;

	this->_idea_count = src._idea_count;

	for (int i = 0; i < _idea_count; i++)
	{
		this->ideas[i] = src.ideas[i];
	}
}

Brain &Brain::operator=(const Brain &src)
{
	std::cout << "Copy assignment operator of Brain called." << std::endl;

	if (this == &src)
		return (*this);

	_idea_count = src._idea_count;

	for (int i = 0; i < _idea_count; i++)
	{
		this->ideas[i] = src.ideas[i];
	}

	return (*this); 
}


Brain::~Brain()
{
	std::cout << "Destructor of Brain called." << std::endl;
}

void Brain::AddIdea(std::string idea)
{
	if (this->_idea_count == max)
	{
		std::cout << "Your brain is full no more space for ideas" << std::endl;

		return ;
	}

	ideas[_idea_count] = idea;
	_idea_count++;

	std::cout << "Added " << _idea_count << " new idea"  << (_idea_count > 1 ? "s." : ".") << std::endl;
}

std::string &Brain::GetIdeaByIndex(int index)
{
	/*
		static means this variable is created once and lives for the entire program lifetime
			not just inside the function call
	*/
	static std::string NotFound = "404 Not Found";

    if (index < 0 || index >= 100)
        return NotFound;

    return ideas[index];
}
