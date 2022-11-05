#pragma once
#ifndef COMP_H
#define COMP_H
#include "Book.h"

class Comp : public Book
{
private:
	int stories;
public:
	Comp();
	int getStories()
	{return stories;}
	void setInfo();
	void storeInfo(string, string, string, Genres, Subgenres, int, int);
};

#endif
