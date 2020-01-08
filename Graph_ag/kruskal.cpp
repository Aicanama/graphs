#include "kruskal.h"
#include"Graph.h"
#include "MinHeap.h"
#include "DisjointSet.h"
#include <iostream>

using namespace std;


void kruskal(Graph& G) {

    /*cout << "Kruskal Algorithm : " << endl;

	MinHeap MH = MinHeap(G.ListEdge, G.ListEdge.capacity(), G.ListEdge.size());

	//création pointeur
	int* vertexK = new int[G.ListVertex.size()];

	for (int i = 0; i < G.ListVertex.size(); ++i) {
		vertexK[i] = (G.ListVertex[i]->id);
	}


	DisjointSet ds = DisjointSet(G.ListVertex.size());
	unsigned int compteur = 0;

	Edge t;

	while (compteur != G.ListVertex.size()-1) {
		t = MH.TakeMin();

		if (ds.diff(t.destination->id, t.source->id)) {//if in different sets
			cout << "Edge: " << t.id << ",Weight: " << t.cost << ",Connecting vertex " << t.source->id+1 << ",vertex " << t.destination->id+1 << endl;
			ds.Union(t.destination->id, t.source->id);
		}
		else {
			continue;
		}

		MH.deleteMin();
		compteur++;
	}*/
}
