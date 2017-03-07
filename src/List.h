#ifndef LIST_H_
#define LIST_H_

#include <cstddef> //for NULL

template <class listdata> //list stores generic listdata, not any specific C++ type

class List
{
    private:
		struct Node
		{
		listdata data;
		Node* next;
		Node* previous;
		Node(listdata data): data(data), next(NULL), previous(NULL){}
		};

		typedef struct Node* Nodeptr;

		Nodeptr first;
		Nodeptr last;
		Nodeptr iterator;
		int size;

		void reverse(Nodeptr node);
		bool isSorted(Nodeptr node);
		int binarySearch(int low, int high, listdata data);
		//Recursively searchs the list by dividing the search space in half
		//Returns the index of the element, if it is found in the List
		//Returns -1 if the element is not in the List

    public:

        /**Constructors and Destructors*/

        List();
        //Default constructor; initializes and empty list
        //Postcondition: There should be an empty list.

        List(const List &list);
        //Copy Constructor
        //Postcondition: There should be a deep copy of the original list

        ~List();
        //Destructor. Frees memory allocated to the list
        //Postcondition: The list is cleared


        /********************************************************
         *                      Accessors                       *
         ********************************************************/


        listdata getFirst();
        //Returns the first element in the list
        //Precondition: There should be at least one element in the list


        listdata getLast();
        //Returns the last element in the list
        //Precondition: There should be at least one element in the list


        bool isEmpty();
        //Determines whether a list is empty.

        int getSize();
        //Returns the size of the list

        void printList();
        //Prints to the console the value of each element in the list sequentially
		//and separated by a blank space
		//Prints nothing if the list is empty

        void printListReverse();

        listdata getIterator();
		//Return element at itertor's node
		//Precondition: size!=0 && iterator!=null

        bool isSorted();

        int getIndex();
        //Indicates the index of the Node where the iterator is currently pointing
        //Nodes are numbered from 1 to size of the list
        //Pre: size != 0
        //Pre: !off_end()

        /*************************************************************
         *                       Manipulators                        *
         *************************************************************/

        void removeLast();
        //Removes the value of the last element in the list
        //Precondition: There should be one element in the list
        //Postcondition: There should be one less element in the list. The last element should be different than before.

        void removeFirst();
        //Removes the value of the first element in the list
        //Precondition: There should be at least one element in the list
        //Postcondition: There should be one less element in the list. The first element should be different than before.

        void insertLast(listdata data);
        //Inserts a new element at the end of the list
        //If the list is empty, the new element becomes both first and last
        //Postcondition: There should be one more element in the list. The last element should be different than before.

        void insertFirst(listdata data);
        //Inserts a new element at the start of the list
        //If the list is empty, the new element becomes both first and last
        //Postcondition: There should be one more element in the list. The first element should be different than before.

        void removeIterator();
		//Remove element at the iterator
		//Precondition: size!=0 && iterator!= null

        void insertIterator(listdata data);
		//Insert node at the element after the iterator is pointing to
		//Precondition: !offEnd

        void advanceToIndex(int index);
        //Moves the iterator to the node whose index number is specified in the parameter
        //Pre: size != 0
        //Pre: index <= size

        int linearSearch(listdata data);
        //Searchs the list, element by element, from the start of the List to the end of the List
        //Returns the index of the element, if it is found in the List
        //Calls the above indexing functions in its implementation
        //Returns -1 if the element is not in the List
        //Pre: size != 0

        int binarySearch(listdata data);
        //Returns the index where data is located in the List
        //Calls the private helper function binarySearch to perform the search
        //Pre: size != 0
        //Pre: List is sorted (must test on a sorted list)

        /**************************************************************
         *             Additional List Operations                     *
         **************************************************************/

        void startIterator();
        //Make iterator point to the first node of the list
        //Precondition: size!=0

        void advanceIterator();
        //Move iteraror to the next node
        //Precondition: size!=0 && iterator!=null

        void retreatIterator();

        bool offEnd();
        //Returns true or false whether the iterator is null (end of the list)

        bool operator==(const List &list);

        void printReverse();
};
