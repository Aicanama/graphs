#include "BFS.h"

#include "Graph.h"
#include <vector>
#include <queue>
#include <cstdlib>
#include <iostream>
#include <queue>


using namespace std;

//id : vertex de départ
void BFS(Graph* G, int id) {

    queue<int> q;

    //on note tous les vertex comme non visités
    G->setAllUnvisited();

    //on visite le 1er
    G->visit(id);
    //on l'ajoute à la queue
    q.push(id);

    //on continue de visiter les autres vertices
    while (!q.empty()) {
        id = q.front();
        cout << id << " ";
        q.pop();

        //en fonction du nombre d'edge !!!!!! REVOIR COMMENT OBTENIR CA
        for (int i = 0; i < 5 ; ++i) {
            if (!G->isVisited(id)) {
                G->visit(id);
                q.push(i);
            }
        }
    }
}


