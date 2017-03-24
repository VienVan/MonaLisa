/*

 * Vincent Ha

 * CIS 22C, Winter 2017

 */

#include <locale>
#include "Order.h"

Order::Order() :
		customerFirst_Name("N/A"), priority(standard), date("N/A"), totalPrice(0), hasShipped(false) {
}

Order::Order(string cfn, string cln, string d) :
		customerFirst_Name(cfn), customerLast_Name(cln), priority(standard), date(
				d), totalPrice(0), hasShipped(false) {
}

Order::Order(const Order& o) :
		customerFirst_Name(o.customerFirst_Name), customerLast_Name(
				o.customerLast_Name), priority(o.priority), date(o.date), totalPrice(o.totalPrice), hasShipped(o.hasShipped) {
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
	return customerFirst_Name;
}

string Order::getcustomerLast_Name() {
	return customerLast_Name;
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
	customerFirst_Name = cfn;
}

void Order::setcustomerLast_Name(string cln) {
	customerLast_Name = cln;
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

ostream& operator<<(ostream& os, const Order& o) {
	os << "Customer: " << o.customerFirst_Name << " "
			<< o.customerLast_Name << endl;
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
		customerFirst_Name = o.customerFirst_Name;
		customerLast_Name = o.customerLast_Name;
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

void Order::userInteraction()
{
	cout << "vien is awesome \n";
}
