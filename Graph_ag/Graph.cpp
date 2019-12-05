#include "Graph.h"
#include "Vertex.h"

#include <vector>
#include <time.h>
#include <cstdlib>
#include <iostream>

#include <string>
#include <sstream>
#include <fstream>
#include <list>

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
                 Edge* e = new Edge(id,1,ListVertex[i],ListVertex[j]);
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
        int c = ListEdge[k]->cost;
        int i = ListEdge[k]->source->id;
        int j = ListEdge[k]->destination->id;
        Adj[i][j]=c;
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
    cout << "res de file2graph : " << this->file2graph(FICH) <<endl;

}


Graph::~Graph(){
    ///delete adjency matrix

    for (int i =0;i<nb_vertex;i++)
        delete[] Adj[i];
    delete[] Adj;
}


///fonction qui d�tecte la fin d'une ligne dans un fichier
bool endLine (ifstream& fichier){
    char carac;

    fichier.get(carac);

    if ((carac == '\n') || (carac == '\r')) {
        return true;
    }
    else {
        return false;
    }
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


        ///gestion exception 3 premi�re lignes
        try {
            if (nb_vertex <0 || (types[0]!='o' && types[0]!='n')  || (types[1]!='m' && types[1]!='l')) throw(-1);
            else throw(1);
        }catch(int nb){
            if (nb!=1) exit (EXIT_FAILURE);  ///si pb dans cr�ation graph on stoppe
            else
                {
                    ///lecture fichier avec adjency matrix (directed or undirected) ==>graph_o_matrix
                    if ((types[0] =='o' || types[0] =='n' )&& types[1]=='m') {
                        if (graph_o_matrix(FICH)!=1) exit (EXIT_FAILURE);
                        else return (graph_o_matrix(FICH));
                        }
                     else if ((types[0] =='o' || types[0] =='n' )&& types[1]=='l') {
                        if (graph_list(FICH) != 1) exit (EXIT_FAILURE);
                        else return (graph_list(FICH));
                    }


                }}


    }
    else{

        return 0;

        }

}

int Graph::graph_o_matrix(ifstream& FICH){
    try { //si marche renvoie 1
    try { //exception par m�moire ou allocation
    int i;
    for(i=0;i<nb_vertex; ++i)
    {
        Vertex* v = new Vertex(i);
        ListVertex.push_back(v);

    }

    int id=0;

    for (int i=0; i<nb_vertex; ++i)    {

            lineX(FICH,i+3); //mis en place au niveau voulu

            int compteur = 0;
            int j = 0;

            string line; //string contenant la ligne de la matrix
            getline(FICH, line);

            int posEspace =0;

            while (j<nb_vertex)
            {

                posEspace = line.find(" ",posEspace+1);
                string VALUE = line.substr(compteur,posEspace-compteur);
                istringstream iss (VALUE);
                int c = stringToInt(VALUE);

                Edge* e = new Edge(id, c, ListVertex[i],ListVertex[j]);
                ListEdge.push_back(e);
                ++id;
                ++j;

                compteur = compteur+(posEspace-compteur); //on se met apr�s l'espace

            }



            }

    }catch(exception const& e) {return 0;}
    throw 1;
    }catch(int nb){return nb;}
}

///Cr�e un graph � partir d'une liste d'adjacence
int Graph::graph_list(ifstream& File){

    try{//return 1 if it construct the graph

        for(int i = 0; i < nb_vertex; ++i){
                cout << "\n";
        ///Cr�ation de la liste de vertices
            Vertex* v = new Vertex(i);
            ListVertex.push_back(v);

                int compteur = 0;
                int j, c;
                ///on se place � la bonne ligne (on commence a 0)
                lineX(File,3+i);

                string line;
                getline(File, line);
                    int p = line.size();
                    cout << "line : " <<line << " taille ligne : " << p <<endl;

                    int posEspace =0;
                    while( !endLine(File))
                     {
                         posEspace = line.find(" ",posEspace+1);
                         cout << "posEspace : "<< posEspace  << " compte :" << compteur<<endl;
                         if (compteur%2==0)
                         {
                            string VALUE = line.substr(compteur,posEspace-compteur); //value avant l'espace
                            cout << "VALUE : "<< VALUE <<endl;
                            istringstream iss (VALUE);
                            j = stringToInt(VALUE);

                        }
                        else
                        {
                            string VALUE = line.substr(compteur,posEspace-compteur);
                            cout << "VALUE : "<< VALUE <<endl;
                            istringstream iss (VALUE);

                             c = stringToInt(VALUE);  //2eme val = le cout
                                ///On cr�e le nouveau edge
                                if (c > 0) {
                                    Edge* e = new Edge(i,c,ListVertex[i],ListVertex[j]);
                                    ListEdge.push_back(e);
                                }

                        }
                         compteur = compteur+(posEspace-compteur); //on se met apr�s l'espace

                     }




                //cout << "Le vertex a " << (compteur-1)/2 << " voisin(s)" << endl;

                }
                return 1;

    }
    catch(exception const& e) {return 0;}
}

///Fonction qui place le curseur � la ligne x
void Graph::lineX(ifstream& File, int x) {

        ///on remet le curseur au d�but du fichier
        File.seekg(0, ios::beg);

        ///on le d�place au d�but de la ligne x
        for (int i = 0; i < x; ++i) {
            string line;
            getline(File,line);
        }

}

///fonction qui transforme un string en int
int Graph::stringToInt(string ss){
    int value;

    value = atoi(ss.c_str());
    return value;
}


///Fonction qui met tous les vertices � non visit�
void Graph::setAllUnvisited() {
    for (int i = 0; i < nb_vertex; ++i) {
        ListVertex[i]->visit = 0;
    }
}

///Fonction qui indique si le vertex id est visit�
bool Graph::isVisited(int ID) {
    return ListVertex[ID]->visit;
}


///Fonction qui note le vertex id comme visit�
void Graph::visited(int ID) {
    ListVertex[ID]->visit = 1;
}

//id : vertex de d�part
void Graph::BFS(int ID) {

    list<int> q;

    //on note tous les vertex comme non visit�s
    setAllUnvisited();

    //on visite le 1er
    visited(ID);

        //on l'ajoute � la queue
        q.push_back(ID);

    //on continue de visiter les autres vertices
    while (!q.empty()) {
        ID = q.front();
        cout << "Visited " << ID << " ";
        q.pop_front();

        //en fonction du nombre d'edge !!!!!! REVOIR COMMENT OBTENIR CA
         int currVertex;

        for(int i = 0; i< nb_vertex; ++i)
        {   int k =0;

            while( Adj[ID][i]!=0 && k<1){
                k++;
                currVertex = i;
                    if (!isVisited(currVertex)) {
                        visited(currVertex);
                        q.push_back(currVertex);
                    }

            }
        }
    }
}

///Fonction qui visite le vertex
void Graph::dfs_util(int ID) {

    visited(ID);
    cout << "Visited " << ID << " ";

    int currVertex;
    for(int i =0; i< nb_vertex; ++i)
        {
            if(Adj[ID][i]!=0){
                currVertex = i;
                if(!isVisited(currVertex)) {
                    dfs_util(currVertex);
                }
            }
    }
}

///Fonction qui r�p�te la fonction dfs_util
void Graph::DFS(int ID) {

    //on note tous les vertex comme non visit�s
    setAllUnvisited();
    //recursive call
    dfs_util(ID);

}
