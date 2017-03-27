//#define _CRT_SECURE_NO_WARNINGS
#include "ControlModule.h"

ControlModule::ControlModule() {}

ControlModule::ControlModule(BST<Art> *invTitle, BST<Art> *invArtist)
{
	order = new Order();
	customer = new HashTable();
	inventoryTitle = invTitle;
	inventoryArtist = invArtist;
}

ControlModule::~ControlModule()
{
    delete order;
//    delete customer;
    order = nullptr;
//    customer = nullptr;
}

void ControlModule::userInteraction(ostream& os)
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
				case 1: { employeeInteraction(os);} break;
				case 2: { customerInteraction(os);} break;
				default: {cout << "Thank you for shopping at Mona Lisa\n";} break;
	        }
		} while (atoi(choice.c_str()) != 3);
}

void ControlModule::employeeInteraction(ostream& os)
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
		 << "3. Inventory by Artist" << endl
		 << "4. Inventory by Title" << endl
		 << "5. Quit" << endl
		 << "Enter Your Choice: ";
	getline(cin, choice);
		switch(atoi(choice.c_str()))
		{
			case 1: { order->userInteraction("employee");} break;
			case 2: { customer->userInteraction();} break;
			case 3: { inventoryArtist->userInteraction();} break;
			case 4: { inventoryTitle->userInteraction();} break;
			default: {cout << "Go Team!\n";} break;
		}
	} while(atoi(choice.c_str()) != 5);
//	order->userInteraction();
}

void ControlModule::customerInteraction(ostream& os)
{
	string choice;
	do
	{
		cout << endl;
		cout << "\n\t Mona Lisa Art Dealer\n\t Customer Menu" << endl;
		cout << "1. Browse inventory by Artist" << endl
			 << "2. Browse inventory by Title" << endl
			 << "3. Place an Order" << endl
			 << "4. View Purchases" << endl
	         << "5. Quit" << endl
	         << "Enter Your Choice: ";
       getline(cin, choice);
       switch(atoi(choice.c_str()))
       {
			case 1: { inventoryArtist->userInteraction();;} break;
			case 2: { inventoryTitle->userInteraction();;} break;
			case 3: { order->userInteraction("order");;} break;
			case 4: { order->printCart(os);;} break;
			case 5: { } break;
			default: {cout << "Thank you for shopping at Mona Lisa\n";} break;
       }
	} while(atoi(choice.c_str()) != 4);

}
