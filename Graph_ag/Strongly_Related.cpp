#include "Strongly_Related.h"
#include "DFS.h"

#include <iostream>

using namespace std;

Graph* getTranspose(Graph* G)
{
    Graph* g =  new Graph(G->nb_vertex);

    for (int i =0;i<G->nb_vertex;i++)
        for (int j =0;j<G->nb_vertex;j++)
            g->Adj[j][i]=G->Adj[i][j];
    cout << "gtranspoe fnct : g->nb_vertex  "<< g->nb_vertex <<  " listVertex[2] = " << g->ListVertex[2]<<endl;
    return g;
}

void fillOrder(int v, stack<int> &Stack, Graph* G)
{
    // Mark the current node as visited and print it
    G->visited(v);

    // Recur for all the vertices adjacent to this vertex
     for(int i=0; i<G->nb_vertex; ++i)
    {
        cout << "bouclde de "<<v<<endl;
         if(G->Adj[v][i]!=0){
            int currentVertex = i;
            cout << "curr vertex voisin de "<< v<<" : " << currentVertex<<endl;
            if(!G->isVisited(currentVertex))
            fillOrder(currentVertex, Stack, G);
        }

     }
     cout << "fin boucle " <<endl<<endl;
    // All vertices reachable from v are processed by now, push v
    Stack.push(v);

    cout << "Stack top : " << Stack.top() <<endl;;
}

void Strongly_Related(Graph* G){
    // The main function that finds and prints all strongly connected
// components
    stack<int> Stack;

    G->setAllUnvisited();

    // Fill vertices in stack according to their finishing times
    for(int i = 0; i < G->nb_vertex; i++)
        if(!G->isVisited(i))
            fillOrder(i, Stack, G);

    // Create a reversed graph
    Graph* GTrans = getTranspose(G);

    // Mark all the vertices as not visited (For second DFS)
    GTrans->setAllUnvisited();

    // Now process all vertices in order defined by Stack
    while (Stack.empty() == false)
    {
        // Pop a vertex from stack
        int v = Stack.top();
        Stack.pop();

        // Print Strongly connected component of the popped vertex
        if (!GTrans->isVisited(v))
        {
            dfs_util(GTrans,v);
            cout << endl;
        }
    }
}
