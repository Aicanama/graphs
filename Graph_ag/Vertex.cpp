#include "Vertex.h"
#include <iostream>

using namespace std;

Vertex::Vertex(int _id)
{
       this->id = _id;
}


Vertex::~Vertex(){
    delete[] distance;
}

void Vertex::cost(int _id,int dist){
    distance[_id] = dist;
}
