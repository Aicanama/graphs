#include "Edge.h"
#include "Vertex.h"


using namespace std;

Edge::Edge(int _id, int _cost, Vertex* src, Vertex* dest)
{
    this->id = _id;
    this->cost = _cost;
    this->source = src;
    this->destination = dest;
}
