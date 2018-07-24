#include <bits/stdc++.h>
using namespace std;

class Grafo
{
  private:
    int n;
    list<int> *myList;
    void llenarLista(int v, bool visited[], list<int> &list);
    void DFSutil(int v, bool visited[]);
  
  public:
    Grafo(int n);
    void addEdge(int u, int v);
    Grafo transponer();
    void imprimir();
};

Grafo::Grafo(int n)
{
    this->n = n;
    myList = new list<int>[n];
}

void Grafo::addEdge(int u, int v)
{
    myList[u].push_back(v);
}

Grafo Grafo::transponer()
{
    Grafo g(n);
    
    for(int v = 0; v < n; v++)
    {
        list<int>::iterator it;
        
        for(it=myList[v].begin(); it !=myList[v].end(); it++)
        {
            g.myList[*it].push_back(v);
        }
    }
    
    return g;
}

void Grafo::DFSutil(int v, bool visited[])
{
    visited[u] = true;
    cout<<u<< " ";
    list<int>::iterator it;
    for (it = adj[u].begin(); it != adj[u].end(); ++it)
        if (!visited[*it])
            DFSUtil(*it, visited);
}


void Grafo::llenarLista(int u, bool visited[], list<int> &list)
{
    visited[u]=true;
    list<int>::iterator it;
}



