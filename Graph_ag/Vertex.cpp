#include "Vertex.h"


Vertex& Vertex::operator=(const Vertex& other)
{
    if (this!=&other)
    {
       id = other.id;
       x = other.x;
       y = other.y;
       color = other.color;
    }
    return *this;
}
