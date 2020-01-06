#include "Graph.h"
#include "Vertex.h"
#include "Floyd_Warshall.h"
#include "BFS.h"

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

void Graph::genererDistVertex(){
    int k=0;

    for (int i=0;i<nb_vertex;i++){
    ListVertex[i]->distance = new int[nb_vertex];
    }

  Floyd_Warshall(this);

  cout<<" \t";
    for (int i =0;i<nb_vertex;i++)
        cout<<i<<"\t";
    cout<<endl;

    for (int i =0;i<nb_vertex;i++){
        cout<<i<<"\t";
        for (int j =0;j<nb_vertex;j++)
                if(ListVertex[i]->distance[j]==INT_MAX) cout <<"INF\t";
                else cout<<ListVertex[i]->distance[j]<<"\t";
        cout<<endl;
    }
    cout<<endl;





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


///fonction qui détecte la fin d'une ligne dans un fichier
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
    try { //exception par mémoire ou allocation
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

                compteur = compteur+(posEspace-compteur); //on se met après l'espace

            }



            }

    }catch(exception const& e) {return 0;}
    throw 1;
    }catch(int nb){return nb;}
}


///Fonction qui trie ordre croissant
void Graph::sortEdge() {
    int length = nb_edge;

    for (int i = 0; i < length-1; ++i) {
        for (int j = 0; j < length-1-i; ++j) {
            if ((ListEdge[j]->cost) > (ListEdge[j+1]->cost)) {
                Edge* p = ListEdge[j+1];
                ListEdge[j+1] = ListEdge[j];
                ListEdge[j] = p;
            }
        }
    }
}


///Fonction qui vérifie qu'un vertex est bien dans la liste
int Graph::verifV(int ID, Vertex*& v){
    for(int i=0; i<nb_vertex; ++i) {
        if (ListVertex[i]->id == ID) {
            v = ListVertex[i];
            return 1;
        }
    }
    return 0;
}



///Crée un graph à partir d'une liste d'adjacence
int Graph::graph_list(ifstream& File){

    try{///return 1 if it construct the graph
        for(int i = 0; i < nb_vertex; ++i){
            ///Création de la liste de vertices
            Vertex* v = new Vertex(i);
            ListVertex.push_back(v);
        }

        ///variables pour la suite
        int compteur = 0, counter = 0;
        int j = 0, c = 0, id = 0;

        for (int i = 0; i < nb_vertex; ++i) {
            ///on se place à la bonne ligne (on commence a 0)
            lineX(File,3+i);

            string line;
            getline(File, line);
            int taille = line.size();
            cout << endl << "taille de la ligne : " << taille << endl << endl;

            ///on se replace au début de la ligne
            File.seekg(0,ios::beg);
            lineX(File,3+i);

            do {
                string morceau;
                File >> morceau;
                cout << "morceau : " << morceau << endl;

                int p = morceau.size();

                if(counter%2 == 0) {
                    j = stringToInt(morceau);
                }
                else {
                    c = stringToInt(morceau);
                    ///On crée le nouveau edge
                    Edge* e = new Edge(id, c, ListVertex[i],ListVertex[j]);
                    ListEdge.push_back(e);
                }

                compteur = compteur + p + 1;
                cout << "compteur : " << compteur << endl << endl;
                counter++;
                id++;
            }
            while(compteur <= taille);

            compteur = 0;
            cout << "On passe a la ligne suivante!" << endl << endl;
            //cout << "Le vertex a " << (compteur-1)/2 << " voisin(s)" << endl;
        }
        return 1;
    }
    catch(exception const& e) {return 0;}
}

///Fonction qui place le curseur à la ligne x
void Graph::lineX(ifstream& File, int x) {

        ///on remet le curseur au début du fichier
        File.seekg(0, ios::beg);

        ///on le déplace au début de la ligne x
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


///Fonction qui met tous les vertices à non visité
void Graph::setAllUnvisited() {
    for (int i = 0; i < nb_vertex; ++i) {
        ListVertex[i]->visit = 0;
    }
}

///Fonction qui indique si le vertex id est visité
bool Graph::isVisited(int ID) {
    return ListVertex[ID]->visit;
}


///Fonction qui note le vertex id comme visité
void Graph::visited(int ID) {
    ListVertex[ID]->visit = 1;
}


///Fonction qui traverse le graph et compte le nb de vertices visités
int Graph::pathes_prefixe(Graph* G){
    vector<int> v;
    v = BFS(G,0);

    int nbVisited = v.size();
    return nbVisited;
}


///Fonction qui vérifie la "relatedness" du graph
bool Graph::graph_connexe(Graph* G){
    int value = pathes_prefixe(G);
    if(G->nb_vertex == value) return 1;
    else return 0;
}

