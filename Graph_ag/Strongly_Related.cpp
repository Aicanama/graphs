#include "Strongly_Related.h"
#include "DFS.h"

#include <iostream>

using namespace std;

Graph getTranspose(Graph* G)
{    Graph g = Graph(1);

     g.nb_vertex = G->nb_vertex;
     g.nb_edge = G->nb_edge;

        g.ListVertex = G->ListVertex;
        g.ListEdge = G->ListEdge;

        g.genererMatrice();

    for (int i =0;i<g.nb_vertex;i++)
        for (int j =0;j<g.nb_vertex;j++)
             g.Adj[j][i]= G->Adj[i][j];

        return g;
}

void fillOrder(int v, stack<int> &Stack, Graph* G)
{
    // Mark the current node as visited and print it
    G->visited(v);

    // Recur for all the vertices adjacent to this vertex
     for(int i=0; i<G->nb_vertex; ++i)
    {
         if(G->Adj[v][i]!=0){
            int currentVertex = i;
            if(!G->isVisited(currentVertex))
            fillOrder(currentVertex, Stack, G);
        }

     }
    // All vertices reachable from v are processed by now, push v
    Stack.push(v);

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
   Graph GTrans = getTranspose(G);
   GTrans.afficher();


    // Mark all the vertices as not visited (For second DFS)
   GTrans.setAllUnvisited();

   cout << "Strongly_Related : strongly connected component on the same line\n";
    // Now process all vertices in order defined by Stack
    while (Stack.empty() == false)
    {
        // Pop a vertex from stack
        int v = Stack.top();
        Stack.pop();

        // Print Strongly connected component of the popped vertex
       if (!GTrans.isVisited(v))
        {
            dfs_util2(GTrans,v);
            cout << endl;
        }
    }

}
