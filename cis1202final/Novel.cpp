#include "Novel.h"
#include <iostream>

Novel::Novel()
{
	Book::Book();
	chapters = 0;
	return;
}

void Novel::storeInfo(string tempTitle, string tempAuth, string tempSeries, Genres tempGen, Subgenres tempSub, int tempPgs, int tempChaps)
{
	Book::storeInfo(tempTitle, tempAuth, tempSeries, tempGen, tempSub, tempPgs);
	chapters = tempChaps;
	return;
}

void Novel::setInfo()
{
	int intGen, intSub, pgs, chaps;
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
	cout << "How many chapters?\n";
	cin >> chaps;
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
	Novel::storeInfo(name, writer,series , newGen, newSub, pgs, chaps);
	return;
}