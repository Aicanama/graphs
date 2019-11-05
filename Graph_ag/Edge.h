#ifndef EDGE_H
#define EDGE_H

#include "Vertex.h"

class Edge
{
    private:
        int id;
        Vertex source;
        Vertex destination;

    public:

        Edge(int i, Vertex v1, Vertex v2):id(i),source(v1),destination(v2){};
        virtual ~Edge();
        Edge(const Edge& other):id(other.id),source(other.source), destination(other.destination){};
        Edge& operator=(const Edge& other);

};

#endif // EDGE_H

/**contain the attributes and functions on the edges, ...*/
