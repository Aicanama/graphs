#include "DisjointSet.h"

using namespace std;

DisjointSet::DisjointSet(int n)
{
    this->n = n;
    rnk = new int[n+1];
    parent = new int[n+1];
    makeSet();

    // Initially, all vertices are in
        // different sets and have rank 0.
        for (int i = 0; i <= n; i++)
        {
            rnk[i] = 0;

            //every element is parent of itself
            parent[i] = i;
        }
}

//Destructor
DisjointSet::~DisjointSet(){
delete parent;
delete rnk;
}

/*void DisjointSet::makeSet()
{
    for(int i = 0; i < n; ++i) {
        parent[i] = i;
    }
}*/

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


void DisjointSet::Union(int x, int y)
    {
        x = Find(x), y = Find(y);

        /* Make tree with smaller height
           a subtree of the other tree  */
        if (rnk[x] > rnk[y])
            parent[y] = x;
        else // If rnk[x] <= rnk[y]
            parent[x] = y;

        if (rnk[x] == rnk[y])
            rnk[y]++;
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
