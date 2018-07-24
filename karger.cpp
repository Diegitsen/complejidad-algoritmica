// Karger's algorithm to find Minimum Cut in an
// undirected, unweighted and connected graph.
#include <iostream>
#include <conio.h>
#include <time.h>
#include <vector>
using namespace std;
using namespace System;

class UnionFind
{
private:
	int n;
	int min = 9999;
	vector<int> rank;
	vector<int> parent;
	vector<int> src;
	vector<int> dest;
	vector<int> aux1;
	vector<int> aux2;
	vector<int> auxparent;
	vector<int> auxrank;

public:
	UnionFind(int n) //this is goin to be v.size()
	{
		this->n = n;

		for (int i = 0; i < n; i++)
		{
			parent.push_back(i);
			rank.push_back(0);
		}
		auxparent = parent;
		auxrank = auxrank;
	}

	void setSrc(int x)
	{
		src.push_back(x);
	}


	void setDest(int x)
	{
		dest.push_back(x);
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

	void karger()
	{


		for (int j = 0; j < 10; j++)
		{
			int vertices = n;
			aux1 = src;
			aux2 = dest;
			parent = auxparent;
			//rank = auxrank;

			while (vertices > 2)
			{
				int i = rand() % aux1.size();

				int s1 = find(aux1[i]);
				int s2 = find(aux2[i]);

				if (s1 == s2)
					continue;

				else
				{
					cout << aux1[i] << " " << aux2[i] << endl;
					vertices--;
					unionSetUtil(s1, s2);
				}


			}

			int cutedges = 0;

			for (int i = 0; i < aux1.size(); i++)
			{
				int s1 = find(aux1[i]);
				int s2 = find(aux2[i]);

				if (s1 != s2)
					cutedges++;
			}

			cout << "El n es: " << cutedges << endl << endl;

			if (cutedges < min)
				min = cutedges;
		}

		cout << "El min es: " << min << endl;
	}
};


int main()
{
	int V = 4;
	int E = 5;

	UnionFind uf(4);

	uf.setSrc(0);
	uf.setDest(1);

	uf.setSrc(0);
	uf.setDest(2);

	uf.setSrc(0);
	uf.setDest(3);

	uf.setSrc(1);
	uf.setDest(3);

	uf.setSrc(2);
	uf.setDest(3);



	srand(time(NULL));

	uf.karger();


	_getch();

	return 0;
}