#ifndef DFS_H
#define DFS_H

#include "Graph.h"

void DFS(Graph*, int);
void dfs_util(Graph* G, int ID);
void dfs_util_strong(Graph& G, int ID);

#endif // DFS_H
