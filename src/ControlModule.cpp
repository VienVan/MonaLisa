/*
 * ControlModule.cpp
 *
 *  Created on: Mar 25, 2017
 *      Author: Vincent_Ha
 */
#include <cctype>
#include "ControlModule.h"

ControlModule::ControlModule(BST<Art> *invTitle, BST<Art> *invArtist) {
	orders = new PriorityQueue();
	customers = new HashTable();
	inventoryTitle = invTitle;
	inventoryArtist = invArtist;
}

ControlModule::~ControlModule() {
//	delete orders;
//	delete customers;
}

void ControlModule::orderHandling() {
	cout << endl;
	string choice;
	do {
		cout << "\t Mona Lisa Art Dealer" << endl;
		cout << "\t Order Handling Menu" << endl;
		cout << "1. View Orders" << endl;
		cout << "2. Ship First Order" << endl;
		cout << "3. Exit" << endl;
		cout << "Enter the Number Associated With Your Choice: ";
		getline(cin, choice);
		if (atoi(choice.c_str()) > 3 || atoi(choice.c_str()) < 1) {
			cout << "Invalid Input. Please Try Again." << endl;
			cout << endl;
			continue;
		}
		switch (atoi(choice.c_str())) {
		case 1:
			orders->printShippingList(cout);
			cout << endl;
			break;
		case 2:
			if (orders->getSize() != 0) {
				Order copy = orders->shipOrder();
				Customer temp_customer_copy;
				temp_customer_copy.setFirst_Name(copy.getcustomerFirst_Name());
				temp_customer_copy.setLast_Name(copy.getcustomerLast_Name());
				Customer copy3(customers->getItem(temp_customer_copy));
				copy3.shippedOrder(copy);
				customers->remove(copy3);
				customers->insert(copy3);
			} else
				cout << "There is nothing to ship" << endl;
			break;
		default:
			break;
		}
	} while (atoi(choice.c_str()) != 3);
}

void ControlModule::searchByArtist(Customer& c, Order& o) {
	string artist, choice;
	while (1) {
		cout << endl;
		cout << "Please Enter the Artist of the Piece you are searching for: ";
		getline(cin, artist);
		cout << endl;
		Art copy;
		copy.setArtist(artist);
		if (inventoryArtist->find(copy)) {
			copy = inventoryArtist->findNode(copy);
			cout << "We Found an Item With the Artist You Entered:" << endl;
			cout << copy << endl;
			cout
					<< "Would You Like to Purchase This Item? (Please Enter Y for Yes and N for No): ";
			getline(cin, choice);
			while (toupper(choice.c_str()[0]) == 'Y'
					|| toupper(choice.c_str()[0]) == 'N') {
				if (toupper(choice.c_str()[0]) == 'Y') {
					purchaseItem(copy, o);
					break;
				} else if (toupper(choice.c_str()[0]) == 'N')
					break;
				else {
					cout << "Invalid Input. Please Try Again." << endl;
					cout << "We Found an Item With the Artist You Entered:"
							<< endl;
					cout << copy << endl;
					cout
							<< "Would You Like to Purchase This Item? (Please Enter Y for Yes and N for No): ";
					getline(cin, choice);
					continue;
				}
			}
		} else
		{
			cout << "Art: " << copy << endl;
			cout << "We Could Not Find What You Were Looking." << endl;
		}

		cout << "Would You Like to Continue Searching (Please Enter Y for Yes and N for No): ";
		getline(cin, choice);
		if (toupper(choice.c_str()[0]) == 'Y')
			continue;
		else if (toupper(choice.c_str()[0]) == 'N') {
			cout << "Returning to the Previous Menu" << endl;
			break;
		}
	}
}

void ControlModule::searchByTitle(Customer& c, Order& o) {
	string title, choice;
	while (1) {
		cout << endl;
		cout << "Please Enter the Title of the Piece you are searching for: "
				<< endl;
		getline(cin, title);

		Art copy;
		copy.setTitle(title);
		if (inventoryTitle->find(copy)) {
			copy = inventoryTitle->findNode(copy);
			cout << "We Found an Item With the Title You Entered:" << endl;
			cout << copy << endl;
			cout
					<< "Would You Like to Purchase This Item? (Please Enter Y for Yes and N for No): ";
			getline(cin, choice);
			while (toupper(choice.c_str()[0]) == 'Y'
					|| toupper(choice.c_str()[0]) == 'N') {
				if (toupper(choice.c_str()[0]) == 'Y') {
					purchaseItem(copy, o);
					break;
				} else if (toupper(choice.c_str()[0]) == 'N')
					break;
				else {
					cout << "Invalid Input. Please Try Again." << endl;
					cout << "We Found an Item With the Title You Entered:"
							<< endl;
					cout << copy << endl;
					cout
							<< "Would You Like to Purchase This Item? (Please Enter Y for Yes and N for No): ";
					getline(cin, choice);
					continue;
				}
			}
		} else
			cout << "We Could Not Find What You Were Looking." << endl;

		cout
				<< "Would You Like to Continue Searching (Please Enter Y for Yes and N for No): ";
		getline(cin, choice);
		if (toupper(choice.c_str()[0]) == 'Y')
			continue;
		else if (toupper(choice.c_str()[0]) == 'N') {
			cout << "Returning to the Previous Menu" << endl;
			break;
		}
	}
}

