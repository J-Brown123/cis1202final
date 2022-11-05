// Jordan Brown 
// CIS 1202.800
// Oct. 20, 2022

#include <iostream>
#include"Book.h"
#include "Comp.h"
#include "Novel.h"
#include <iomanip>
#include <fstream>

using namespace std;
const int SIZE = 20;

//Prototypes
int menu();
void dataMenu(Novel[], Comp[], int, int);
int displayOne(string, Novel[], int);
int displayOne(string, Comp[], int);
void displayLibrary(Novel[], Comp[], int, int);
void outputLibrary(Novel[], Comp[], int, int, fstream&, fstream&);
void inputLibrary(Novel[], Comp[], int&, int&, fstream&, fstream&);
void authorTotal(Novel[], Comp[], int, int, string);
void genreTotal(Novel[], Comp[], int, int, int);
void seriesTotal(Novel[], Comp[], int, int, string);
void findLongest(Novel[], Comp[], int, int);
void findShortest(Novel[], Comp[], int, int);

int main()
{
	//Arrays and variables
	Novel nov[SIZE];
	Comp com[SIZE];
	int selection, type, choice, find, num1 = 0, num2 = 0;
	string search;

	//Open file
	fstream file1, file2;
	file1.open("novLibrary.dat", ios::out | ios::binary | ios::in);
	file2.open("comLibrary.dat", ios::out | ios::binary | ios::in);
	if (!file1)
	{
		file1.open("novLibrary.dat", ios::out | ios::binary | ios::trunc);
		file1.close();
	}
	if (!file2)
	{
		file2.open("comLibrary.dat", ios::out | ios::binary | ios::trunc);
		file2.close();
	}


	//Main Menu and Switch
	do
	{
		selection = menu();
		switch (selection)
		{
		case 1: 
		{
			//Get book info
			int choice;
			cout << "Is this a novel or a compilation?\n1 - Novel\n2 - Compilation\n";
			cin >> choice;
			while (choice < 1 || choice > 2)
			{
				cout << "Invalid response.\n";
				cout << "Is this a novel or a compilation?\n1 - Novel\n2 - Compilation\n";
				cin >> choice;
			}
			if (choice == 1)
			{
				nov[num1].setInfo();
				num1++;
			}
			else
			{
				com[num2].setInfo();
				num2++;
			}
		}
			cout << endl;
			break;
		case 2: displayLibrary(nov, com, num1, num2);
			break;
		case 3: {
			cout << "Type the title to search for:\n";
			cin.ignore();
			getline(cin, search);
			cout << "Is this a novel or a compilation?\n1 - Novel\n2 - Compilation\n";
			cin >> type;
			while (type < 1 || type > 2)
			{
				cout << "Invalid response.\n";
				cout << "Is this a novel or a compilation?\n1 - Novel\n2 - Compilation\n";
				cin >> type;
			}
			if (type == 1)
				find = displayOne(search, nov, num1);
			if (type == 2)
				find = displayOne(search, com, num2);
			if (find == -1)
			{
				cout << "Title not found.\n\n";
				break;
			}
			if (find != -1 && type == 1)
			{
				cout << setw(11) << "Title:" << nov[find].getTitle() << endl;
				cout << setw(11) << "Author:" << nov[find].getAuthor() << endl;
				cout << setw(11) << "Series:" << nov[find].getSeries() << endl;
				cout << setw(11) << "Pages:" << nov[find].getPages() << endl;
				cout << setw(11) << "Chapters:" << nov[find].getChapters() << endl;

				if (nov[find].getGenre() == 0)
					cout << setw(11) << "Genre:" << "There is no genre" << endl;
				else if (nov[find].getGenre() == 1)
					cout << setw(11) << "Genre:" << "Fantasy" << endl;
				else if (nov[find].getGenre() == 2)
					cout << setw(11) << "Genre:" << "Sci-Fi" << endl;
				else if (nov[find].getGenre() == 3)
					cout << setw(11) << "Genre:" << "Horror" << endl;

				if (nov[find].getSub() == 0)
					cout << setw(11) << "Subgenre:" << "There is no subgenre" << endl;
				else if (nov[find].getSub() == 1)
					cout << setw(11) << "Subgenre:" << "Epic Fantasy" << endl;
				else if (nov[find].getSub() == 2)
					cout << setw(11) << "Subgenre:" << "Sword and Sorcery" << endl;
				else if (nov[find].getSub() == 3)
					cout << setw(11) << "Subgenre:" << "Space Opera" << endl;
			}
			else if (find != -1 && type == 2)
			{
				cout << setw(11) << "Title:" << com[find].getTitle() << endl;
				cout << setw(11) << "Author:" << com[find].getAuthor() << endl;
				cout << setw(11) << "Series:" << com[find].getSeries() << endl;
				cout << setw(11) << "Pages:" << com[find].getPages() << endl;
				cout << setw(11) << "Chapters:" << com[find].getStories() << endl;

				if (com[find].getGenre() == 0)
					cout << setw(11) << "Genre:" << "There is no genre" << endl;
				else if (com[find].getGenre() == 1)
					cout << setw(11) << "Genre:" << "Fantasy" << endl;
				else if (com[find].getGenre() == 2)
					cout << setw(11) << "Genre:" << "Sci-Fi" << endl;
				else if (com[find].getGenre() == 3)
					cout << setw(11) << "Genre:" << "Horror" << endl;

				if (com[find].getSub() == 0)
					cout << setw(11) << "Subgenre:" << "There is no subgenre" << endl;
				else if (com[find].getSub() == 1)
					cout << setw(11) << "Subgenre:" << "Epic Fantasy" << endl;
				else if (com[find].getSub() == 2)
					cout << setw(11) << "Subgenre:" << "Sword and Sorcery" << endl;
				else if (com[find].getSub() == 3)
					cout << setw(11) << "Subgenre:" << "Space Opera" << endl;
			}
		}
			cout << endl;
			break;
		case 4: cout << "This will overwrite the existing file. Is that ok?\n1 - Yes\n2 - No.\n";
			cin >> choice;
			while (choice < 1 || choice > 2)
			{
				cout << "Invalid response.\n1 - Yes\n2 - No\n";
				cin >> choice;
			}
			if (choice == 1)
			{
				outputLibrary(nov, com, num1, num2, file1, file2);
				cout << endl;
				break;
			}
			else
			{
				cout << endl;
				break;
			}
		case 5: cout << "This will delete the current inputted data and replace with the file. Is that ok?\n1 - Yes\n2 - No.\n";
			cin >> choice;
			while (choice < 1 || choice > 2)
			{
				cout << "Invalid response.\n1 - Yes\n2 - No\n";
				cin >> choice;
			}
			if (choice == 1)
			{
				inputLibrary(nov, com, num1, num2, file1, file2);
				cout << endl;
				break;
			}
			else
			{
				cout << endl;
				break;
			}
		case 6: dataMenu(nov, com, num1, num2);
			break;
		case 7: cout << "Exiting.\n";
			file1.close();
			file2.close();
			return 0;
			break;
		}

	} while (selection != 7);
	file1.close();
	file2.close();
	return 0;
}

