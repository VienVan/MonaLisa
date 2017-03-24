#ifndef _CONTROLMODULE_H
#define _CONTROLMODULE_H

#include "Art.h"
#include "Customer.h"
#include "Order.h"
//#include "HashTable.h"


class ControlModule
{
private:
//    Inventory *I;
    Order *order;
    Customer *customer;
//    HashTable *inventory;

public:
    ControlModule();
    ~ControlModule();
	void userInteraction();
	void employeeInteraction();
	void customerInteraction();
};

#endif
