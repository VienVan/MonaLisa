#ifndef _CONTROLMODULE_H
#define _CONTROLMODULE_H

#include "Art.h"
#include "Customer.h"
#include "Order.h"
#include "BST.h"
#include "HashTable.h"

//#include "HashTable.h"


class ControlModule
{
private:
//    Inventory *I;
    Order *order;
    HashTable *customer;
    BST<Art> *inventoryTitle;
    BST<Art> *inventoryArtist;

public:
    ControlModule(BST<Art> *invTitle, BST<Art> *invArtist);
    ~ControlModule();
	void userInteraction();
	void employeeInteraction();
	void customerInteraction();
};

#endif
