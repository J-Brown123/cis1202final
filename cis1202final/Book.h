#pragma once
#ifndef BOOK_H
#define BOOK_H
using namespace std;
#include <string>

enum Genres { NONE, FANTASY, SCIFI, HORROR };
enum Subgenres { NA, EPIC, SWORD_SCORCERY, SPACE_OPERA };
class Book
{
protected:
	string title;
	string author;
	string series;
	Genres genre;
	Subgenres sub;
	int pages;
public:
	Book();
	string getTitle()
	{return title;}
	string getAuthor()
	{return author;}
	string getSeries()
	{return series;}
	Genres getGenre()
	{return genre;}
	Subgenres getSub()
	{return sub;}
	int getPages()
	{return pages;}
	void setInfo();
	void showGenres();
	void showSubs();
	void storeInfo(string, string, string, Genres, Subgenres, int);
};

#endif
