#include "Prim.h"
#include <iostream>

using namespace std;

void Prim(Graph* G)
{

    int nb = 0;
    G->setAllUnvisited();

    G->visited(0);
     // print for edge and weight
        cout << "Prim : \nEdge" << " : " << "Weight";
      cout << endl;

// the number of egde in minimum spanning tree will be
  // always less than (V -1), where V is number of vertices in
  //graph
    while (nb < G->nb_vertex-1) {

  //For every vertex in the set S, find the all adjacent vertices
  // , calculate the distance from the vertex selected at step 1.
  // if the vertex is already in the set S, discard it otherwise
  //choose another vertex nearest to selected vertex  at step 1.

      int min = INT_MAX, debut = 0, fin = 0;


      for (int i = 0; i < G->nb_vertex; i++) {
        if (G->isVisited(i)) {
            for (int j = 0; j < G->nb_vertex; j++) {
              if (!G->isVisited(j) && G->Adj[i][j]!=0) { // not visited and there is an edge
                  if (min > G->Adj[i][j]) {
                      min = G->Adj[i][j];
                      debut = i;
                      fin = j;
                  }

              }
          }
        }
      }
      cout << debut <<  " - " << fin << " :  " << G->Adj[debut][fin];
      cout << endl;
      G->visited(fin);
      nb++;
    }
       cout << endl;

}

