#ifndef MINHEAP_H
#define MINHEAP_H

#include "Graph.h"
#include "BFS.h"
#include "Edge.h"

class MinHeap
{
     public:
         //member
        Edge* table; // pointer to array of elements in heap vertex  (dist = value, vertex = i)    <- revoir ce com !
        int capacity; // maximum possible size of min heap
        int nb_element; // Current number of elements in min heap

        //constructors
        MinHeap(Graph*);
        MinHeap(std::vector<Edge*>, int, int);
        virtual ~MinHeap();


        ///-----Binary tree
        int parent(int);
        int left(int);
        int right(int);
        bool IsLeaf(int);
        void Insert(Edge&);

        void deleteMin();
        int getMin();
        Edge& TakeMin();

        bool isEmpty();
        bool isFull();
        void travDown(int);
        void TravUp(int);



        ///----------Exchange

        //organize from the root MinHeap
        void OrganizeHeap(int);
        //swap 2 elements pre-existing in Heap
        void Exchange(int*,int*);
        //change value of 1 element with a given number
        void Exchange_Element(int,int);

        ///--------Insert/delete
        void AddElement(int);
};

#endif // MINHEAP_H
