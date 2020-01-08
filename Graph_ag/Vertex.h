#ifndef VERTEX_H
#define VERTEX_H

#include <vector>

class Vertex
{
    public:
        //members
        int id;
        int visit;
        std::vector<int> ListNeighbour; // ListNeighbour[i] will hold the id of neighbour

        //attribute
        Vertex(int);
        virtual ~Vertex();

        //mettre la liste de voisin
        /*void setNeighbour(int);
        Vertex& getNeighbour(int)*/
};

#endif // VERTEX_H

/**contain attributes and functions on the vertices, ...*/
