#include "Edge.h"
#include "Vertex.h"


using namespace std;

Edge::Edge(){};

Edge::Edge(int _id, int _cost, Vertex* src, Vertex* dest)
{
    this->id = _id;
    this->cost = _cost;
    this->source = src;
    this->destination = dest;
}

Edge& Edge::operator=(const Edge& ed) {
	if(this != &ed) {
		this->id = ed.id;
		this->cost = ed.cost;
		this->destination = ed.destination;
		this->source = ed.source;
	}
	return *this;
}

Edge::~Edge(){
    delete source;
    delete destination;
}
