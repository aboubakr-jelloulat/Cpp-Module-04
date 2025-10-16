#pragma once

#include <string>

class Brain
{
	static const int MAX= 100;
	std::string ideas[MAX];
	int _idea_count;

public:
	Brain();
	Brain(const Brain &src);
	Brain &operator=(const Brain &src);
	virtual ~Brain();

	void AddIdea(std::string idea);
	std::string &GetIdeaByIndex(int index);

	
};
