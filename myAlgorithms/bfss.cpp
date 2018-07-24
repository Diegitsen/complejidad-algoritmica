#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Grafo
{
    private:
        int n;
        list<int> *myList;
    
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
        
        void BFS(int s)
        {
            bool *visited = new bool[n];
            
            for(int i = 0; i < n; i++)
                visited[i]=false;
                
            list<int>queue;
            visited[s]=true;
            queue.push_back(s);
            
            list<int>::iterator it;
            
            while(!queue.empty())
            {
                s = queue.front();
                cout << s << " ";
                queue.pop_front();
                
                for(it = myList[s].begin(); it != myList[s].end(); it++)
                {
                    if(!visited[*it])
                    {
                        visited[*it]=true;
                        queue.push_back(*it);
                    }
                }
            }
        }
    
};

int main()
{
 
    
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
    
    g.BFS(5);
    return 0;
}