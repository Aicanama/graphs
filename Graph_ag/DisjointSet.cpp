#include "DisjointSet.h"

using namespace std;

DisjointSet::DisjointSet(int n)
{
    rnk = new int[n];
    parent = new int[n];
    this->n = n;
    makeSet();
}

//Destructor
DisjointSet::~DisjointSet(){}

void DisjointSet::makeSet()
{
    for(int i = 0; i < n; ++i) {
        parent[i] = i;
    }
}
int DisjointSet::Find(int x)
    {
        // Finds the representative of the set
        // that x is an element of
        if (parent[x] != x) {

            // if x is not the parent of itself
            // Then x is not the representative of
            // his set,
            parent[x] = Find(parent[x]);

            // so we recursively call Find on its parent
            // and move i's node directly under the
            // representative of this set
        }
        return parent[x];
    }


void DisjointSet::Union(int m, int n) { // perform Union of two subsets m and n
      int x = Find(m);
      int y = Find(n);
      parent[x] = y;
}

bool DisjointSet::diff(int a, int b) {
    if(a != b) {
        return true;
    }
    else {
        return false;
    }
}

bool DisjointSet::operator!=(DisjointSet a) {
    if((this->n != a.n) && (this->rnk != a.rnk) && (this->parent != a.parent)) {
        return true;
    }
    else {
        return false;
    }
}
