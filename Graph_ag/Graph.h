#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "time.h"
#include "Vertex.h"
#include "Edge.h"

#include <string>
#include <sstream>
#include <fstream>
#include <list>


class Graph
{
    public:

        /// Construtor
        Graph(int nb_vertex);
        Graph();
        virtual ~Graph();

        /// fonctions
        void afficher();
        void genererMatrice();

        ///fichier lecture
        int file2graph(std::ifstream& FICH);
        int graph_o_matrix(std::ifstream& FICH);
        int graph_list(std::ifstream&);
        void lineX(std::ifstream&, int);
        int stringToInt(std::string);

        ///Visit
        bool isVisited(int);
        void setAllUnvisited();
        void visited(int);

        //affichage de BFS
        void BFS(int);

        //affichage de DFS
        void dfs_util(int);
        void DFS(int);



    public:
        int nb_vertex;
        std::vector<Vertex*> ListVertex;  //V
        std::vector<Edge*> ListEdge;      //E

        int** Adj;
};

#endif // GRAPH_H

/**contain the graph structure and functions on graphs: construction, conversion, paths...*/
