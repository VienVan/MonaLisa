/*
 * Heap.h
 *
 *  Created on: Mar 6, 2017
 *  Author: Vien Van
 */

#ifndef HEAP_H_
#define HEAP_H_

#include <cstddef>
#include <string>
using namespace std;

template <class heapdata>
class Heap
{
private:
        struct Node
        {
                heapdata data;
                Node* left_child;
                Node* right_child;
                Node* parent;
                Node(heapdata newdata): data(newdata), left_child(NULL), right_child(NULL), parent(NULL) {}
        };

        typedef Node* NodePtr;
        NodePtr root;
        int size;
        heapdata A[size];

        int getHeapSize(heapdata A[]);
        // returns size of the array

        void heapIncreaseKey(heapdata A[], int index, heapdata key);
        // if (key > A[i]
        // A[i] = key
        // while parent is smaller and not at root, swap parent and child

        void maxHeapify(heapdata A[], int index);
        // get index of left and right child
        // start swapping

        heapdata* buildArray(NodePtr root, heapdata A[]);
        // use algorithm to fill array
public:
        void buildHeap(heapdata A[]);
        // calls heap_size(A)
        // use for loop starting at n = 2 down to 1
        // calls max-heapify helper function inside for loop

        void heapInsert(heapdata A[], heapdata key);
        // make space at the end of array
        // calls HeapIncreaseKey helper (A, size, key)
        // increase heapsize

        void heapSort(heapdata A[]);
        // get size of array
        // swap 1st and last
        // calls maxheapify
        // in for loop

};
#endif /* HEAP_H_ */
