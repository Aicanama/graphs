#ifndef VERTEX_H
#define VERTEX_H


class Vertex
{
    public:
        //members
        int id;
        int x,y;
        char color;
        int visit;

        //attribute
        Vertex(int);
        virtual ~Vertex();
};

#endif // VERTEX_H

/**contain attributes and functions on the vertices, ...*/
