#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "Edge.h"
#include "Vertex.h"
#include "Graph.h"
#include "BFS.h"

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
    cout << "\n\n test BFS"<<endl;

    B->BFS(0);

    return 0;
}



