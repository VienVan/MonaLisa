
//#define _CRT_SECURE_NO_WARNINGS
#include "ControlModule.h"

ControlModule::ControlModule()
{
	order = new Order();
	customer = new Customer();
//	inventory = new HashTable();
}

ControlModule::~ControlModule()
{
    delete order;
    delete customer;
    order = nullptr;
    customer = nullptr;
}

void ControlModule::userInteraction()
{

		string choice;
	    do{
	        cout << "\n\t Mona Lisa Art Dealer\n\t\t Main Menu" << endl
	        << "\n\t Are you an employee or customer? \n"
	        << "1. Employee" << endl
	        << "2. Customer" << endl
	        << "3. Exit" << endl << endl
	        << "Enter Your Choice: ";

	        getline(cin, choice);
	        switch(atoi(choice.c_str()))
	        {
				case 1: { employeeInteraction();} break;
				case 2: { customerInteraction();} break;
				default: {cout << "Thank you for shopping at Mona Lisa\n";} break;
	        }
		} while (atoi(choice.c_str()) != 3);
}

void ControlModule::employeeInteraction()
{
	string key = "monalisa";
	string password = "";
	string choice;
	cout << "Please enter password: ";
	getline(cin, password);

	while (key != password)
	{
		cout << "Incorrect Password";
		cout << "Please re-enter password: ";
		getline(cin, password);
		cout << endl;
	}
	do
	{
	cout << endl;
	cout << "\n\t Mona Lisa Art Dealer\n\t Employee Menu" << endl;
	cout << "1. Orders" << endl
		 << "2. Customers" << endl
		 << "3. Inventory" << endl
		 << "4. Quit" << endl
		 << "Enter Your Choice: ";
	getline(cin, choice);
	 switch(atoi(choice.c_str()))
	{
		case 1: { order->userInteraction();} break;
		case 2: { customer->userInteraction();} break;
//		case 3: { inventory->userInteraction();} break;
		default: {cout << "Thank you for shopping at Mona Lisa\n";} break;
	}
	} while(atoi(choice.c_str()) != 7);
//	order->userInteraction();
}

void ControlModule::customerInteraction()
{
	customer->userInteraction();
}