int menu()
{
	int selection;
	cout << "Choose from the following:\n";
	cout << "1 - Input New Book Info\n2 - Display All Books\n";
	cout << "3 - Display One Book\n4 - Save to File\n5 - Load from File\n";
	cout << "6 - Book Data\n7 - Exit\n";
	cin >> selection;
	while (selection < 1 || selection > 7)
	{
		cout << "Invalid response.\n";
		cout << "Choose from the following:\n";
		cout << "1 - Input New Book Info\n2 - Display All Books\n";
		cout << "3 - Display One Book\n4 - Save to File\n5 - Load from File\n";
		cout << "6 - Book Data\n7 - Exit\n";
		cin >> selection;
	}
	return selection;
}

void displayLibrary(Novel novs[], Comp comps[], int val1, int val2)
{
	cout << "The novels in the library are:\n";
	for (int i = 0; i < val1; i++)
	{
		cout << setw(11) << "Title:" << novs[i].getTitle() << endl;
		cout << setw(11) << "Author:" << novs[i].getAuthor() << endl;
		cout << setw(11) << "Series:" << novs[i].getSeries() << endl;
		cout << setw(11) <<  "Pages:" << novs[i].getPages() << endl;
		cout << setw(11) << "Chapters:" << novs[i].getChapters() << endl;
		
		if (novs[i].getGenre() == 0)
			cout << setw(11) << "Genre:" << "There is no genre" << endl;
		else if (novs[i].getGenre() == 1)
			cout << setw(11) << "Genre:" << "Fantasy" << endl;
		else if (novs[i].getGenre() == 2)
			cout << setw(11) << "Genre:" << "Sci-Fi" << endl;
		else if (novs[i].getGenre() == 3)
			cout << setw(11) << "Genre:" << "Horror" << endl;

		if (novs[i].getSub() == 0)
			cout << setw(11) << "Subgenre:" << "There is no subgenre" << endl;
		else if (novs[i].getSub() == 1)
			cout << setw(11) << "Subgenre:" << "Epic Fantasy" << endl;
		else if (novs[i].getSub() == 2)
			cout << setw(11) << "Subgenre:" << "Sword and Sorcery" << endl;
		else if (novs[i].getSub() == 3)
			cout << setw(11) << "Subgenre:" << "Space Opera" << endl;
		else if (novs[i].getSub() == 4)
			cout << setw(11) << "Subgenre:" << "Cyberpunk" << endl;
		cout << endl;
	}
	cout << endl;

	cout << "The compilations in the library are:\n";
	for (int i = 0; i < val2; i++)
	{
		cout << setw(11) << "Title:" << comps[i].getTitle() << endl;
		cout << setw(11) << "Author:" << comps[i].getAuthor() << endl;
		cout << setw(11) << "Series:" << comps[i].getSeries() << endl;
		cout << setw(11) << "Pages:" << comps[i].getPages() << endl;
		cout << setw(11) << "Chapters:" << comps[i].getStories() << endl;
		
		if (comps[i].getGenre() == 0)
			cout << setw(11) << "Genre:" << "There is no genre" << endl;
		else if (comps[i].getGenre() == 1)
			cout << setw(11) << "Genre:" << "Fantasy" << endl;
		else if (comps[i].getGenre() == 2)
			cout << setw(11) << "Genre:" << "Sci-Fi" << endl;
		else if (comps[i].getGenre() == 3)
			cout << setw(11) << "Genre:" << "Horror" << endl;

		if (comps[i].getSub() == 0)
			cout << setw(11) << "Subgenre:" << "There is no subgenre" << endl;
		else if (comps[i].getSub() == 1)
			cout << setw(11) << "Subgenre:" << "Epic Fantasy" << endl;
		else if (comps[i].getSub() == 2)
			cout << setw(11) << "Subgenre:" << "Sword and Sorcery" << endl;
		else if (comps[i].getSub() == 3)
			cout << setw(11) << "Subgenre:" << "Space Opera" << endl;
		else if (comps[i].getSub() == 4)
			cout << setw(11) << "Subgenre:" << "Cyberpunk" << endl;
		cout << endl;
	}
	cout << endl;
	return;
}

