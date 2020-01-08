#include"Graph.h"
#include "MinHeap.h"
#include "kruskal.h"
#include <iostream>

#include <vector>;

#include <cstring>;

using namespace std;

// A utility function to find the subset of an element i
int find(int parent[], int i)
{
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

// A utility function to do union of two subsets
void UnionHere(int parent[], int x, int y)
{
    int xset = find(parent, x);
    int yset = find(parent, y);
    if(xset != yset)
    {
        parent[xset] = yset;
    }
}

int kruskal(Graph* G){

    cout << "Kruskal Algorithm : " << endl;
    cout << "MST :" << endl << "Edge \tWeight" << endl;

    //Initialisation
	int mstWeight = 0;
	vector<Edge*> liste = G->ListEdge;

	// Create disjoint sets
    int *parent = new int[G->nb_vertex * sizeof(int)];
    // Initialize all subsets as single element sets
    memset(parent, -1, sizeof(int) * G->nb_vertex);

    liste = sortingCost(liste);


    vector<int> tabIdEdgeAvecCost;

    for(int i = 0; i < liste.size(); ++i){
           if(liste[i]->cost!=0){
                tabIdEdgeAvecCost.push_back(i);
            }
    }


	for(int i = tabIdEdgeAvecCost[0]; i < tabIdEdgeAvecCost[tabIdEdgeAvecCost.size()-1]; ++i){

         int u = liste[i]->source->id;
        int v = liste[i]->destination->id;

         int set_u = find(parent, u);
       int set_v = find(parent, v);

       // Check if the selected edge is creating
        // a cycle or not (Cycle is created if u
        // and v belong to same set)
        if (set_u != set_v)
        {
            // Current edge will be in the MST
            // so print it
            cout << u << " - " << v <<"\t "<<liste[i]->cost<< endl;

            // Update MST weight
            mstWeight += liste[i]->cost;

            // Merge two sets
            UnionHere(parent,set_u, set_v);
        }
    }

    return mstWeight;

}


///Fonction qui tri les edges en fonction de leur coût (du min au plus)
vector<Edge*> sortingCost(vector<Edge*> _ListEdge) {
	//attribut dont on aura besoin
	vector<Edge*> listEdge_sorted;
	listEdge_sorted.push_back(_ListEdge[0]);
	int counter = 0;
	bool test;


	for (int i = 1; i < _ListEdge.size(); ++i) {
		test = true;

		while (test){
			if (counter == listEdge_sorted.size()) {
				counter = 0;
				test = 0;
				listEdge_sorted.push_back(_ListEdge[i]);
			}
			else {
				if (listEdge_sorted[counter]->cost > _ListEdge[i]->cost) {
					listEdge_sorted.insert(listEdge_sorted.begin() + (counter+1), listEdge_sorted[counter]);
					listEdge_sorted[counter] = _ListEdge[i];
					counter = 0;
					test = 0;
				}
				else {
					counter++;
				}
			}
		}
	}
	return listEdge_sorted;
}
/** krustal v2

int kruskal(Graph* G){

    cout << "Kruskal Algorithm : " << endl;
    cout << "MST :" << endl << "Edge \tWeight" << endl;

    //Initialisation
	int mstWeight = 0;
	vector<Edge*> liste = G->ListEdge;

    liste = sortingCost(G);

    for(unsigned int i = 0; i < liste.size(); ++i){
        Vertex* u = liste[i]->source;
        Vertex* v = liste[i]->destination;

        Vertex* set_u = Find(u);
        Vertex* set_v = Find(v);

        //on vérifie qu'ils n'appartiennent pas au même set
        if (set_u != set_v)
        {
            //on affiche l'edge car il sera dans le MST
            cout << u->id << " - " << v->id << "\t" << liste[i]->cost << endl;

            //on update le résultat
            mstWeight = mstWeight + liste[i]->cost;

            // Merge two sets
            Union(liste[i]);
        }
    }

    for (int i = 0; i < G->nb_vertex; ++i) {
        G->ListVertex[i]->parent = G->ListVertex[i];
    }

    cout << "Le MST a un poids de : " << mstWeight << endl;

    return mstWeight;
}



///Fonction qui trie les edges en fonction de leur coût (du min au plus)
vector<Edge*> sortingCost(Graph* G) {
	//attributs dont on aura besoin
	vector<Edge*> listEdge_sorted;
	unsigned int counter = 0;
	bool test;

	listEdge_sorted.push_back(G->ListEdge[0]);

	for (unsigned int i = 1; i < G->ListEdge.size()/2; ++i) {
            test = true;

            while (test){
                if (counter == listEdge_sorted.size()) {
                    counter = 0;
                    test = false;
                    listEdge_sorted.push_back(G->ListEdge[i]);
                }
                else {
                    if (listEdge_sorted[counter]->cost > G->ListEdge[i]->cost) {
                        listEdge_sorted.insert(listEdge_sorted.begin()+(counter+1), listEdge_sorted[counter]);
                        listEdge_sorted[counter] = G->ListEdge[i];
                        counter = 0;
                        test = false;
                    }
                    else {
                        counter++;
                    }
                }
            }
	}


	return listEdge_sorted;
}


///Fonction qui fait l'union en fonction du rank
void Union(Edge* e)
{
	Vertex* x = e->source->parent;
	Vertex* y = e->destination->parent;

	x = Find(x);
    y = Find(y);

	// Make tree with smaller height a subtree of the other tree
	if (x->rnk > y->rnk)
		y->parent = x;
	else {
        // If rnk[x] <= rnk[y]
		x->parent = y;
	}
	if (x->rnk == y->rnk)
		++(y->rnk);
}



///Fonction qui cherche le parent du vertex
Vertex* Find(Vertex* _u)
{
	if (_u != _u->parent) {
		_u->parent = Find(_u->parent);
	}

	return _u->parent;
}*/
