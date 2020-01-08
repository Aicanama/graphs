#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

#include "Edge.h"
#include "Vertex.h"
#include "Graph.h"
#include "Dijkstra.h"
#include "BFS.h"
#include "DFS.h"
#include "MinHeap.h"
#include "Floyd_Warshall.h"
#include "TopologicalSort.h"
#include "Strongly_Related.h"
#include "Prim.h"
#include "kruskal.h"


using namespace std;

int main()
{
    /*graph random : */
    /*Graph* G = new Graph(3);
    G->genererMatrice();
    G->afficher();*/

    Graph* B = new Graph();
    B->genererMatrice();
    B->afficher();
    B->genererDistVertex();


    Floyd_Warshall(B);

    //BFS(B,0); no neeed because of graph connex
    //print BFS too
    if(!B->graph_connexe())cout<<"\n le graphe n'est pas connex" <<endl;
    else cout<<"\n le graph est connex"<<endl;


    DFS(B,0);

    Dijkstra(B,0);//si affiche INF = infini

    TopologicalSort(B);

    Strongly_Related(B);

    Prim(B);

    int msw_t;
    msw_t= kruskal(B);
     cout << "\nWeight of MST is " << msw_t;

    return 0;
}



