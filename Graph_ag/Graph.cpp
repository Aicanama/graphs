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

Graph::Graph(){
    /// lecture fichier puis construction graph
    cout << "res de file2graph : " << file2graph("file.txt") <<endl;
     /!\pb avec les exception de si graphe pas assez ecrit dans fichier n doit pas construire le graph

}


int Graph::file2graph(char* fich )
{

    int n;
    ifstream FICH(fich);
try { //test 3 premiere ligne et pas de chier
    try { // test si exception
    if(FICH)
    {
            ///first line for nb vertices
            FICH.seekg(0,ios::beg);
            string nb_vertices;
            FICH >> nb_vertices;
                ///conversion string to int and transfert to Graph
                istringstream(nb_vertices) >> this->nb_vertex;
                cout << nb_vertex<<endl;

            ///type of the graph: o for directed graph, n for undirected graph
            FICH.seekg(0,ios::cur);
            string types;
            FICH >> types[0];
            cout << types[0] <<endl;

            ///type of representation: m adjacency matrix, l adjacency list.
            FICH.seekg(0,ios::cur);
            FICH >> types[1];
            cout << types[1]<<endl;

            ///gestion exception 3 première lignes
            if (nb_vertex <0 || (types[0]!='o' && types[0]!='n')  || (types[1]!='m' && types[1]!='l')) throw(n=-1);

                ///lecture fichier avec adjency matrix (directed)


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

                }
            }
    throw 1;
    }

    else
    {
        cerr << "erreur dans le fichier " << fich << endl;
        throw 0;

    }
    }catch(int nb){return nb;}


    }catch(exception const& e) {return 0;}


}

Graph::~Graph(){
    ///delete adjency matrix

    for (int i =0;i<nb_vertex;i++)
        delete[] Adj[i];
    delete[] Adj;
}
