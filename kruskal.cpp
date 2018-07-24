#pragma once;
#include <iostream>
#include <conio.h>
#include <vector>
#include <algorithm>

using namespace std;
using namespace System;

typedef pair<int, int> iPair;

class unionFind
{
private:
	int n;
	vector<int> rank;
	vector<int> parent;

public:
	unionFind(int n)
	{
		this->n = n;

		for (int i = 0; i < n; i++)
		{
			parent.push_back(i);
			rank.push_back(0);
		}
	}

	int find(int i)
	{
		if (parent[i] != i)
			parent[i] = find(parent[i]);

		return parent[i];
	}

	void unionSetUtil(int x, int y)
	{
		int xroot = find(x);
		int yroot = find(y);

		if (rank[xroot] > rank[yroot])
			parent[yroot] = xroot;

		else if (rank[yroot] > rank[xroot])
			parent[xroot] = yroot;

		else
		{
			parent[xroot] = yroot;
			rank[yroot]++;
		}
	}

	void unionSet(int x, int y)
	{
		unionSetUtil(find(x), find(y));
	}

	void showSet()
	{
		for (int i = 0; i < n; i++)
		{
			cout << "El padre de " << i << " es: " << parent[i] << endl;
		}
	}
};

class Kruskalaso
{
private:
	int nn, mm;
	vector<pair<int, iPair>> edges;

public:
	Kruskalaso(int nn, int mm)
	{
		this->nn = nn;
		this->mm = mm;
	}

	void addEdges(int u, int v, int w)
	{
		edges.push_back({ w,{ u, v } });
	}


	int kruskal()
	{
		int mst = 0;

		sort(edges.begin(), edges.end());

		vector<pair<int, iPair>>::iterator it;

		unionFind uf(nn);

		for (it = edges.begin(); it != edges.end(); it++)
		{
			int u = it->second.first;
			int v = it->second.second;
			int set_u = uf.find(u); //ds.findSet(u);
			int set_v = uf.find(v);

			//si no causa un ciclo...
			if (set_u != set_v)
			{
				cout << u << " - " << v << endl;
				mst += it->first;
				uf.unionSetUtil(set_u, set_v);
			}
		}

		return mst;
	}

};


int main()
{
	int n = 9;
	int m = 9;

	Kruskalaso k(n, m);

	k.addEdges(0, 1, 4);
	k.addEdges(0, 7, 8);
	k.addEdges(1, 2, 8);
	k.addEdges(1, 7, 11);
	k.addEdges(2, 3, 7);
	k.addEdges(2, 8, 2);
	k.addEdges(2, 5, 4);
	k.addEdges(3, 4, 9);
	k.addEdges(3, 5, 14);
	k.addEdges(4, 5, 10);
	k.addEdges(5, 6, 2);
	k.addEdges(6, 7, 1);
	k.addEdges(6, 8, 6);
	k.addEdges(7, 8, 7);

	cout << "Edges of MST " << endl;
	int mstWeight = k.kruskal();

	cout << "\nWeight of MST is " << mstWeight;

	_getch();

	return 0;
}





