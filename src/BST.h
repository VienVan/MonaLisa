/*
 * BST.h
 *
 *  Created on: Mar 25, 2017
 *      Author: Vincent_Ha
 */

#ifndef BST_H_
#define BST_H_

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include <cstddef>
#include <string>
#include <assert.h>
#include <fstream>   // for file I/O
#include <iostream>

using namespace std;

template <class bstdata>
class BST
{
    private:
        struct Node
        {
                bstdata data;
                Node* left;
                Node* right;
                Node(bstdata newdata): data(newdata), left(NULL), right(NULL) {}
        };

        typedef struct Node* NodePtr;
        NodePtr root;

        /*************************************
         *     Private helper functions      *
         *************************************/

        void copyHelper(NodePtr copy);
        //recursively makes a deep copy of a binary search tree

        void inOrderPrintHelper(NodePtr root, ostream& os);
		//private helper function for inOrderPrint
		//recursively prints tree values in order from smallest to largest

		void preOrderPrintHelper(NodePtr root, ostream& os);
		//private helper function for preOrderPrint
		//recursively prints tree values in preorder

		void postOrderPrintHelper(NodePtr root, ostream& os);
		//private helper function for postOrderPrint
		//recursively prints tree values in postorder

        void destructorHelper(NodePtr root);
        //private helper function for the destructor
        //recursively frees the memory in the BST


        bstdata maximumHelper(NodePtr root);
        //recursively searches for the maximum value in the Binary Search Tree

        bstdata minimumHelper(NodePtr root);
        //recursively locates the minimum value in the tree
        //returns this value once it is located

        void getSizeHelper(NodePtr root, int& size);
        //recursively calculates the size of the tree

        int getHeightHelper(NodePtr root);
        //recursively calculates the height of the tree

        bool findHelper(NodePtr root, bstdata value);
        //recursively searches for value in the tree

        NodePtr removeHelper(NodePtr root, bstdata value);
        //recursively removes the specified value from the tree

        void insertHelper(NodePtr root, bstdata value);
        //private helper function for insert
        //recursively inserts a value into the BST

        bstdata findHelper2(NodePtr root, bstdata value);
        /**Public functions*/

    public:

        /**********************************************
         * CONSTRUCTOR, DESTRUCTOR, COPY CONSTRUCTOR  *
         **********************************************/

        BST();
        //Instantiates a new Binary Search Tree
        //post: a new Binary Search Tree object

        ~BST();
        //frees the memory of the BST object
        //All memory has been deallocated

        BST(const BST& tree);
        //makes a deep copy of tree
        //Calls the copyHelper function to make a copy recursively


        /********************************************************
         *                   ACCESS FUNCTIONS                   *
         ********************************************************/
        bstdata getRoot();
		//returns the value stored at the root of the Binary Search Tree
		//pre: the Binary Search Tree is not empty

        bool isEmpty();
        //determines whether the Binary Search Tree is empty

        void inOrderPrint(ostream &os);
        //calls the inOrderPrintHelper function to print out the values
        //stored in the Binary Search Tree
        //If the tree is empty, prints nothing

        void preOrderPrint(ostream &os);
        //calls the preOrderPrintHelper function to print out the values
        //stored in the Binary Search Tree
        //If the tree is empty, prints nothing

        void postOrderPrint(ostream &os);
        //calls the postOrderPrintHelper function to print out the values
        //stored in the Binary Search Tree
        //If the tree is empty, prints nothing

        bstdata maximum();
        //finds the maximum value in the Binary Search Tree and returns it
        //calls the maximumHelper function to search for the max recursively
        //pre: !isEmpty()

        bstdata minimum();
        //calls the minimumHelper function to return the minimum value in the tree
        //Pre: the tree is not empty

        int getSize();
        //returns the size of the tree
        //calls the getSizeHelper function to calculate the size recursively

        int getHeight();
        //recursively finds the height of the tree and returns it
        //calls the getHeight helper function to calculate the height recursively
        //returns -1 if the tree is empty

        bool find(bstdata value);
        //returns whether the value is in the tree
        //calls the findHelper function to search for the value recursively
        //Pre: !isEmpty()

        bstdata findNode(bstdata value);
        /************************************************************
        *                       MANIP. FUNCTIONS                    *
        *************************************************************/

        void insert(bstdata value);
		//inserts a new value into the Binary Search Tree
		//post: a new value inserted into the Binary Search Tree

        void remove(bstdata value);
        //removes the specified value from the tree
        //Pre: !isEmpty()
        //Pre: The value is contained in the Binary Search Tree
        //If the value is not in the Binary Search Tree, the tree is left unchanged


        void employeeInteraction(ostream& os);
};



#endif /* BINARYSEARCHTREE_H_ */

/*********************************************************
 *    Constructors, Destructors & Copy Constructor       *
 *********************************************************/
template <class bstdata>
BST<bstdata>::BST() : root(NULL){}

