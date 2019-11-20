#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "time.h"
#include "Vertex.h"
#include "Edge.h"

#include <string>
#include <sstream>
#include <fstream>

#include "graph_o_matrix.h"


class Graph
{
    public:

        /// Construtor
        Graph(int nb_vertex);
        Graph();
        ~Graph();

        /// fonctions
        void afficher();
        void genererMatrice();

        ///fichier lecture
        int file2graph(char* fich );


    private:
        int nb_vertex;
        std::vector<Vertex*> ListVertex;  //V
        std::vector<Edge*> ListEdge;      //E


        int** Adj;
};

#endif // GRAPH_H

/**contain the graph structure and functions on graphs: construction, conversion, paths...*/
