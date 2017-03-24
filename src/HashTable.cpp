/*
 * HashTable.cpp
 *
 *  Created on: Mar 5, 2017
 *      Author: VienVonVan
 */

#include "HashTable.h"

/*********************************************
 *       Constructors & Destructors          *
 *********************************************/

HashTable::HashTable() {}

HashTable::~HashTable() {}


/*********************************************
 *     			    ACCESSORS                *
 *********************************************/

int HashTable::hash(string key)
{
    int index, sum = 0;
    for(int i = 0; i < key.length(); i++)
        sum += (int) key[i]; //summing the ASCII values for each character in the string
    index = sum % SIZE; //dividing the summed ASCII values by 35 && storing remainder as my index
    return index;
}

int HashTable::countBucket(int index)
{
	if(Table[index].isEmpty())
	{
		return 0;
	}
	return Table[index].getSize();
}

int HashTable::search(Customer c)
{
	// concatenate title and author for key
	string key = c.getFirst_Name() + c.getLast_Name();

	// get index to insert to
	int index = hash(key);
	List<Customer> customer_list = Table[index];

	if(customer_list.isEmpty())
	{
		return -1;
	}
	else
	{
		// search through list of books

		// advance iterator of list to the found book
		if(Table[index].linearSearch(c) == -1)
		{
			return -1;
		}
		else
		{
			return index;
		}

	}
}

/**********************************************
 * 				MANIPULATORS		          *
 **********************************************/

void HashTable::insert(Customer c)
{
	// concatenate title and author for key
	string key = c.getFirst_Name() + c.getLast_Name();

	// get index to insert to
	int index = hash(key);

	// insert book at indexed array
	Table[index].insertLast(c);
}

void HashTable::remove(Customer c)
{
	// concatenate title and author for key
	string key = c.getFirst_Name() + c.getLast_Name();

	// get index to insert to
	int index = hash(key);

	// insert book at indexed array

	List<Customer> customer_list = Table[index];
	if(customer_list.getSize() == 0)
	{
		cout << "This book is not in the hash table." << endl;
		return;
	}
	else
	{
		int list_index = Table[index].linearSearch(c);
		Table[index].advanceToIndex(list_index);
		Table[index].removeIterator();
	}

}

/***********************************************
 * 			 ADDT'L FUNCTIONS                  *
 ***********************************************/

void HashTable::printBucket(int index)
{
	Table[index].printList();
}

void HashTable::printTable()
{
	for (int i = 0; i < SIZE; i++)
	{
		// print customers
		printBucket(i);
	}
}

void HashTable::userInteraction()
{
	cout << "HashTable interaction" << endl;
}