template <class bstdata>
BST<bstdata>::~BST()
{
	destructorHelper(root);
}


template <class bstdata>
BST<bstdata>::BST(const BST&tree)
{
	copyHelper(tree.root);

}
/*********PRIVATE HELPERS****************/

template <class bstdata>
void BST<bstdata>::insertHelper(NodePtr root, bstdata value)
{
    //base case
	if(value == root->data)
	{
		return;
	}

	else if(value < root->data)
	{

		if(root->left == NULL)
		{

			root->left = new Node(value);
		}
		else
		{

			insertHelper(root->left, value);
		}
	}

	else
	{

		if(root->right == NULL)
		{
			root->right = new Node(value);
		}
		else
		{
			insertHelper(root->right, value);
		}
	}

}

template <class bstdata>
bstdata BST<bstdata>::maximumHelper(NodePtr root)
{
	if(root->right != NULL)
	{
		return maximumHelper(root->right);
	}
	else
	{
		return root->data;
	}
}

template <class bstdata>
bstdata BST<bstdata>::minimumHelper(NodePtr root)
{
	if(root->left != NULL)
	{
		return minimumHelper(root->left);
	}
	else
	{
		return root->data;
	}
}

template <class bstdata>
void BST<bstdata>::getSizeHelper(NodePtr root, int& size)
{
	if(root != NULL)
	{
		size++;
		getSizeHelper(root->left, size);
		getSizeHelper(root->right, size);
	}
	else
	{
		return;
	}
}

template <class bstdata>
int BST<bstdata>::getHeightHelper(NodePtr root)
{
	if(root == NULL)
	{
		return 0;
	}
	else
	{
		int left_height = getHeightHelper(root->left);
		int right_height = getHeightHelper(root->right);
		if(left_height > right_height)
		{
			return left_height + 1;
		}
		else
		{
			return right_height + 1;
		}
	}
}

template <class bstdata>
bool BST<bstdata>::findHelper(NodePtr root, bstdata value)
{
	if(value == root->data)
	{
		return true;
	}
	else if(value < root->data)
	{
		if(root->left == NULL)
		{
			return false;
		}
		else
		{
			return findHelper(root->left, value);
		}
	}
	else
	{
		if(root->right == NULL)
		{
			return false;
		}
		else
		{
			return findHelper(root->right, value);
		}
	}
}

template <class bstdata>
void BST<bstdata>::copyHelper(NodePtr copy)
{
	if(copy == NULL)
	{
		root = NULL;
	}
	else
	{
		insert(copy->data);
		copyHelper(copy->left);
		copyHelper(copy->right);
	}
}

template <class bstdata>
bstdata BST<bstdata>::findHelper2(NodePtr root, bstdata value){
	if(value == root->data)
		return root->data;
	else if(value < root->data){
		if(root->left == NULL){
			cout << "Cannot find the value in the tree" << endl;
			return value;
		} else
			return findHelper2(root->left, value);
	} else{
		if(root->right == NULL){
			cout << "Cannot find the value in the tree" << endl;
			return value;
		} else
			return findHelper2(root->right, value);
	}
}

/********************************************************
 *                   ACCESS FUNCTIONS                   *
 ********************************************************/
template <class bstdata>
bstdata BST<bstdata>::getRoot()
{
	assert(root != NULL);
	return root->data;
}

template <class bstdata>
bool BST<bstdata>::isEmpty()
{
	return root == NULL;
}

template <class bstdata>
void BST<bstdata>::inOrderPrint(ostream& os)
{
	if(root == NULL)
	{
		cout << " " << endl;
	}
	inOrderPrintHelper(root, os);
	cout << endl << endl;
	os << endl << endl;
}

template <class bstdata>
void BST<bstdata>::preOrderPrint(ostream& os)
{
	if(root == NULL)
	{
		cout << " " << endl;
	}
	preOrderPrintHelper(root, os);
	cout << endl;
	os << endl;
}

template <class bstdata>
void BST<bstdata>::postOrderPrint(ostream& os)
{
	if(root == NULL)
	{
		cout << " " << endl;
		os << " " << endl;
	}
	postOrderPrintHelper(root, os);
	cout << endl << endl;
	os << endl << endl;
}

template <class bstdata>
bstdata BST<bstdata>::maximum()
{
	assert(!isEmpty());
	return maximumHelper(root);
}

template <class bstdata>
bstdata BST<bstdata>::minimum()
{
	assert(!isEmpty());
	return minimumHelper(root);
}

template <class bstdata>
int BST<bstdata>::getSize()
{
	int size = 0;
	if(root == NULL)
	{
		return size;
	}
	else
	{
		getSizeHelper(root, size);
		return size;
	}

}

template <class bstdata>
int BST<bstdata>::getHeight()
{
	if(root == NULL)
	{
		return -1;
	}
	else
	{
		return getHeightHelper(root);
	}
}

template <class bstdata>
bool BST<bstdata>::find(bstdata value)
{
	assert(!isEmpty());
	return findHelper(root, value);
}