void outputLibrary(Novel novs[], Comp comps[], int val1, int val2, fstream& file1, fstream& file2)
{
	//Overwrite data
	file1.close();
	file1.open("novLibrary.dat", ios::out | ios::binary | ios::trunc);
	file1.close();
	file1.open("novLibrary.dat", ios::in | ios::binary | ios::out);
	file2.close();
	file2.open("comLibrary.dat", ios::out | ios::binary | ios::trunc);
	file2.close();
	file2.open("comLibrary.dat", ios::in | ios::binary | ios::out);

	//Output data
	int i = 0;
	while (i < val1)
	{
		file1.write(reinterpret_cast<char*>(&novs[i]), sizeof(novs[i]));
		i++;
	}

	if (file2.eof())
		file2.clear(ios::eofbit);
	file2.seekg(0, ios::beg);
	i = 0;
	while (i < val2)
	{
		file2.write(reinterpret_cast<char*>(&comps[i]), sizeof(comps[i]));
		i++;
	}
	cout << "Writing complete.\n";
	return;
}

void inputLibrary(Novel novs[], Comp comps[], int &val1, int &val2, fstream& file1, fstream& file2)
{
	//Clear arrays
	for (int i = 0; i < SIZE; i++)
	{
		novs[i].Novel::Novel();
		comps[i].Comp::Comp();
	}

	//Input file data into arrays
	if (file1.eof())
		file1.clear(ios::eofbit);
	file1.seekg(0, ios::beg);
	val1 = 0;
	val2 = 0;
	file1.read(reinterpret_cast<char*>(&novs[val1]), sizeof(novs[val1]));
	while (file1 && val1 < SIZE)
	{
		val1++;
		file1.read(reinterpret_cast<char*>(&novs[val1]), sizeof(novs[val1]));
	}

	if (file2.eof())
		file2.clear(ios::eofbit);
	file2.seekg(0, ios::beg);
	file2.read(reinterpret_cast<char*>(&comps[val2]), sizeof(comps[val2]));
	while (file2 && val2 < SIZE)
	{
		val2++;
		file2.read(reinterpret_cast<char*>(&comps[val2]), sizeof(comps[val2]));
	}

	cout << "Reading complete.\n";
	return;
}

