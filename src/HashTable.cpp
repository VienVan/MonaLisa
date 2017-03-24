///*
// * 	Jimmy Nguyen
// *	CIS 22C, Winter 2017
// *  March 7, 2017
// *  HashTable.cpp - Lab 8 - Hash Table
// */
//
//#include <iostream>
//#include <assert.h>
//#include "HashTable.h"
//
//
///**************************** Constructors and Destructor ****************************/
//HashTable :: HashTable()
//{
//
//}
//
//HashTable :: ~ HashTable()
//{
//
//}
//
////HashTable :: HashTable(const HashTable& ht):Table(ht.Table)
////{
////
////}
///***************************** Additional List Operations ****************************/
//void HashTable :: printBucket(int index)
//{
//	cout << "Printing Bucket: " << index << endl;
//	Table[index].printList();
//}
//
//void HashTable :: printTable()
//{
//	for(int i = 0; i < SIZE; i++)
//	{
//		if (!Table[i].isEmpty())
//		{
//			cout << "<----------------------->" << endl;
//			cout << "Bucket: " << i << endl;
//			cout << Table[i].getFirst();
//			cout << "Number of books at this bucket: " << countBucket(i) << endl;
//			cout << "<----------------------->" << endl << endl;
//		}
//	}
//}
//
//void HashTable :: remove(Art b)
//{
//	int count;
//	string temp;
//
//	temp = b.getTitle() + b.getArtist();
//	count = countBucket(hash(temp));
//
//	if(search(b) != -1)
//	{
//		Table[hash(temp)].startIterator();
//		while (count != 0)
//		{
//			if(Table[hash(temp)].getIterator() == b)
//			{
//				count = 0;
//				cout << "Removed " << b.getTitle() << endl;
//				Table[hash(temp)].removeIterator();
//			}
//			else
//			{
//				Table[hash(temp)].advanceIterator();
//				count --;
//			}
//		}
//	}
//}
///****************************** Manipulation Procedures ******************************/
//int HashTable :: hash(string key)
//{
//    int index, sum = 0;
//
//    for(int i = 0; i < key.length(); i++)
//        sum += (int) key[i];
//
//    index = sum % SIZE;
//    return index;
//}
//
//void HashTable :: insert(Art b)
//{
//	int hold;
//	string temp;
//
//	temp = b.getTitle() + b.getArtist();
//	hold = hash(temp);
//	Table[hold].insertLast(b);
//}
//
//
///************************************* Accessors *************************************/
//int HashTable :: countBucket(int index)
//{
//	assert(0 <= index && index < SIZE);
//
//	return Table[index].getSize();
//}
//
//int HashTable :: search(Art b)
//{
//	int hold, count;
//	string temp;
//
//	temp = b.getTitle() + b.getArtist();
//	count = countBucket(hash(temp));
//	Table[hash(temp)].startIterator();
//
//	while (count != 0)
//	{
//		hold = -1;
//		if(Table[hash(temp)].getIterator() == b)
//		{
//			count = 0;
//			hold = hash(temp);
//		}
//		else
//		{
//			Table[hash(temp)].advanceIterator();
//			count --;
//		}
//	}
//	return hold;
//}
