#include "Floyd_Warshall.h"
#include "Graph.h"

#include <iostream>

using namespace std;

void Floyd_Warshall(Graph* G){
    int dist[G->nb_vertex][G->nb_vertex];

    for (int i =0; i< G->nb_vertex; ++i){
        for(int j= 0; j< G->nb_vertex; ++j){
                dist[i][j]=INT_MAX; //int_max = infini
        }
    }

    for (int i =0; i< G->nb_vertex; ++i){
        dist[i][i]=0;
    }

    for (int i =0; i< G->nb_vertex; ++i){
        for(int j= 0; j< G->nb_vertex; ++j){
                if(G->Adj[i][j]!=0){
                    dist[i][j]=G->Adj[i][j]; //weigh of vertex i to j
                }

        }
    }

     for (int k =0; k< G->nb_vertex; ++k){
        for (int i =0; i< G->nb_vertex; ++i){
            for(int j= 0; j< G->nb_vertex; ++j){
                if( dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX &&
                   dist[i][j]>(dist[i][k]+dist[k][j]))
                {
                    dist[i][j] = dist[i][k]+dist[k][j];
                }
            }
        }
     }

cout << "\n Floyd-Warshall for shortest paths between any couple of vertices:\n";
 cout<<" \t";
    for (int i =0;i<G->nb_vertex;i++)
        cout<<i<<"\t";
    cout<<endl;

    for (int i =0;i<G->nb_vertex;i++){
        cout<<i<<"\t";
        for (int j =0;j<G->nb_vertex;j++)
                if(dist[i][j]==INT_MAX) cout <<"INF\t";
                else cout<<dist[i][j]<<"\t";
        cout<<endl;
    }
    cout<<endl;

}


