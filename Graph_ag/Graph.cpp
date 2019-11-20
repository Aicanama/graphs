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

void Graph::genererMatrice(){
    Adj = new int*[nb_vertex];
    for (int i =0;i<nb_vertex;i++){
        Adj[i] = new int[nb_vertex];
        for (int j =0;j<nb_vertex;j++)
            Adj[i][j]=0;
    }
    int n = ListEdge.size();
    for (int k =0; k<n ;k++){
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

Graph::Graph(){
    /// lecture fichier puis construction graph
    ifstream FICH("file.txt");
    cout << "res de file2graph : " << file2graph(FICH) <<endl;

}


int Graph::file2graph( ifstream& FICH )
{
    ///try fichie

    if(FICH){

        ///first line for nb vertices
            FICH.seekg(0,ios::beg);
            string nb_vertices;
            FICH >> nb_vertices;
                ///conversion string to int and transfert to Graph
                istringstream(nb_vertices) >> nb_vertex;

            ///type of the graph: o for directed graph, n for undirected graph
            FICH.seekg(0,ios::cur);
            string types;
            FICH >> types[0];

            ///type of representation: m adjacency matrix, l adjacency list.
            FICH.seekg(0,ios::cur);
            FICH >> types[1];


        ///gestion exception 3 première lignes
        try {
            if (nb_vertex <0 || (types[0]!='o' && types[0]!='n')  || (types[1]!='m' && types[1]!='l')) throw(-1);
            else throw(1);
        }catch(int nb){
            if (nb!=1) exit (EXIT_FAILURE);  ///si pb dans création graph on stoppe
            else
                {
                    ///lecture fichier avec adjency matrix (directed or undirected) ==>graph_o_matrix
                    if ((types[0] =='o' || types[0] =='n' )&& types[1]=='m') {
                        if (graph_o_matrix(FICH)!=1) exit (EXIT_FAILURE);
                        else return (graph_o_matrix(FICH));
                        }


                }}


    }
    else{

        return 0;

        }

}

int Graph::graph_o_matrix(ifstream& FICH){
    try { //si marche renvoie 1
    try { //exception par mémoire ou allocation
    for(int i=0;i<nb_vertex; ++i)
    {
        Vertex* v = new Vertex(i);
        ListVertex.push_back(v);

    }

    int id=0;
    for (int i=0;i<nb_vertex; ++i)    {
            for (int j=0;j<nb_vertex; ++j) {
            string compteur;   ///string contenant le caractère et l'espace d'après
            FICH.seekg(0,ios::cur);
            FICH >> compteur;

            int k=0;
             while(k<2)  //if k =1 on a pris l'espace donc on a bien l'élément i
            {
                if (compteur[k]==' ') k=0; //remise a zero lors de l'espace
                else
                {
                        if(compteur[k]=='1')
                        {
                             Edge* e = new Edge(id, ListVertex[i],ListVertex[j]);
                             ListEdge.push_back(e);
                            ++id;
                        }
                    }
                    k++;
                }

            }}

    }catch(exception const& e) {return 0;}
    throw 1;
    }catch(int nb){return nb;}
}

Graph::~Graph(){
    ///delete adjency matrix

    for (int i =0;i<nb_vertex;i++)
        delete[] Adj[i];
    delete[] Adj;
}
