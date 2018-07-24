#include <bits/stdc++.h>
using namespace std;

class Grafo
{
  private:
    int v;
    vector<vector<int>> myVector;
  
  public:
    int getV()
    {
        return v;
    }
  
    Grafo(int v) : myVector(v) { this->v = v;  }
    
    void addEdge(int v, int w)
    {
        myVector[v].push_back(w);
    }
    
    void BFS(int s)
    {
        vector<bool> visited;
        
        for(int i = 0; i < v; i++)
            visited[i]=false;
            
        vector<int> queuebamba;
        
        visited[s] = true;
        
        queuebamba.push_back(s);
        
        vector<int>::iterator it;
        
        while(!queuebamba.empty())
        {
            s = queuebamba.front();
            cout << s << " ";
            queuebamba.pop_back();
            
            for(it = myVector[s].begin(); it != myVector[s].end(); it++)
            {
                if(!visited[*it])
                {
                    visited[*it]=true;
                    queuebamba.push_back(*it);
                }
            }
        }
    }
    
};

int main()
{
    
  freopen("bfsin", "rt", stdin);
 //freopen("bfsout", "wt", stdout);
 
 int casos;
 cin >> casos;
 cout << endl;
 
 while(casos > 0)
 {
     int n, m;
     cin >> n >> m;
     cout << endl;
     
     Grafo g(n);
     
     while(m >0)
     {
         int u,v;
         cin >> u >> v;
         cout << endl;
         g.addEdge(u, v);
         
         
         m--;
     }
     
     g.BFS(5);
     
     casos--;
}
  
  
  

  
    return 0;
}

/*  Grafo g(10);
    g.addEdge(1,2);
    g.addEdge(2,1);
    g.addEdge(3,1);
    g.addEdge(3,4);
    g.addEdge(5,4);
    g.addEdge(3,5);
    g.addEdge(4,6);
    g.addEdge(5,2);
    g.addEdge(2,1);
    g.addEdge(7,1);
    g.addEdge(1,2);
    g.addEdge(9,10);
    g.addEdge(8,9);
    cout << "oye sii" << endl;
    cout << g.getV() << endl;
    
    g.BFS(1);*/