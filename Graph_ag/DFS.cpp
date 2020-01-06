#include "DFS.h"

#include "Graph.h"
#include <iostream>

using namespace std;


///Fonction qui visite le vertex
void dfs_util(Graph* G, int ID) {

    G->visited(ID);
    cout << " " << ID << " ";

    int currVertex;
    for(int i =0; i< G->nb_vertex; ++i)
        {
            if(G->Adj[ID][i]!=0){
             currVertex = i;
                if(!G->isVisited(currVertex)) {
                    dfs_util(G,currVertex);
                }
            }
    }
}

///Fonction qui répète la fonction dfs_util
void DFS(Graph* G,int ID) {

     cout << "\n\n DFS starts at "<< ID <<endl;

    //on note tous les vertex comme non visités
    G->setAllUnvisited();
    //recursive call
    dfs_util(G,ID);
}

///Fonction qui visite le vertex
void dfs_util2(Graph& G, int ID) {

    G.visited(ID);
    cout << " " << ID << " ";

    int currVertex;
    for(int i =0; i< G.nb_vertex; ++i)
        {
            if(G.Adj[ID][i]!=0){
             currVertex = i;
                if(!G.isVisited(currVertex)) {
                    dfs_util2(G,currVertex);
                }
            }
    }
}

