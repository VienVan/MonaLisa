/*
 * ControlModule.cpp
 *
 *  Created on: Mar 25, 2017
 *      Author: Vincent_Ha
 */
#include <cctype>
#include "ControlModule.h"

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
				Customer copy2;
				copy2.setFirst_Name(copy.getcustomerFirst_Name());
				copy2.setLast_Name(copy.getcustomerLast_Name());
				Customer copy3(customers->getItem(copy2));
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
		cout << "Please Enter the Artist of the Piece you are searching for: "
				<< endl;
		getline(cin, artist);

		Art copy;
		copy.setArtist(artist);
		if (inventoryArtist->find(copy)) {
			copy = inventoryArtist->find2(copy);
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

void ControlModule::searchByTitle(Customer& c, Order& o) {
	string title, choice;
	while (1) {
		cout << endl;
		cout << "Please Enter the Title of the Piece you are searching for: "
				<< endl;
		getline(cin, title);

		Art copy;
		copy.setTitle(title);
		if (inventoryArtist->find(copy)) {
			copy = inventoryTitle->find2(copy);
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

void Checkout(Order& o, Customer& c){
	o.setTotalPrice();
	string choice;
	while(1){
		cout << "Please Select A Shipping Option:" << endl;
		cout << "1. Standard Shipping ()" << endl;
		cout << "2. Rush Shipping ()" << endl;
		cout << "3. Overnight Shipping ()" << endl;
		cout << "Please Enter the Number Associated With the Choice You Want: ";
		getline(cin, choice);
		if(atoi(choice.c_str()) > 3 || atoi(choice.c_str()) < 1){
			cout << "Invalid Input. Please Try Again" << endl;
			continue;
		} else
			break;
	}
	cout << endl;
	switch (atoi(choice.c_str())){
		case 1:
			o.setPriority('S');
			break;
		case 2:
			o.setPriority('R');
			break;
		case 3:
			o.setPriority('O');
			break;
	}
	cout << "Review Your Order" << endl;
	//cout << o << endl;
	//cout << "Is Everything Correct? (Enter )"
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

Customer ControlModule::checkCustomer() {
	string choice, choice2, firstName, lastName, address, state, city;
	while (1) {
		cout
				<< "Have You Previously Visited Our Shop? (Enter Y For Yes and N For No): ";
		getline(cin, choice);
		if (toupper(choice.c_str()[0]) != 'Y'
				&& toupper(choice.c_str()[0]) != 'N') {
			cout << "Invalid Input. Please Try Again." << endl;
			continue;
		}
	}

	cout << "Please Enter Your First Name: ";
	getline(cin, firstName);
	cout << "Please Enter Your Last Name: ";
	getline(cin, lastName);
	cout << "Please Enter the State You Live In: ";
	getline(cin, state);
	Customer copy;
	copy.setFirst_Name(firstName);
	copy.setLast_Name(lastName);
	copy.setAddress(address);
	if (toupper(choice.c_str()[0]) == 'Y') {
		if (customers->search(copy) != -1) {
			Customer copy2(customers->getItem(copy));
			while (1) {
				cout << "Is this you?" << endl;
				cout << copy2 << endl;
				cout << "Enter Y For Yes and N For No: ";
				getline(cin, choice2);
				if (toupper(choice.c_str()[0]) == 'Y') {
					copy = copy2;
					customers->remove(copy);
					break;
				} else if (toupper(choice.c_str()[0]) == 'N') {
					cout
							<< "Please Enter Your House Number Followed By a Space and Your House Address: ";
					getline(cin, address);
					cout
							<< "Please Enter The City You Live In (Do Not Also Enter the State You Live): ";
					getline(cin, city);
					copy.setAddress(address);
					copy.setCity(city);
					customers->insert(copy);
					break;
				} else {
					cout << "Invalid Input. Please Try Again." << endl;
				}
			}
		}
		return copy;
	}
}

ControlModule::ControlModule(BST<Art> *invTitle, BST<Art> *invArtist) {
	orders = new PriorityQueue();
	customers = new HashTable();
	inventoryTitle = invTitle;
	inventoryArtist = invArtist;
}

ControlModule::~ControlModule() {
	delete orders;
	delete customers;
}

void ControlModule::userInteraction() {
	string choice;
	do {
		cout << "\n\t Mona Lisa Art Dealer\n\t\t Main Menu" << endl
				<< "\n\t Are you an employee or customer? \n" << "1. Employee"
				<< endl << "2. Customer" << endl << "3. Exit" << endl << endl
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
		cout << "1. Orders" << endl << "2. Customers" << endl
				<< "3. Inventory by Artist" << endl << "4. Inventory by Title"
				<< endl << "5. Quit" << endl
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
			inventoryArtist->userInteraction();
		}
			break;
		case 4: {
			inventoryTitle->userInteraction();
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
		cout << "Welcome " << customerCopy.getFirst_Name() << " "
				<< customerCopy.getLast_Name();
		cout << "1. Browse inventory by Artist" << endl
				<< "2. Browse inventory by Title" << endl << "3. Go To Checkout"
				<< endl << "4. View Purchases" << endl << "5. Quit" << endl
				<< "Enter The Number Associated With Your Choice: ";
		getline(cin, choice);
		if (atoi(choice.c_str()) > 4 || atoi(choice.c_str()) != 4 < 1) {
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
			//orders->userInteraction("customer");
			break;
		case 4:
			break;
		default:
			cout << "Returning to the Previous Menu\n";
			break;
		}
	} while (atoi(choice.c_str()) != 4);
}
