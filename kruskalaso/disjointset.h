#ifndef _DS_H_
#define _DS_H_
class DisjointSets{
public:
	int *parent;
	int *rank;
	int n;

	DisjointSets(int n){
		this->n = n;
		parent = new int[n + 1];
		rank = new int[n + 1];
		for (int i = 0; i <= n; i++){
			rank[i] = 0;
			parent[i] = i;
		}
	}

	int findSet(int u){
		if (u != parent[u])
			parent[u] = findSet(parent[u]);
		return parent[u];
	}

	void unionSet(int x, int y){
		x = findSet(x);
		y = findSet(y);

		if (rank[x] > rank[y])
			parent[y] = x;
		else // If rank[x] <= rank[y]
			parent[x] = y;
		//
		if (rank[x] == rank[y])
			rank[y]++;
	}
};


#endif