int displayOne(string search, Novel novs[], int num)
{
	int index = -1, i = 0;
	bool found = false;
	while (!found && i < num)
	{
		if (novs[i].getTitle() == search)
		{
			index = i;
			found = true;
		}
		i++;
	}
	return index;
}

int displayOne(string search, Comp comps[], int num)
{
	int index = -1, i = 0;
	bool found = false;
	while (!found && i < num)
	{
		if (comps[i].getTitle() == search)
		{
			index = i;
			found = true;
		}
		i++;
	}
	return index;
}

void dataMenu(Novel novs[], Comp comps[], int val1, int val2)
{
	int selection, choice;
	string search;
	cout << "Choose from the following:\n";
	cout << "1 - Amount by Author\n2 - Amount by Genre\n3 - Amount by Series\n";
	cout << "4 - Find Longest\n5 - Find Shortest\n6 - Exit to Main\n";
	cin >> selection;
	while (selection < 1 || selection > 6)
	{
		cout << "Invalid response.\n";
		cout << "Choose from the following:\n";
		cout << "1 - Amount by Author\n2 - Amount by Genre\n3 - Amount by Series\n";
		cout << "4 - Find Longest\n5 - Find Shortest\n6 - Exit to Main\n";
		cin >> selection;
	}
		switch (selection)
		{
		case 1: cout << "Which author do you want to analyze?\n";
			cin.ignore();
			getline(cin, search);
			authorTotal(novs, comps, val1, val2, search);
			cout << endl;
			break;
		case 2: cout << "Which genre do you want to analyze?\n";
			novs[0].showGenres();
			cin >> choice;
			while (choice < 0 || choice > 3)
			{
				cout << "Invalid response.\n";
				cout << "Which genre do you want to analyze?\n";
				novs[0].showGenres();
				cin >> choice;
			}
			genreTotal(novs, comps, val1, val2, choice);
			cout << endl;
			break;
		case 3: cout << "Which series do you want to analyze?\n";
			cin.ignore();
			getline(cin, search);
			seriesTotal(novs, comps, val1, val2, search);
			cout << endl;
			break;
		case 4: findLongest(novs, comps, val1, val2);
			cout << endl;
			break;
		case 5: findShortest(novs, comps, val1, val2);
			cout << endl;
			break;
		case 6: cout << "Returning to main.\n\n";
			return;
		}
	return;
}

void authorTotal(Novel novs[], Comp comps[], int val1, int val2, string search)
{
	int totalCount = 0, authCount = 0, totalPages = 0, authPages = 0;
	float percent, pgs;
	for (int i = 0; i < val1; i++)
	{
		totalCount++;
		totalPages += novs[i].getPages();
		if (novs[i].getAuthor() == search)
		{
			authPages += novs[i].getPages();
			authCount++;
		}
	}
	for (int i = 0; i < val2; i++)
	{
		totalCount++;
		totalPages += comps[i].getPages();
		if (comps[i].getAuthor() == search)
		{
			authPages += comps[i].getPages();
			authCount++;
		}
	}
	cout << "This author has written " << authCount << " works out of a total of " << totalCount << " in the library.\n";
	cout << "This author has written " << authPages << " pages out of a total of " << totalPages << " in the library.\n";
	pgs = totalPages;
	percent = authPages / pgs;
	cout << "This author has written approximately " << percent * 100 << " percent of the pages in the library.\n";
	return;
}

