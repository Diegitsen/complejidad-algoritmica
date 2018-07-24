#include <iostream>
#include <vector>
#include <algorithm>

#include "disjointset.h"

using namespace std;

typedef  pair<int, int> iPair; // u, v vertex


class Graph{

public:
	int n, m; // n is number of Vertex, m is Edge
	vector< pair<int, iPair> > edges;

	Graph(int n, int m){
		this->n = n;
		this->m = m;
	}

	void addEdge(int u, int v, int w){
		edges.push_back({ w, { u, v } });
	}

	int kruskalMST(){
		int mst_wt = 0;
		
		sort(edges.begin(), edges.end());
		//---
		DisjointSets ds(n);
		//---
		vector< pair<int, iPair>>::iterator it;
		//--
		for (it = edges.begin(); it != edges.end(); it++){
			
			int u = it->second.first;
			int v = it->second.second;
			int set_u = ds.findSet(u);
			int set_v = ds.findSet(v);
			
			if (set_u != set_v){
				cout << u << " - " << v << endl;
				mst_wt += it->first;
				cout << mst_wt << endl;
				ds.unionSet(set_u, set_v);
			}
		}
		return mst_wt;
	}
};

int main(){
	int n = 9;
	int m = 14;
	Graph g(n, m);
	/*
	Homework:
	-> Rebuild the graph
	-> Build the table (w,edge,selected)
	-> Applied the algorithm
	-> Check your answers with the output of the program
	-> Create a function in order to load the edges and weights from a file (PC2)
	-> Recreate the class in order to use classes (for intance: points) , use templates.
	-> 
	*/
	//g.addEdge(u,v,w)
	g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 2, 8);
	g.addEdge(1, 7, 11);
	g.addEdge(2, 3, 7);
	g.addEdge(2, 8, 2);
	g.addEdge(2, 5, 4);
	g.addEdge(3, 4, 9);
	g.addEdge(3, 5, 14);
	g.addEdge(4, 5, 10);
	g.addEdge(5, 6, 2);
	g.addEdge(6, 7, 1);
	g.addEdge(6, 8, 6);
	g.addEdge(7, 8, 7);

	cout << "Edges of MST "<<endl;
	int mstWeight = g.kruskalMST();

	cout << "\nWeight of MST is " << mstWeight;

	cin.get();
	return 0;
}