/*
 * Hash.h
 *
 *  Created on: Mar 6, 2017
 *      Author: KOTA IWAMOTO
 */

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <string>
#include <assert.h>
#include "Art.h"
#include "List.h"
using namespace std;

class HashTable {
public:
    /**Constructors*/

    HashTable();
    //constructor

    ~HashTable();
    //destructor


    HashTable(const HashTable& ht);
    //copy constructor

    /**Access Functions*/

    int hash(string key);


    int countBucket(int index);

    //pre: 0<= index < SIZE

    int search(Art a);


    /**Manipulation Procedures*/

    void insert(Art a);

    void remove(Art ab);


    /**Additional Functions*/

    void printBucket(int index);
    //pre: 0<= index < SIZE


    void printTable();


private:
    static const int SIZE = 10;
    List<Art> Table[SIZE];
};

#endif /* HASHTABLE_H_ */

