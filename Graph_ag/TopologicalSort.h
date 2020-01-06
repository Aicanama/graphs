#ifndef TOPOLOGICALSORT_H
#define TOPOLOGICALSORT_H

#include "Graph.h"
#include <stack>

void TopologicalSortUtil(int, Graph*, std::stack<int>&);

void TopologicalSort(Graph*);

#endif // TOPOLOGICALSORT_H
