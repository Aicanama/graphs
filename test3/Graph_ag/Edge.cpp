#include "Edge.h"
#include "Vertex.h"


using namespace std;

Edge::Edge(int _id, Vertex* src, Vertex* dest)
{
    this->id = _id;
    this->source = src;
    this->destination = dest;
}
