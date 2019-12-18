#include "MinHeap.h"
#include "Graph.h"
#include "BFS.h"

#include<iostream>

using namespace std;

///-------Constructor--------------
MinHeap::MinHeap(Graph* G){
    nb_element = 0;
    capacity = G->nb_vertex;
    table = new int[capacity];
    (*this) = createMinHeap(G);
}

MinHeap::~MinHeap(){
    delete [] table;
}

MinHeap& MinHeap::createMinHeap(Graph* G)
{

    vector<int> v = BFS(G,0); //ordre des vertex
    G->setAllUnvisited();
    int n= G->nb_vertex;

    for(int k=0;k<n;k++){
        if(G->isVisited(v.at(k))){
            G->visited(v[k]);
            AddElement(v[k]); //AddElement(dist de v -> attribut de vertex + voir version td du prof avec set)
        }
    }
    return *this;


}

///-------BT-----------------------------------

bool MinHeap::IsEmpty(){
    return nb_element==0;
}

//to get index of parent
int MinHeap::parent(int ID){
     return ID/2;
}

// to get index of left child
int MinHeap::left(int ID){
    return (2*ID);
}

// to get index of right child
int MinHeap::right(int ID){
    return (2*ID + 1);
}

//return true if index ID is leaf
bool MinHeap::IsLeaf(int ID){
    return (2*ID>nb_element);
}


///-------------Exchange-------------------

void MinHeap::Exchange(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}

void MinHeap::OrganizeHeap(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < nb_element && table[l] < table[i])
        smallest = l;
    if (r < nb_element && table[r] < table[smallest])
        smallest = r;
    if (smallest != i)
    {
        Exchange(&table[i], &table[smallest]);
        OrganizeHeap(smallest);
    }
}


///-------Add/Deleter ----------------------------

void MinHeap::AddElement(int k)
{
    if (nb_element == capacity)
    {
        cout << "\nOverflow: Could not insert Key\n";
    }

    //mise a l'infini pour 0
    table[0]=INT_MAX;

    // First insert new key at the end
    nb_element++;
    int i = nb_element;
    table[i] = k;

    // root untouchable and while parent > i we swap them
    while (i != 1 && table[parent(i)] > table[i])
    {
       Exchange(&table[i], &table[parent(i)]);

       //on remonte le tableau pour vérifier que tjr min est le parent
       i = parent(i);
    }
}

int MinHeap::TakeMin(){

    if (IsEmpty()) cout<<"Empty heap"<<endl;

    // Store the minimum value, and remove it from heap
    int root = table[1];
    table[1] = table[nb_element];
    nb_element--;
    OrganizeHeap(1);

    return root;
}




