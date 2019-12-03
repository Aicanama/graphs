#ifndef EDGE_H
#define EDGE_H

#include "Vertex.h"

class Edge
{

    public:
        int id;
        int cost;
        Vertex* source;
        Vertex* destination;

        Edge(int, int, Vertex*, Vertex*);
        ~Edge();
    private:
};

#endif // EDGE_H

/**contain the attributes and functions on the edges, ...*/
