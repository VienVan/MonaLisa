/*
 * ControlModule.h
 *
 *  Created on: Mar 25, 2017
 *      Author: Vincent_Ha
 */

#ifndef CONTROLMODULE_H_
#define CONTROLMODULE_H_

#include "Art.h"
#include "Customer.h"
#include "Order.h"
#include "BST.h"
#include "HashTable.h"
#include "PriorityQueue.h"

//#include "HashTable.h"


class ControlModule
{
private:
    PriorityQueue *orders;
    HashTable *customers;
    BST<Art> *inventoryTitle;
    BST<Art> *inventoryArtist;
    void orderHandling();
    void searchByArtist(Customer& c, Order& o);
    void searchByTitle(Customer& c, Order& o);
    void purchaseItem(Art& a, Order& o);
    void checkOut(Order& o, Customer& c);
    void inventoryByArtistMenu(Customer& c, Order& o);
    void inventoryByTitleMenu(Customer& c, Order& o);
    Customer checkCustomer();

public:
    ControlModule(BST<Art> *invTitle, BST<Art> *invArtist);
    ~ControlModule();
	void userInteraction();
	void employeeInteraction();
	void customerInteraction();
	void viewPurchases(Customer& c);
};



#endif /* CONTROLMODULE_H_ */
