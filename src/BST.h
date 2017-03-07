/*
 * Kim Cao
 * CIS 22C, Winter 2017
 */

#ifndef BST_H_
#define BST_H_

#include <cstddef>
#include <string>

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

        typedef Node* NodePtr;
        NodePtr root;
        int size;


        /**Private helper functions*/

        void insertHelper(NodePtr root, bstdata value);
        //private helper function for insert
        //recursively inserts a value into the BST

        void destructorHelper(NodePtr root);
        //private helper function for the destructor
        //recursively frees the memory in the BST

        void inOrderPrintHelper(NodePtr root);
        //private helper function for inOrderPrint
        //recursively prints tree values in order from smallest to largest

        void preOrderPrintHelper(NodePtr root);
        //private helper function for preOrderPrint
        //recursively prints tree values in preorder

        void postOrderPrintHelper(NodePtr root);
        //private helper function for postOrderPrint
        //recursively prints tree values in postorder

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

        void copyHelper(NodePtr copy);
        //recursively makes a deep copy of a binary search tree

        /**Public functions*/

    public:
        BST();
        //Instantiates a new Binary Search Tree
        //post: a new Binary Search Tree object

        BST(const BST& tree);
        //makes a deep copy of tree
        //Calls the copyHelper function to make a copy recursively

        ~BST();
        //frees the memory of the BST object
        //All memory has been deallocated

        bool isEmpty();
        //determines whether the Binary Search Tree is empty

        void insert(bstdata value);
        //inserts a new value into the Binary Search Tree
        //post: a new value inserted into the Binary Search Tree

        bstdata getRoot();
        //returns the value stored at the root of the Binary Search Tree
        //pre: the Binary Search Tree is not empty

        void inOrderPrint();
        //calls the inOrderPrintHelper function to print out the values
        //stored in the Binary Search Tree
        //If the tree is empty, prints nothing

        void preOrderPrint();
        //calls the preOrderPrintHelper function to print out the values
        //stored in the Binary Search Tree
        //If the tree is empty, prints nothing

        void postOrderPrint();
        //calls the postOrderPrintHelper function to print out the values
        //stored in the Binary Search Tree
        //If the tree is empty, prints nothing

        /*Access functions */

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

        /*Manipulation procedures */

        void remove(bstdata value);
        //removes the specified value from the tree
        //Pre: !isEmpty()
        //Pre: The value is contained in the Binary Search Tree
        //If the value is not in the Binary Search Tree, the tree is left unchanged
};


#endif /* BST_H_ */




