#ifndef VERTEX_H
#define VERTEX_H

#include "Edge.h"


class Vertex
{
    public:
        Vertex():id(),x(),y(),color(){};
        Vertex(int idi):id(idi),x(),y(),color(){};
        virtual ~Vertex();
        Vertex(const Vertex& other):id(other.id),x(other.x),y(other.y),color(other.color){};
        Vertex& operator=(const Vertex& other);

    friend class Edge;

    private:
        int id;
        int x,y;
        char color;
};

Vertex V;

#endif // VERTEX_H

/**contain attributes and functions on the vertices, ...*/
