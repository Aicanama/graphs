#include "Graph.h"
#include "Vertex.h"

#include <vector>
#include <time.h>
#include <cstdlib>
#include <iostream>

#include <string>
#include <sstream>
#include <fstream>


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

    ifstream File("file.txt");

    if(File)
    {
        ///first line for nb vertices
        File.seekg(0,ios::beg);
        string nb_vertices;
        File >> nb_vertices;
            ///conversion string to int and transfert to Graph
            istringstream(nb_vertices) >> this->nb_vertex;
            cout << nb_vertex<<endl;

        ///type of the graph: o for directed graph, n for undirected graph
        File.seekg(0,ios::cur);
        string types;
        File >> types[0];
        cout << types[0] <<endl;

        ///type of representation: m adjacency matrix, l adjacency list.
        File.seekg(0,ios::cur);
        File >> types[1];
        cout << types[1]<<endl;


    for(int i=0;i<nb_vertex; ++i)
    {
        Vertex* v = new Vertex(i);
        ListVertex.push_back(v);

    }
    srand(time(NULL));


    int id=0;

    for (int i=0;i<nb_vertex; ++i)    {
            for (int j=0;j<nb_vertex; ++j) {

            string compteur; ///string
            File.seekg(0,ios::cur);
            File >> compteur;

            int k=0;
            while(k<2)  //
            {
                if (compteur[k]==' ') k=0;
                else
                {
                        if(compteur[k]=='1')
                        {
                             Edge* e = new Edge(id,ListVertex[i],ListVertex[j]);
                             ListEdge.push_back(e);
                            ++id;
                        }
                    }
                    k++;
                }

            }
        }
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }

}

Graph::~Graph(){
    ///delete adjency matrix

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
