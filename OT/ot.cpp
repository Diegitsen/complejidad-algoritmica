#include<iostream>
#include<vector>
#include<queue>
#include <list>

using namespace std;

class Grafo
{
  private:
    int n;
    list<int> *myList;
    int *incoming = new int[n];

  public:
    Grafo(int n)
    {
        this->n = n;
        myList = new list<int>[n];
        
        for(int i=0; i<n; i++)
            incoming[i]=0;
    }
    
    void addEdge(int u, int v)
    {
        myList[u].push_back(v);
        incoming[v]++;
    }
    
    void OT()
    {
        list<int> q ;
        
        for(int i=0; i<n;i++){
          if(incoming[i] ==0)
            q.push_back(i);
        }
            
        while(!q.empty())
        {
            int u = q.front();
            q.pop_front();
            cout << u << " ";
            list<int>::iterator it;
            
            for(it = myList[u].begin(); it != myList[u].end(); it++)
            {
                incoming[*it]--;
                
                if(incoming[*it]==0)
                    q.push_back(*it);
            }
        }

    }
};

int main()
{
    Grafo g(6);
    
    g.addEdge(0,3);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(2,4);
    g.addEdge(2,5);
    
    g.OT();
}