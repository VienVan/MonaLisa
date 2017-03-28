#include <iomanip>
#include <assert.h>
#include <iostream>
#include <fstream>
#include <string>
#include "ControlModule.h"
using namespace std;

int main()
{

	BST<Art> *inventoryTitle = new BST<Art>;
	BST<Art> *inventoryArtist = new BST<Art>;
	Art artTitle;
	Art artArtist;
	ofstream outfile;
	ifstream infile;
	string inName, outName, temp, title, artist, genre, medium, prompt;
	int count;
	int info = 0;
	int year = 0;
	double price = 0;

	artTitle.sortByTitle = true;

	cout << "Welcome to Project!" << endl << endl;

	infile.open("input.txt");
	do
	{
		getline(infile,temp);
		getline(infile,temp);
		getline(infile,temp);
		getline(infile,temp);
		getline(infile,temp);
		getline(infile,temp);
		info ++;
	}while(getline(infile,temp));
	count = info;

	infile.clear();
	infile.seekg(0, ios::beg);
	cout << "CIS 22C\nFinal Project\nTeam #6\nMembers:" << endl;
	cout << "\tYun Cao, Vincent Ha, Jimmy Nguyen, Kota Iwamoto, Vien Van\n";

	// coping art object to artArtist

	do
	{

		getline(infile,title);
		if(title.empty())
		{
			break;
		}
		artTitle.setTitle(title);
		artArtist.setTitle(title);

		getline(infile,artist);
		artTitle.setArtist(artist);
		artArtist.setArtist(artist);

		getline(infile,medium);
		artTitle.setMedium(medium);
		artArtist.setMedium(medium);


		getline(infile,genre);
		artTitle.setType(genre);
		artArtist.setType(genre);


		infile >> year;
		artTitle.setYear(year);
		artArtist.setYear(year);


		infile >> price;
		artTitle.setPrice(price);
		artArtist.setPrice(price);


		infile >> ws;
		inventoryTitle->insert(artTitle);
		inventoryArtist->insert(artArtist);


	}while(!infile.eof());

	infile.close();
	Art a = inventoryArtist->getRoot();
	cout << a << endl;
	inventoryArtist->remove(a);
	cout << "new art inventory" << endl;
	inventoryArtist->inOrderPrint(cout);
//	infile.open("Customer.txt");


	outfile.open("output.txt");

//
//	ControlModule runner(inventoryTitle, inventoryArtist);
//	runner.userInteraction();


	cout << "Thank you! Goodbye!" << endl;
	return 0;
}
