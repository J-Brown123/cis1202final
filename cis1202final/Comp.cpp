#include "Comp.h"
#include <iostream>

Comp::Comp()
{
	stories = 0;
	return;
}

void Comp::storeInfo(string tempTitle, string tempAuth, string tempSeries, Genres tempGen, Subgenres tempSub, int tempPgs, int tempStory)
{
	Book::storeInfo(tempTitle, tempAuth, tempSeries, tempGen, tempSub, tempPgs);
	stories = tempStory;
	return;
}

void Comp::erase()
{
	title = " ";
	author = " ";
	series = " ";
	pages = 0;
	genre = NONE;
	sub = NA;
	stories = 0;
	return;
}

void Comp::setInfo()
{
	int intGen, intSub, pgs, story;
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
	cout << "How many stories are in the compilation?\n";
	cin >> story;
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
	Comp::storeInfo(name, writer, series, newGen, newSub, pgs, story);
	return;
}