/*

 * Vincent Ha

 * CIS 22C, Winter 2017

 */

#include <iomanip>
#include "Art.h"

Art::Art(string t, string a, string g, string m, double p, unsigned int y){
	title = t;
	artist = a;
	genre = g;
	medium = m;
	price = p;
	year = y;
}

void Art::setTitle(string t){
	title = t;
}

void Art::setArtist(string a){
	artist = a;
}

void Art::setGenre(string g){
	genre = g;
}

void Art::setMedium(string m){
	medium = m;
}

void Art::setPrice(double p){
	price = p;
}

void Art::setYear(unsigned int y){
	year = y;
}

string Art::getTitle(){
	return title;
}

string Art::getArtist(){
	return artist;
}

string Art::getGenre(){
	return genre;
}

string Art::getMedium(){
	return medium;
}

double Art::getPrice(){
	return price;
}

unsigned int Art::getYear(){
	return year;
}

ostream& operator<<(ostream& os, const Art& art){
	os << art.artist << endl;
	os << art.title << ", " << art.year << endl;
	os << art.medium << endl;
	os << "$" << art.price << endl;
	return os;
}

bool Art::operator==(const Art& art){
	return artist == art.title && title == art.title && year == art.year;
}

bool Art::operator<(const Art& art){
	if(title == art.title){
		if(artist == art.artist){
			if(year == art.year)
				return false;
			else
				return year < art.year;
		} else
			return artist < art.artist;
	} else
		return title < art.title;
}


bool Art::operator>(const Art& art){
	if(title == art.title){
			if(artist == art.artist){
				if(year == art.year)
					return false;
				else
					return year > art.year;
			} else
				return artist > art.artist;
		} else
			return title > art.title;
}
