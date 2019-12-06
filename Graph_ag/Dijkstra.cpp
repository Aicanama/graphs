#include "Dijkstra.h"
#include "Graph.h"
#include <iostream>

using namespace std;

//pick the vertex <ith the minimum vertex
int minDistance(Graph* G,int dist[]) {
    // Initialize min value
    int mini=INT_MAX, min_index;

    for (int v = 0; v < G->nb_vertex; v++){
        if (!G->isVisited(v) && dist[v] < mini){
            mini = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void Dijkstra(Graph* G,int ID){
    int dist[G->nb_vertex]; // dist[i] will hold the shortest path
    int pred[G->nb_vertex]; //pred[i] will hold the "father" of the vertex for the shortest path

    G->setAllUnvisited(); //put every vertices unVisited

    for (int i =0; i< G->nb_vertex; ++i){
        dist[i]=INT_MAX; //int_max = infini
        pred[i]=INT_MAX;
    }

    // Distance of source vertex from itself is always 0
    dist[ID] = 0;

    // Find shortest path for all vertices
    for (int k = 0; k < G->nb_vertex; ++k) {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        int u = minDistance(G,dist);

         // Mark the picked vertex as processed
        G->visited(u);

        for( int v=0; v<G->nb_vertex; ++v){
                //test si le vertex current (v) n'est pas encore visité, si src (=u) est bien visité, si v est voisin avec u,
                //si distance de src + current < distance que possède déjà currrent
            if(!G->isVisited(v) && dist[u]!=INT_MAX && G->Adj[u][v]!=0
               && dist[u] + G->Adj[u][v] < dist[v] ){

                    dist[v] = dist[u] + G->Adj[u][v];
                    pred[v] = u;

            }
        }

    }

    printf("\n\n Dijkstra : \nVertex \t\t Distance \tPredecessor\n");
    for (int i = 0; i < G->nb_vertex; i++){
        cout<<i<< " \t\t " << dist[i] << "\t\t "<<pred[i]  <<endl;
    }

}

