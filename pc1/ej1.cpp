#include <bits/stdc++.h>
using namespace std;

class Grafo
{
  private:
    int n;
    list<int> *myList;
    void DFSutil(int v, bool visited[])
    {
        visited[v] = true;
        cout << char(v+65)<< " ";
        list<int>::iterator it;
        
        for(it = myList[v].begin(); it != myList[v].end(); it++)
        {
            if(!visited[*it])
            {
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
    
    void addGrafo(int v, int w)
    {
        myList[v].push_back(w);
    }
    
    void BFS(int s)
    {
        bool *visited = new bool[n];
        for(int i = 0; i < n; i++)
        {
            visited[i]=false;
        }
        
        visited[s] = true;
        
        list<int> cola;
        cola.push_back(s);
        
        list<int>::iterator it;
        
         while(!cola.empty())
        {
            s = cola.front();
            cout << char(65+s) << " ";
            cola.pop_front();
            
            for(it = myList[s].begin(); it != myList[s].end(); it++)
            {
                if(!visited[*it])
                    {
                        visited[*it]=true;
                        cola.push_back(*it);
                    }
            }
            
            
        }
        
        
        
        
    }
    
    void DFS(int s)
    {
        bool *visited = new bool [n];
        for(int i = 0; i < n; i++)
        {
            visited[i]=false;
        }
        
        DFSutil(s, visited);
        
    }
  
};


int main(){


    Grafo g(8);
    g.addGrafo(1,5);
    g.addGrafo(2,1);
    g.addGrafo(2,3);
    g.addGrafo(2,6);
    g.addGrafo(3,7);
    g.addGrafo(3,4);
    g.addGrafo(4,8);
    g.addGrafo(4,7);
    g.addGrafo(5,2);
    g.addGrafo(6,7);
    g.addGrafo(6,5);
    g.addGrafo(6,3);
    
    cout<<"DFS: ";
    g.DFS(1);
    cout<<endl;
    cout<<"BFS: ";
    g.BFS(1);
    return 0;
}