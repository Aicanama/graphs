#include "Graph.h"
#include "Vertex.h"

#include <vector>
#include <time.h>
#include <cstdlib>
#include <iostream>

using namespace std;

Graph::Graph( int _nb_vertex )
{
    this->nb_vertex = _nb_vertex;

    for (int i=0;i<nb_vertex; ++i)
    {
        Vertex* v = new Vertex(i);
        ListVertex.push_back(v);

    }
    srand(time(NULL));

    int id=0;
    for (int i=0;i<nb_vertex; ++i)    {
        for (int j=0;j<nb_vertex; ++j)        {
            if (i==j)continue;
            int r=rand()%2;
            if(r==1) /// il existe un lien
            {
                 Edge* e = new Edge(id,ListVertex[i],ListVertex[j]);
                 ListEdge.push_back(e);
                ++id;
            }
        }
    }

}

Graph::Graph(){
    /// lecture fichier
}
Graph::~Graph(){
    ///

    for (int i =0;i<nb_vertex;i++)
        delete[] Adj[i];
    delete[] Adj;
}

void Graph::genererMatrice(){
    Adj = new int*[nb_vertex];
    for (int i =0;i<nb_vertex;i++){
        Adj[i] = new int[nb_vertex];
        for (int j =0;j<nb_vertex;j++)
            Adj[i][j]=0;
    }
    int n = ListEdge.size();
    for (int k =0; k<ListEdge.size();k++){
        int i = ListEdge[k]->source->id;
        int j = ListEdge[k]->destination->id;
        Adj[i][j]=1;
    }
}

void Graph::afficher(){

    cout<<" \t";
    for (int i =0;i<nb_vertex;i++)
        cout<<i<<"\t";
    cout<<endl;

    for (int i =0;i<nb_vertex;i++){
        cout<<i<<"\t";
        for (int j =0;j<nb_vertex;j++)
            cout<<Adj[i][j]<<"\t";
        cout<<endl;
    }
    cout<<endl;
}
