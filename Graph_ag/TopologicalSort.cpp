#include "TopologicalSort.h"
#include "Graph.h"
#include <iostream>
#include <stack>

using namespace std;

///Fonction qui visite le vertex
void TopologicalSortUtil(int ID, Graph* G, stack<int>& Stack) {
    //mark as visited
    G->visited(ID);

    //recur for all the vertices adjacent to this vertex
    for(int i=0; i<G->nb_vertex; ++i){
            if(G->Adj[ID][i]!=0){
                if(!G->isVisited(i)) TopologicalSortUtil(i, G, Stack);
            }

        }
        Stack.push(ID);
    }



void TopologicalSort(Graph* G){

    stack<int> Stack;
    ///on marque tous les vertices comme non visités
    G->setAllUnvisited();

    ///recursive call
    for(int i = 0; i < G->nb_vertex; ++i){
        if (!G->isVisited(i)){
            TopologicalSortUtil(i,G,Stack);
        }
    }

    ///Print contents of stack
    cout << "TopologicalSort : "<<endl;
    while (Stack.empty() == false) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}
