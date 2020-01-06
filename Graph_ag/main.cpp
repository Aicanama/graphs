#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

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


using namespace std;

int main()
{
    /*Graph* G = new Graph(3);
    G->genererMatrice();
    G->afficher();*/
    cout << "test file"<< endl;
    Graph* B = new Graph();
    B->genererMatrice();
    B->afficher();
    B->genererDistVertex();


    BFS(B,0);

    DFS(B,1);

    Dijkstra(B,0);//si affiche INF = infini

    /**MinHeap h(B); //construct add(i)--> avoir voisin

    cout<<"\n MinHeap  " ;
    for (int i =1;i<=h.nb_element;i++)
    {
        cout<<h.table[i]<<" | ";
    }*/

    TopologicalSort(B);

    //Strongly_Related(B);

    return 0;
}



