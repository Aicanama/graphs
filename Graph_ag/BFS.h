#ifndef BFS_H
#define BFS_H

#include "Graph.h"
#include <vector>
#include <queue>
#include <cstdlib>
#include <iostream>
#include <queue>

class BFS
{
    public:
        BFS(Graph* G, int id);
        virtual ~BFS();

};

#endif // BFS_H
