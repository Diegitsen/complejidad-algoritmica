#include <bits/stdc++.h>
using namespace std;

class Grafo{
    
    private:
    
        int n;
        list<int> *listAd;
        
        void  DFSutil(int v, bool visited[]){
            visited[v]=true;
            cout<<v<<" ";
            list<int>::iterator it;
            for(it=listAd[v].begin();it!=listAd[v].end();it++)
                if(visited[*it]==false)
                    DFSutil(*it,visited);
        }
        
    public:
    
        Grafo(int n){
            this->n=n;
            listAd=new list<int>[n];
        }
        
        void add_edge(int v, int w){
            listAd[v].push_back(w);
        }
        
        void DFS(int s){
            bool *visited=new bool[n];
            for(int i=0;i<n;i++)
                visited[i]=false;
            DFSutil(s,visited);
        }
};

int main(){
    
 
    
    
    Grafo g(6);
    
    g.add_edge(0,1);
    g.add_edge(1,0);
    g.add_edge(1,2);
    g.add_edge(1,3);
    g.add_edge(2,1);
    g.add_edge(2,3);
    g.add_edge(2,4);
    g.add_edge(3,1);
    g.add_edge(3,2);
    g.add_edge(3,5);
    g.add_edge(4,2);
    g.add_edge(5,3);
    
    g.DFS(5);
    
    return 0;
}