#ifndef MINHEAP_H
#define MINHEAP_H

#include "Graph.h"
#include "BFS.h"

class MinHeap
{
     public:
         //member
        int *table; // pointer to array of elements in heap vertex  (dist = value, vertex = i)
        int capacity; // maximum possible size of min heap
        int nb_element; // Current number of elements in min heap

    public:
        //constructors
        MinHeap(Graph*);
        virtual ~MinHeap();

        MinHeap& createMinHeap(Graph*);

          ///-----Binary tree
        int parent(int);
        int left(int);
        int right(int);
        bool IsLeaf(int);

        bool IsEmpty();

        ///----------Exchange

        //organize from the root MinHeap
        void OrganizeHeap(int);
        //swap 2 elements pre-existing in Heap
        void Exchange(int*,int*);
        //change value of 1 element with a given number
        void Exchange_Element(int,int);

        ///--------Insert/delete
        void AddElement(int);
        int TakeMin();




};

#endif // MINHEAP_H