template <class bstdata>
typename BST<bstdata>::NodePtr BST<bstdata>::removeHelper(NodePtr root, bstdata value)
{
    if(root == NULL)
    {
    	return root;
    }
    else if(value < root->data)
    {
    	root->left = removeHelper(root->left, value);
    }
    else if(value > root->data)
    {
    	root->right = removeHelper(root->right, value);
    }
    else
    {
    	if(root->right == NULL && root->left == NULL)
    	{
    		delete root;
    		root = NULL;
    	}
    	else if(root->left != NULL && root->right == NULL)
    	{
    		NodePtr temp = root;
    		root = root->left;
    		delete temp;
    	}
    	else if(root->right != NULL && root->left == NULL)
    	{
    		NodePtr temp = root;
    		root = root->right;
    		delete temp;
    	}
    	else
    	{
    		root->data = minimumHelper(root->right);
    		root->right = removeHelper(root->right, minimumHelper(root->right));
    	}
    }
    return root;
}

template <class bstdata>
void BST<bstdata>::inOrderPrintHelper(NodePtr root, ostream& os)
{
	if(root!= NULL)
	{
		inOrderPrintHelper(root->left, os);
		os << root->data;
		os << endl;
		cout << root->data;
		cout << endl;
		inOrderPrintHelper(root->right, os);
	}
}


template <class bstdata>
void BST<bstdata>::preOrderPrintHelper(NodePtr root, ostream& os)
{
	if(root!= NULL)
	{
		os << root->data;
		inOrderPrintHelper(root->left, os);
		inOrderPrintHelper(root->right, os);

	}

}

template <class bstdata>
void BST<bstdata>::postOrderPrintHelper(NodePtr root, ostream& os)
{
	if(root!= NULL)
	{
		inOrderPrintHelper(root->left, os);
		inOrderPrintHelper(root->right, os);
		os << root->data;

	}

}

template<class bstdata>
void BST<bstdata>::destructorHelper(NodePtr root)
{
	if(root!= NULL)
	{
		destructorHelper(root->left);
		destructorHelper(root->right);
		delete root;
	}
}

template <class bstdata>
bstdata BST<bstdata>::findNode(bstdata value){
	if(!find(value) || getSize() == 0){
		cout << "The item could not be found" << endl;
		return value;
	} else{
		return findHelper2(root, value);
	}
}

/********************************************
 *         MANIPULATORS FUNCTIONS           *
 ********************************************/
template <class bstdata>
void BST<bstdata>::insert(bstdata value)
{

    if (root == NULL)
    {
        root = new Node(value); //if the tree is empty insert the value at the root
    }
    else
    {
        insertHelper(root, value); //otherwise call the helper function, passing it the root
    }

}

template <class bstdata>
void BST<bstdata>::remove(bstdata value)
{
	//add code to handle the preconditions
	assert(find(value));
	root = removeHelper(root, value);
}




template <class bstdata>
void BST<bstdata>::employeeInteraction(ostream& os)
{
	BST<Art> tree;
	Art art;
	string title;
	string artist;
	string type;
	string medium;
	double price;
	unsigned int year;

	string choice;
	do
	{
		cout << "\t Mona Lisa Art Dealer" << endl
			 << "\t Art Inventory" << endl
			 << "1. Insert" << endl
			 << "2. Remove" << endl
			 << "3. List Full Inventory" << endl
			 << "4. Exit" << endl
			 << "Enter Your Choice: ";
		getline(cin, choice);
		switch(atoi(choice.c_str()))
		{
			case 1: {
				cout << "New Art Piece Info" << endl;
				cout << "------------------" << endl;

				cout << "Title: ";
				getline(cin, title);
				art.setTitle(title);

				cout << "Author: ";
				getline(cin, artist);
				art.setArtist(artist);

				cout << "Medium: ";
				getline(cin, medium);
				art.setMedium(medium);

				cout << "Genre: ";
				getline(cin,type);
				art.setType(type);

				cout << "Price:";
				cin >> price;
				art.setPrice(price);

				cout << "Year: ";
				cin >> year;
				art.setYear(year);
				cout << endl;

				insert(art);
				inOrderPrint(os);
			} break;
			case 2: {
				cout << "Enter the information about the art you wish to remove." << endl;

				cout << "Title: ";
				getline(cin, title);
				art.setTitle(title);
				cout << "Author: ";
				getline(cin, artist);
				art.setArtist(artist);

				if(!find(art))
				{
					cout << "Sorry, " << art.getTitle() << " is not in this collection!" << endl;
				}
				else
				{
					remove(art);
					cout << art.getTitle() << " has been removed!" << endl;
				}
					cout << endl;

			} break;
			case 3: { this -> inOrderPrint(os); } break;
			case 4: { } break;
			default:{cout << "Thank you for shopping at Mona Lisa\n";} break;
		}
	} while (atoi(choice.c_str()) != 4);
}

#endif /* BST_H_ */
