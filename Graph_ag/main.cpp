#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "Edge.h"
#include "Vertex.h"
#include "Graph.h"

using namespace std;

int main()
{
    Graph* G = new Graph(10);
    G->genererMatrice();
    G->afficher();
    cout << "test file"<< endl;
    Graph* B = new Graph();
    B->genererMatrice();
    B->afficher();

    cout << "\n test BFS file start at 0"<<endl;
    B->BFS(0);
    cout << "\n test DFS file start at 1"<<endl;
    B->DFS(1);
    return 0;
}



