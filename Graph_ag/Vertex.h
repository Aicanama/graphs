#ifndef VERTEX_H
#define VERTEX_H


class Vertex
{
    public:
        Vertex(int);
        virtual ~Vertex();

        int id;
        int x,y;
        char color;
    private:
};

#endif // VERTEX_H

/**contain attributes and functions on the vertices, ...*/