void genreTotal(Novel novs[], Comp comps[], int val1, int val2, int search)
{
	int totalCount = 0, genCount = 0, totalPages = 0, genPages = 0;
	float percent, pgs;
	for (int i = 0; i < val1; i++)
	{
		totalCount++;
		totalPages += novs[i].getPages();
		if (novs[i].getGenre() == search)
		{
			genPages += novs[i].getPages();
			genCount++;
		}
	}
	for (int i = 0; i < val2; i++)
	{
		totalCount++;
		totalPages += comps[i].getPages();
		if (comps[i].getGenre() == search)
		{
			genPages += comps[i].getPages();
			genCount++;
		}
	}
	cout << "This genre accounts for " << genCount << " works out of a total of " << totalCount << " in the library.\n";
	cout << "This genre accounts for " << genPages << " pages out of a total of " << totalPages << " in the library.\n";
	pgs = totalPages;
	percent = genPages / pgs;
	cout << "This genre accounts for approximately " << percent * 100 << " percent of the pages in the library.\n";
	return;
}

void seriesTotal(Novel novs[], Comp comps[], int val1, int val2, string search)
{
	int totalCount = 0, serCount = 0, totalPages = 0, serPages = 0;
	float percent, pgs;
	for (int i = 0; i < val1; i++)
	{
		totalCount++;
		totalPages += novs[i].getPages();
		if (novs[i].getSeries() == search)
		{
			serPages += novs[i].getPages();
			serCount++;
		}
	}
	for (int i = 0; i < val2; i++)
	{
		totalCount++;
		totalPages += comps[i].getPages();
		if (comps[i].getSeries() == search)
		{
			serPages += comps[i].getPages();
			serCount++;
		}
	}
	cout << "This series accounts for " << serCount << " works out of a total of " << totalCount << " in the library.\n";
	cout << "This series accounts for " << serPages << " pages out of a total of " << totalPages << " in the library.\n";
	pgs = totalPages;
	percent = serPages / pgs;
	cout << "This series accounts for approximately " << percent * 100 << " percent of the pages in the library.\n";
	return;
}

void findLongest(Novel novs[], Comp comps[], int val1, int val2)
{
	int index1, index2, max1 = 0, max2 = 0;
	for (int i = 0; i < val1; i++)
	{
		if (novs[i].getPages() > max1)
		{
			index1 = i;
			max1 = novs[i].getPages();
		}
	}
	for (int i = 0; i < val2; i++)
	{
		if (comps[i].getPages() > max2)
		{
			index2 = i;
			max2 = comps[i].getPages();
		}
	}
	cout << "The longest novel in the library by pages is " << novs[index1].getTitle() << " with " << novs[index1].getPages() << " pages.\n";
	cout << "The longest compilation in the library by pages is " << comps[index2].getTitle() << " with " << comps[index2].getPages() << " pages.\n";
	if (novs[index1].getPages() > comps[index2].getPages())
		cout << novs[index1].getTitle() << " is the longest work in the library by pages.\n";
	else if (comps[index2].getPages() > novs[index1].getPages())
		cout << comps[index2].getTitle() << " is the longest work in the library by pages.\n";
	else
		cout << novs[index1].getTitle() << " and " << comps[index2].getTitle() << " have the same number of pages, and are both the longest\n";
	return;
}

void findShortest(Novel novs[], Comp comps[], int val1, int val2)
{
	int index1 = 0, index2 = 0, min1 = novs[0].getPages(), min2 = comps[0].getPages();
	for (int i = 0; i < val1; i++)
	{
		if (novs[i].getPages() < min1)
		{
			index1 = i;
			min1 = novs[i].getPages();
		}
	}
	for (int i = 0; i < val2; i++)
	{
		if (comps[i].getPages() < min2)
		{
			index2 = i;
			min2 = comps[i].getPages();
		}
	}
	cout << "The shortest novel in the library by pages is " << novs[index1].getTitle() << " with " << novs[index1].getPages() << " pages.\n";
	cout << "The shortest compilation in the library by pages is " << comps[index2].getTitle() << " with " << comps[index2].getPages() << " pages.\n";
	if (novs[index1].getPages() > comps[index2].getPages())
		cout << novs[index1].getTitle() << " is the shortest work in the library by pages.\n";
	else if (comps[index2].getPages() > novs[index1].getPages())
		cout << comps[index2].getTitle() << " is the shortest work in the library by pages.\n";
	else
		cout << novs[index1].getTitle() << " and " << comps[index2].getTitle() << " have the same number of pages, and are both the shortest.\n";
	return;
}