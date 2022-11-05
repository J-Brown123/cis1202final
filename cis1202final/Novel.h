#pragma once
#ifndef NOVEL_H
#define NOVEL_H
#include "Book.h"

class Novel : public Book
{
private:
	int chapters;
public:
	Novel();
	int getChapters()
	{return chapters;}
	void setInfo();
	void storeInfo(string, string, string, Genres, Subgenres, int, int);
};

#endif // !NOVEL_H
