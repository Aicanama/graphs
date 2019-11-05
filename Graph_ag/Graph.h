#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "time.h"
#include "Vertex.h"
#include "Edge.h"


class Graph
{
    public:
        Graph(int nb_vertex);
        Graph(const Graph& other);
        virtual ~Graph();
        Graph& operator=(const Graph& other);

        void afficher();


    private:
        int nb_vertex;
        std::vector<Vertex> ListVertex;  //V
        std::vector<Edge> ListEdge;      //E
};

#endif // GRAPH_H

/**contain the graph structure and functions on graphs: construction, conversion, paths...*/
