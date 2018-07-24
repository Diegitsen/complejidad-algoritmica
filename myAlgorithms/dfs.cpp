#include <bits/stdc++.h>
using namespace std;

class Grafo
{
    private:
        int v;
        vector<vector<int>> myVector;

        void DFSutil(int v, vector<bool> visited)
        {
            visited[v]= true;
            cout << v << " ";
            vector<int>::iterator it;
            
            for(it = myVector[v].begin(); it != myVector[v].end(); it++)
            {
                if(visited[*it]==false)
                    DFSutil(*it, visited);
            }
        }
    
    public:
       /* Grafo(int v)
        {
            this->v = v;
            myVector(v);
        }*/
        
        Grafo(int v) : myVector(v) {this->v = v; }
        
        
        void addEdge(int v, int w)
        {
            myVector[v].push_back(w);
        }
        
        void DFS(int s)
        {
            vector<bool> visited;
            
            for(int i = 0; i < v; i++)
                visited[i]=false;
                
            DFSutil(s, visited);    
        }
    
};

int main()
{
    Grafo g(10);
    g.addEdge(1,2);
    g.addEdge(2,1);
    g.addEdge(3,1);
    g.addEdge(1,3);
    g.addEdge(3,4);
    g.addEdge(3,5);
    g.addEdge(4,6); 
    g.addEdge(6,7); 
    g.addEdge(5,2); 
    g.addEdge(5,4);
    g.addEdge(7,1);
    g.addEdge(8,9);
    g.addEdge(9,10);

    cout<<"DFS iniciado en 0: "<<endl;
    g.DFS(1);
    return 0;
}