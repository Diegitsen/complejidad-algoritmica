#include <bits/stdc++.h>
using namespace std;

class Grafo
{
  private:
    int n;
    list<int> *listAD;
    
    void DFSutil(int v, bool visited[])
    {
        visited[v] = true;
        cout << v << " ";
        list<int>::iterator it;
        
        for(it = listAD[v].begin(); it != listAD[v].end(); it++)
            if(visited[*it]==false)
                DFSutil(*it, visited);
        
    }
    
    
  public:
  
    Grafo(int n)
    {
        this->n=n;
        listAD = new list<int>[n];
    }
    
    void add_egde(int v, int w)
    {
        listAD[v].push_back(w);
    }
    
    void DFS(int s)
    {
        bool *visited = new bool[n];
        
        for(int i = 0; i<n; i++)
            visited[i] = false;
            
        DFSutil(s, visited);
        
    }
  
};

int main()
{
    Grafo g(10);
    
    g.add_egde(1,2);
    g.add_egde(2,1);
    g.add_egde(3,1);
    g.add_egde(3,4);
    g.add_egde(5,4);
    g.add_egde(3,5);
    g.add_egde(4,6);
    g.add_egde(5,2);
    g.add_egde(2,1);
    g.add_egde(7,1);
    g.add_egde(1,2);
    g.add_egde(9,10);
    g.add_egde(8,9);
    
    g.DFS(1);
    return 0;
    
}