void ControlModule::purchaseItem(Art& a, Order& o) {
	o.addToCart(a);
}

void ControlModule::checkOut(Order& o, Customer& c){
	o.setTotalPrice();
	string shipping_choice, review_choice;
	do
	{

		while(atoi(shipping_choice.c_str()) > 3 || atoi(shipping_choice.c_str()) < 1)
		{
			cout << "Please Select A Shipping Option:" << endl;
			cout << "1. Standard Shipping (3 - 5 business days)" << endl;
			cout << "2. Rush Shipping ( 1 - 3 business days)" << endl;
			cout << "3. Overnight Shipping (next day deliver)" << endl;
			cout << "4. Go back" << endl;
			cout << "Please Enter the Number Associated With the Choice You Want: ";
			getline(cin, shipping_choice);
		}
		cout << endl;
		switch (atoi(shipping_choice.c_str()))
		{
			case 1:
				o.setPriority('S');
				break;
			case 2:
				o.setPriority('R');
				break;
			case 3:
				o.setPriority('O');
				break;
			case 4:
				return;
				break;
		}
		cout << "Review Your Order: " << endl;
		cout << o << endl;
		cout << "Is Everything Correct? (Enter y or n): ";
		getline(cin, review_choice);
	} while(toupper(review_choice.c_str()[0]) != 'Y');

	orders->addToList(o);
	c.addOrder(o);
	o = Order();
	cout << "Your order has been placed." << endl;
	cout << "Thank You For Shopping With Us" << endl;
}
void ControlModule::inventoryByArtistMenu(Customer& c, Order& o) {
	string choice2;
	while (atoi(choice2.c_str()) != 3) {
		cout << endl;
		cout << "\n\t Mona Lisa Art Dealer\n\t Customer Menu" << endl;
		cout << "1. List Entire Inventory By Artist" << endl;
		cout << "2. Search For/Order An Artpiece" << endl;
		cout << "3. Exit" << endl;
		cout << "Enter The Number Associated With Your Choice: ";
		getline(cin, choice2);
		switch (atoi(choice2.c_str())) {
		case 1:
			inventoryArtist->inOrderPrint(cout);
			break;
		case 2:
			searchByArtist(c, o);
			break;
		default:
			cout << "Returning to the Previous Menu" << endl;
			break;
		}
	}
}

void ControlModule::inventoryByTitleMenu(Customer& c, Order& o) {
	string choice2;
	while (atoi(choice2.c_str()) != 3) {
		cout << endl;
		cout << "\n\t Mona Lisa Art Dealer\n\t Customer Menu" << endl;
		cout << "1. List Entire Inventory By Artist" << endl;
		cout << "2. Search For/Order An Artpiece" << endl;
		cout << "3. Exit" << endl;
		cout << "Enter The Number Associated With Your Choice: ";
		getline(cin, choice2);
		switch (atoi(choice2.c_str())) {
		case 1:
			inventoryTitle->inOrderPrint(cout);
			break;
		case 2:
			searchByTitle(c, o);
			break;
		default:
			cout << "Returning to the Previous Menu" << endl;
			break;
		}
	}
}


// get customer info, create temp customer object
Customer ControlModule::checkCustomer() {
	string choice, choice2, firstName, lastName, house_number, street_address, address, state, city;
	// check if customer exists
	cout << "Have You Previously Visited Our Shop? (Enter Y For Yes and N For No): ";
	do
	{
		getline(cin, choice);
	} while ( toupper(choice.c_str()[0]) != 'Y'
			&& toupper(choice.c_str()[0]) != 'N');

	// get customer's info
	cout << "Please Enter Your First Name: ";
	getline(cin, firstName);
	cout << "Please Enter Your Last Name: ";
	getline(cin, lastName);
	cout << "Please Enter the State You Live In (For example, CA): ";
	getline(cin, state);

	Customer temp_customer;
	temp_customer.setState(state);
	temp_customer.setFirst_Name(firstName);
	temp_customer.setLast_Name(lastName);
	temp_customer.setAddress(address);

	if (toupper(choice.c_str()[0]) == 'Y')
	{
		if (customers->search(temp_customer) != -1)
		{
			Customer temp_customer_copy(customers->getItem(temp_customer));
			do {
				cout << "Is this you?" << endl;
				cout << temp_customer_copy << endl;
				cout << "Enter Y For Yes and N For No: ";
				getline(cin, choice2);
				if (toupper(choice2.c_str()[0]) == 'Y')
				{
					// if customer is found, set customer to temp_customer
					temp_customer = temp_customer_copy;
					customers->remove(temp_customer);
				}
				else if (toupper(choice2.c_str()[0]) == 'N')
				{
					cout << "Please Enter Your House Number Followed By a Space and Your House Address: ";
					getline(cin, address);
					cout << "Please Enter The City You Live In: ";
					getline(cin, city);
					temp_customer.setAddress(address);
					temp_customer.setCity(city);
					customers->insert(temp_customer);
				} else
				{
					cout << "Invalid Input. Please Try Again." << endl;
				}
			} while(toupper(choice2.c_str()[0]) != 'Y' && toupper(choice2.c_str()[0]) != 'N');
		}
	}
	else
	{
		cout << "Please Enter Your House Number: " << endl;
		getline(cin, house_number);
		cout << "Please enter your street address: " << endl;
		getline(cin, street_address);
		address = house_number + street_address;
		cout << "Please Enter The City You Live In: ";
		getline(cin, city);
		temp_customer.setAddress(address);
		cout << "setAddress" << endl;
		temp_customer.setCity(city);
		cout << "setCity" << endl;
		customers->insert(temp_customer);
		cout << "insert customer" << endl;
	}
	cout << "outside everything" << endl;
	return temp_customer;
}



