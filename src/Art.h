/*
 * Art.h
 *
 *  Created on: Mar 6, 2017
 *  Author: Vincent_Ha
 */

#ifndef ART_H_
#define ART_H_

#include <string>
using namespace std;

class Art
{
private:
	string title;
	string artist;
	string genre;
	string medium;
	double price;
	unsigned int year;

public:
	Art(string t, string a, string g, string m, double p, unsigned int y);

	// Accessors and Manipulators
	void setTitle(string t);
	void setArtist(string a);
	void setGenre(string g);
	void setMedium(string m);
	void setPrice(double p);
	void setYear(unsigned int y);

	string getTitle();
	string getArtist();
	string getGenre();
	string getMedium();
	double getPrice();
	unsigned int getYear();

	//Operator Overloads
	friend ostream& operator<< (ostream& os, const Art& art);
	bool operator== (const Art& art);
	bool operator< (const Art& art);
	bool operator> (const Art& art);
};



#endif /* ART_H_ */
