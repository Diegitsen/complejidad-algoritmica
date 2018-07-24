#include <iostream>
#include <list>
using namespace std;

class Grafo
{
  private:
    int n;
    list<int> *myList;
    
    void DFSutil(int s, bool visited[])
    {
        visited[s]=true;
        cout << s << " ";
        list<int>::iterator it;
        
        for(it = myList[s].begin(); it != myList[s].end(); it++)
        {
            if(!visited[*it])
            {
                visited[*it]=true;
                DFSutil(*it, visited);
            }
        }
    }
  
  public:
    Grafo(int n)
    {
        this->n = n;
        myList = new list<int>[n];
    }
    
    void addEdge(int u, int v)
    {
        myList[u].push_back(v);
    }
    
    void DFS(int s)
    {
        bool *visited = new bool [n];
        
        for(int i = 0; i < n; i++)
        {
            visited[i]=false;
        }
        
        DFSutil(s,visited);
        
        
    }
};

int main(){
    Grafo g(6);
    
    g.addEdge(0,1);
    g.addEdge(1,0);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,1);
    g.addEdge(2,3);
    g.addEdge(2,4);
    g.addEdge(3,1);
    g.addEdge(3,2);
    g.addEdge(3,5);
    g.addEdge(4,2);
    g.addEdge(5,3);
    
    g.DFS(5);
    
    return 0;
}