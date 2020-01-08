#include "MinHeap.h"
#include "Graph.h"
#include "BFS.h"
#include <vector>
#include "Edge.h"

#include<iostream>

using namespace std;

/*
///-------Constructor--------------
MinHeap::MinHeap(Graph* G){
    nb_element = 0;
    capacity = G->nb_vertex;
    table = new int[capacity];
    (*this) = createMinHeap(G);
}
*/

//Constructor
MinHeap::MinHeap(vector<Edge*> edge, int cap, int nbE) {
	table = new Edge[cap];
	this->capacity = cap;
	this->nb_element = nbE;

	cout << "test : capacity : " << capacity << " & # elem : " << nbE << " " << endl;

	for(int i = 0; i < nbE; ++i) {
		table[i] = *(edge[i]);
	}

	int j = (nb_element-2)/2;
	while (j >= 0) {
        cout << "Graph j : " << j << endl;
		travDown(j);

		cout << "test" << endl;
		--j;
	}
}


//Destructor
MinHeap::~MinHeap(){
    delete [] table;
}


//traverse heap de haut vers le bas
void MinHeap::travDown(int id) {
    int j;
    bool flag = true;
	Edge edge = table[id];

	//on obtient le fils gauche
	j = 2*id+1;

	//to check i is the last father
	while ((j <= nb_element-1) && flag == true) {
        //si id a un fils droit && le fils droit est plus petit que le gauche
		if ((j < nb_element-1) && (table[j].cost > table[j+1].cost)) {
			//on augmente j pour qu'il soit le plus petit
			j++;
		}

		//si le parent est plus grand que l'enfant
		if (edge.cost <= table[j].cost) {
			flag = false;
		}
		else {
            //on change les valeurs
			table[id] = table[j];
			id = j;
            //on va au prochain
			j = 2*j+1;
		}
		table[id] = edge;
	}
}



//Traverse heap du bas vers le haut
void MinHeap::TravUp(int id) {
	Edge point;

	while (id > 0) {
		if (table[(id-1)/2].cost > table[id].cost)
		{
			point = table[id];
			table[id] = table[(id-1)/2];
			table[(id-1)/2] = point;
		}
		else break;

		id = (id-1)/2;
	}
}


//vérifie si heap est vide
bool MinHeap::isEmpty(){
    if (nb_element == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

//vérifie si heap est full
bool MinHeap::isFull(){
    if (nb_element == capacity){
        return 1;
    }
    else {
        return 0;
    }
}


//Insert un Edge dans heap
void MinHeap::Insert(Edge& e) {
	if(isFull()) {
        return;
	}
	else {
        table[nb_element] = e;
        TravUp(nb_element);
        ++nb_element;
	}
}

//Supprime un Edge de heap
void MinHeap::deleteMin() {
	if (nb_element == 0) {
            return;
	}

	table[0] = table[nb_element-1];
	travDown(0);
	--nb_element;
}


//revoie le plus petit Edge
Edge& MinHeap::TakeMin(){

    if (isEmpty()) cout<<"Empty heap"<<endl;
    else return table[0];
}

/*
MinHeap& MinHeap::createMinHeap(Graph* G)//en fait minheap possède 2 argument (src,dist)
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

bool MinHeap::isEmpty(){
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


//revoie la valeur du plus petit Edge
int MinHeap::getMin(){

    if (isEmpty()) cout<<"Empty heap"<<endl;

    // Store the minimum value, and remove it from heap
    int root = table[1].cost;
    table[1] = table[nb_element];
    nb_element--;
    OrganizeHeap(1);

    return root;
}

*/


