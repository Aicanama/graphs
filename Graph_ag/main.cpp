#include <iostream>

#include "Edge.h"
#include "Vertex.h"
#include "Graph.h"

using namespace std;

int main()
{
    Graph* G= new Graph(10);
    G->genererMatrice();
    G->afficher();
    cout << "test file"<< endl;
    Graph* B = new Graph();
    return 0;
}

