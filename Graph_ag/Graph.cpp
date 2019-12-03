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
    cout << "res de file2graph : " << file2graph(FICH) <<endl;

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
            cout << "compt :" << compteur <<endl;
            int k=0;
             while(k<2)  //k =0 value |k= 1 espace
            {
                if (compteur[k]==' ') k=0; //remise a zero lors de l'espace
                else
                {
                        if(compteur[k]=='1')
                        {
                            int c = compteur[k]-48;
                             Edge* e = new Edge(id, c, ListVertex[i],ListVertex[j]);
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

///Crée un graph à partir d'une liste d'adjacence
int Graph::graph_list(ifstream& File){

    try{//return 1 if it construct the graph

        for(int i = 0; i < nb_vertex; ++i){
        ///Création de la liste de vertices
            Vertex* v = new Vertex(i);
            ListVertex.push_back(v);

                int compteur = 0;
                int j, c;
                ///on se place à la bonne ligne (on commence a 0)
                lineX(File,3+i);

                string line;
                getline(File, line);
                    int p = line.size();
                    cout << "line : " <<line << " taille ligne : " << p <<endl;

                    int posEspace =0;
                    while( !endLine(File))
                     {
                         posEspace = line.find(" ");
                         if (compteur%2==0)
                         {
                            string VALUE = line.substr(compteur,compteur+posEspace); //value avant l'espace
                            cout << "VALUE : "<< VALUE <<endl;
                            istringstream iss (VALUE);
                            j = stringToInt(VALUE);

                        }
                        else
                        {
                            string VALUE = line.substr(compteur,compteur+posEspace);
                            cout << "VALUE : "<< VALUE <<endl;
                            istringstream iss (VALUE);

                             c = stringToInt(VALUE);  //2eme val = le cout
                                ///On crée le nouveau edge
                                if (c > 0) {
                                    Edge* e = new Edge(i,c,ListVertex[i],ListVertex[j]);
                                    ListEdge.push_back(e);
                                }

                            compteur = compteur+posEspace+1; //on se met après l'espace
                        }



                     }




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

Graph::~Graph(){
    ///delete adjency matrix

    for (int i =0;i<nb_vertex;i++)
        delete[] Adj[i];
    delete[] Adj;
}
