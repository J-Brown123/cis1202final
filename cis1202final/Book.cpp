#include "Book.h"
#include <iostream>

Book::Book()
{
	title = " ";
	author = " ";
	series = " ";
	pages = 0;
	genre = Genres::NONE;
	sub = Subgenres::NA;
	return;
}

void Book::showGenres()
{
	cout << "GENRES:\n";
	cout << "0 - N/A, 1 - FANTASY, 2 - SCI-FI, 3 - HORROR\n";
	return;
}

void Book::showSubs()
{
	cout << "SUBGENRES:\n";
	cout << "0 - N/A, 1 - EPIC FANTASY, 2 - SWORD AND SORCERY, 3 - SPACE OPERA, 4 - CYBERPUNK\n";
	return;
}

void Book::storeInfo(string tempTitle, string tempAuth, string tempSeries, Genres tempGen, Subgenres tempSub, int tempPgs)
{
	title = tempTitle;
	author = tempAuth;
	series = tempSeries;
	genre = tempGen;
	sub = tempSub;
	pages = tempPgs;
	return;
}

void Book::setInfo()
{
	int intGen, intSub, pgs;
	string name, writer, series;
	Genres newGen;
	Subgenres newSub;
	cout << "What is the title of the book?\n";
	cin.ignore();
	getline(cin, name);
	cout << "Who was the book written by?\n";
	getline(cin, writer);
	cout << "Which series is the book part of?\n";
	getline(cin, series);
	cout << "How many pages?\n";
	cin >> pgs;
	cout << "Which genre?\n";
	Book::showGenres();
	cin >> intGen;
	while (intGen < 0 || intGen > 3)
	{
		cout << "Invalid response.\n";
		cout << "Which genre?\n";
		Book::showGenres();
		cin >> intGen;
	}
	cout << "Which subgenre?\n";
	Book::showSubs();
	cin >> intSub;
	while (intSub < 0 || intSub > 4)
	{
		cout << "Invalid response.\n";
		cout << "Which subgenre?\n";
		Book::showSubs();
		cin >> intSub;
	}
	newGen = static_cast<Genres>(intGen);
	newSub = static_cast<Subgenres>(intSub);
	Book::storeInfo(name, writer, series, newGen, newSub, pgs);
	return;
}