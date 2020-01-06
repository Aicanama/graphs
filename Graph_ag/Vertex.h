#ifndef VERTEX_H
#define VERTEX_H


class Vertex
{
    public:
        //members
        int id;
        int visit;
        int *distance; // distance[i] will hold the cost of the vertex with all the other vertex

        //attribute
        Vertex(int);
        virtual ~Vertex();

        //Distance mise en place
        void cost(int _id,int dist);
};

#endif // VERTEX_H

/**contain attributes and functions on the vertices, ...*/