void ControlModule::userInteraction() {
	string choice;
	do {
		cout << "\n\t Mona Lisa Art Dealer\n\t\t Main Menu" << endl
				<< "\n\t Are you an employee or customer? \n"
				<< "1. Employee" << endl
				<< "2. Customer" << endl
				<< "3. Exit" << endl << endl
				<< "Enter The Number Associated With Your Choice: ";

		getline(cin, choice);
		switch (atoi(choice.c_str())) {
		case 1: {
			employeeInteraction();
		}
			break;
		case 2: {
			customerInteraction();
		}
			break;
		default: {
			cout << "Thank you for shopping at Mona Lisa\n";
		}
			break;
		}
	} while (atoi(choice.c_str()) != 3);

	ofstream output("input.txt");
}

void ControlModule::employeeInteraction() {
	string key = "monalisa";
	string password = "";
	string choice;
	cout << "Please enter password: ";
	getline(cin, password);

	while (key != password) {
		cout << "Incorrect Password";
		cout << "Please re-enter password: ";
		getline(cin, password);
		cout << endl;
	}
	do {
		cout << endl;
		cout << "\n\t Mona Lisa Art Dealer\n\t Employee Menu" << endl;
		cout << "1. Orders" << endl
			 << "2. Customers" << endl
			 << "3. Inventory by Artist" << endl
			 << "4. Inventory by Title" << endl
			 << "5. Quit" << endl
			 << "Enter The Number Associated With Your Choice: ";
		getline(cin, choice);
		switch (atoi(choice.c_str())) {
		case 1:
			cout << endl;
			orderHandling();
			break;
		case 2: {
			customers->userInteraction();
		}
			break;
		case 3: {
			inventoryArtist->employeeInteraction(cout);
		}
			break;
		case 4: {
			inventoryTitle->employeeInteraction(cout);
		}
			break;
		default: {
			cout << "Go Team!\n";
		}
			break;
		}
	} while (atoi(choice.c_str()) != 5);
//	order->userInteraction();
}

void ControlModule::customerInteraction() {
	string choice;

	Customer customerCopy = checkCustomer();

	Order currentOrder;

	currentOrder.setDate();

	currentOrder.setcustomerFirst_Name(customerCopy.getFirst_Name());

	currentOrder.setcustomerLast_Name(customerCopy.getLast_Name());

	currentOrder.setAddress(
			customerCopy.getAddress() + " " + customerCopy.getCity() + ", " + customerCopy.getState()
					);//+ " " //+ customerCopy.getZip());


	do {
		cout << "\n\t Mona Lisa Art Dealer\n\t Customer Menu" << endl;
		cout << "Welcome " << customerCopy.getFirst_Name() << " " << customerCopy.getLast_Name() << endl;
		cout << "1. Browse inventory by Artist" << endl
			 << "2. Browse inventory by Title" << endl
			 << "3. Go To Checkout" << endl
			 << "4. View Purchases" << endl
			 << "5. Quit" << endl
			 << "Enter The Number Associated With Your Choice: ";
		getline(cin, choice);
		if (atoi(choice.c_str()) > 5 || atoi(choice.c_str()) < 1) {
			cout << "Invalid Input. Please Try Again." << endl;
			cout << endl;
			continue;
		}
		switch (atoi(choice.c_str())) {
		case 1:
			inventoryByArtistMenu(customerCopy, currentOrder);
			break;
		case 2:
			inventoryByTitleMenu(customerCopy, currentOrder);
			break;
		case 3:
			this->checkOut(currentOrder, customerCopy);
			break;
		case 4:
			viewPurchases(customerCopy);
			break;
		default:
			cout << "Returning to the Previous Menu\n";
			break;
		}
	} while (atoi(choice.c_str()) != 5);

}

void ControlModule::viewPurchases(Customer& c)
{
	cout << c << endl;
}
