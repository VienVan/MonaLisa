/*

 * Vincent Ha

 * CIS 22C, Winter 2017

 */

#include <iomanip>
#include "Art.h"
Art::Art() : title(""), artist(""), type(""), medium(""), price(0.0), year(0), sortByTitle(true){}

/*

 * Vincent Ha

 * CIS 22C, Winter 2017

 */

#include <iomanip>
#include <iostream>
#include <string>
#include "Art.h"

Art::Art(string t, string a, string g, string m, double p, unsigned int y) {
	title = t;
	artist = a;
	type = g;
	medium = m;
	price = p;
	year = y;
}

void Art::setTitle(string t) {
	title = t;
}

void Art::setArtist(string a) {
	artist = a;
}

void Art::setType(string g) {
	type = g;
}

void Art::setMedium(string m) {
	medium = m;
}

void Art::setPrice(double p) {
	price = p;
}

void Art::setYear(unsigned int y) {
	year = y;
}

string Art::getTitle() {
	return title;
}

string Art::getArtist() {
	return artist;
}

string Art::getType() {
	return type;
}

string Art::getMedium() {
	return medium;
}

double Art::getPrice() {
	return price;
}

unsigned int Art::getYear() {
	return year;
}

ostream& operator<<(ostream& os, const Art& art) {
	os << art.title << endl;
	os << art.artist << endl;
	os << art.type << endl;
	os << art.medium << endl;
	os << art.year << endl;
	os << fixed << setprecision(0) << art.price << endl;
	return os;
}

bool Art::operator==(const Art& art) {
	return artist == art.artist && title == art.title && year == art.year;
}

bool Art::operator<(const Art& art) {
	string first_name(artist, 0, artist.find(" "));
	string last_name(artist, artist.find(" ") + 1);
	string first_name2(art.artist, 0, art.artist.find(" "));
	string last_name2(art.artist, artist.find(" ") + 1);
	if (sortByTitle) {
		if (title == art.title) {
			if (last_name == last_name2) {
				if (first_name == first_name2) {
					if (year == art.year)
						return false;
					else
						return year < art.year;
				} else
					return first_name < first_name2;
			} else
				return last_name < last_name2;
		} else
			return title < art.title;
	} else {
		if (last_name == last_name2) {
			if (first_name == first_name2) {
				if (title == art.title) {
					if (year == art.year)
						return false;
					else
						return year < art.year;
				} else
					return title < art.title;
			} else
				return first_name < first_name2;
		} else
			return last_name < last_name2;
	}
}

bool Art::operator>(const Art& art) {
	string first_name(artist, 0, artist.find(" "));
	string last_name(artist, artist.find(" ") + 1);
	string first_name2(art.artist, 0, art.artist.find(" "));
	string last_name2(art.artist, artist.find(" ") + 1);
	if (sortByTitle) {
		if (title == art.title) {
			if (last_name == last_name2) {
				if (first_name == first_name2) {
					if (year == art.year)
						return false;
					else
						return year > art.year;
				} else
					return last_name > last_name2;
			} else
				return first_name > first_name2;
		} else
			return title > art.title;
	} else {
		if (last_name == last_name2) {
			if (first_name == first_name2) {
				if (title == art.title) {
					if (year == art.year)
						return false;
					else
						return year > art.year;
				} else
					return title > art.title;
			} else
				return first_name > first_name2;
		} else
			return last_name > last_name2;
	}
}
