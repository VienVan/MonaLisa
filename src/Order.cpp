/*
 * Vincent Ha
 * CIS 22C, Winter 2017
 */

#include <locale>
#include "Order.h"
#include <ctime>


Order::Order() :
		customerFirstName("N/A"), priority(standard), date("N/A"), totalPrice(0), hasShipped(false) {
}

Order::Order(string cfn, string cln, string d) :
		customerFirstName(cfn), customerLastName(cln), priority(standard), date(
				d), totalPrice(0), hasShipped(false) {
}

Order::Order(const Order& o) :
		customerFirstName(o.customerFirstName), customerLastName(
				o.customerLastName), priority(o.priority), date(o.date), totalPrice(o.totalPrice), hasShipped(o.hasShipped) {
	List<Art> copy(o.cart);
	if (!copy.isEmpty()) {
		copy.startIterator();
		while (!copy.offEnd()) {
			cart.insertLast(copy.getIterator());
			copy.advanceIterator();
		}
	}
}

string Order::getcustomerFirst_Name() {
	return customerFirstName;
}

string Order::getcustomerLast_Name() {
	return customerLastName;
}

double Order::getTotalPrice(){
	if(!cart.isEmpty()){
		cart.startIterator();
		while(!cart.offEnd()){
			totalPrice += cart.getIterator().getPrice();
			cart.advanceIterator();
		}
	}
	return totalPrice;
}

void Order::setcustomerFirst_Name(string cfn) {
	customerFirstName = cfn;
}

void Order::setcustomerLast_Name(string cln) {
	customerLastName = cln;
}

void Order::setPriority(char p) {
	if (toupper(p) == 'O')
		priority = overnight;
	if (toupper(p) == 'R')
		priority = rush;
	if (toupper(p) == 'S')
		priority = standard;
}

void Order::setHasShipped(){
	hasShipped = true;
}

void Order::addToCart(Art a) {
	cart.insertLast(a);
}

void Order::removeFromCart(Art a) {
	if (!cart.isEmpty()) {
		cart.startIterator();
		while (!cart.offEnd()) {
			if (a == cart.getIterator()) {
				cart.removeIterator();
				cout << "Item was successfully removed from the cart" << endl;
				return;
			}
			cart.advanceIterator();
		}
	} else
		cout << "The item was not found in the cart." << endl;
}

void Order::printCart(ostream& os) {
	if (!cart.isEmpty()) {
		os << "Items Currently in the Cart:" << endl;
		os << endl;
		cart.startIterator();
		while (!cart.offEnd()) {
			os << cart.getIterator() << endl;
			cart.advanceIterator();
		}
	} else
		os << "The cart is currently empty." << endl;
}

void Order::setDate()
{
	time_t now = time(0);
	char* dt = ctime(&now);
	date = dt;
}
ostream& operator<<(ostream& os, const Order& o) {
	os << "Customer: " << o.customerFirstName << " "
			<< o.customerLastName << endl;
	os << "Date of Order: " << o.date << endl;
	os << "Shipping Priority: ";
	switch (o.priority) {
	case standard:
		os << "Standard" << endl;
		break;
	case rush:
		os << "Rush" << endl;
		break;
	default:
		os << "Overnight" << endl;
	}

	os << "Shipping Status: ";
	if(o.hasShipped == true)
		os << "Shipped" << endl;
	else
		os << "Has Not Shipped" << endl;
	os << "Items Ordered:" << endl;
	os << "--------------" << endl;

	List<Art> copy(o.cart);
	if(!copy.isEmpty()){
		os << endl;
		copy.startIterator();
		while (!copy.offEnd()) {
			os << copy.getIterator() << endl;
			copy.advanceIterator();
		}
	} else
		os << "Nothing" << endl;
	return os;
}

bool Order::operator>(const Order& o) {
	if (priority != o.priority) {
		return priority > o.priority;
	} else
		return date < o.date;
}

bool Order::operator<(const Order& o) {
	if (priority != o.priority) {
		return priority < o.priority;
	} else
		return date > o.date;
}

bool Order::operator==(const Order& o) {
	if (priority == o.priority && date == o.date) {
		List<Art> copy(o.cart);
		if (cart.isEmpty() && copy.isEmpty())
			return true;
		if (!cart.isEmpty() && !copy.isEmpty()) {
			cart.startIterator();
			copy.startIterator();
			while (!cart.offEnd()) {
				if (cart.getIterator() == copy.getIterator()){
				cart.advanceIterator();
				copy.advanceIterator();
				} else
					return false;
			}
			return true;
		}
	}
	return false;
}

Order& Order::operator=(const Order& o){
	if(this == &o){
		return *this;
	} else{
		customerFirstName = o.customerFirstName;
		customerLastName = o.customerLastName;
		priority = o.priority;
		date = o.date;
		while(!cart.isEmpty()){
			cart.removeLast();
		}

		List<Art> copy(o.cart);
		if(!copy.isEmpty()){
			copy.startIterator();
			while(!copy.offEnd()){
				cart.insertLast(copy.getIterator());
				copy.advanceIterator();
			}
		}
		return *this;
	}
}

void Order::userInteraction(string type)
{
	string choice;
	if(type == "employee")
	{
		cout << "\tMona Lisa Art Dealer" << endl
			 << "\t Orders " << endl
			 << "1. View Orders by Priority" << endl
			 << "2. Ship an Order" << endl
			 << "3. Exit " << endl;
	}
	else if(type == "order")
	{
		string choice;
		cout <<"\tMona Lisa Art Dealer" << endl
			 <<"\tPlace an order" << endl << endl
			 << "First Name: ";
		// get customer info
		getline(cin, customerFirstName);
		this->setcustomerFirst_Name(customerFirstName);
		cout << "\nLast Name: ";
		getline(cin, customerLastName);
		this->setcustomerLast_Name(customerLastName);
		setDate();
		// get total price of cart
		while(cart.getSize() != 0)
		{
			cart.startIterator();
			Art art = cart.getIterator();
			totalPrice += art.getPrice();
			cart.advanceIterator();
		}
		cout << "Would you like to purchase this item? (y or n)" << endl;
		getline(cin, choice);
		if(choice == "y" || choice == "Y")
		{
			cout << "Your order has been placed. Thank you for shopping with us." << endl;
		}

	}


}
