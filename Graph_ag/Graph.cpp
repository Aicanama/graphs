#include "Graph.h"
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

Graph::Graph( int nb_vertex )
{
    int i;

    for (i=0;i<nb_vertex; ++i)
    {
        Vertex v(i);
        ListVertex.push_back(v);

    }

    int id=0;
    for (i=0;i<nb_vertex; ++i)
    {
        for (int j=0;j<nb_vertex; ++j)
        {

            int r=rand()%2;
            if(r==1)
            {
                 Edge e(id,ListVertex[i],ListVertex[j]);
                 ListEdge.push_back(e);
            }
            else
            {
                Edge e(id,ListVertex[j],ListVertex[i]);
                ListEdge.push_back(e);
            }
             ++id;
        }
    }



}


Graph& Graph::operator=(const Graph& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

