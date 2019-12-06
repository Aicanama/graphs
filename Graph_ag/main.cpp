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

    BFS(B,0);
    DFS(B,1);

    Dijkstra(B,0);//si affiche gd chiffre = infini

    MinHeap h(B);
    h.AddElement(1);
    h.AddElement(3);
    h.AddElement(6);
    h.AddElement(5);
    h.AddElement(9);

    h.AddElement(4);

cout<<"\n" ;
for (int i =1;i<=h.nb_element;i++)
    {
        cout<<h.table[i]<<" | ";
    }
    return 0;
}



