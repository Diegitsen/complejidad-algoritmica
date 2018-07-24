#include <bits/stdc++.h>
#include <list>
using namespace std;

class Graph
{
    private:
        int n;
        list<int> *listAd;

    public:
        Graph(int n=10); //constructor
        void addEdge(int v, int w); //function f
        void BFS(int s); //print BFS trasversal
};

Graph::Graph(int n)
{
    this->n = n;
    listAd = new list<int>[n];
}

void Graph::addEdge(int u, int v)
{
    listAd[u].push_back(v);
}

void Graph::BFS(int s)
{
    bool *visited = new bool[n];
    
    
    for(int i = 0; i < n; i++)
        visited[i]=false;
        
        
    list<int> queue;
    visited[s] = true; //try with a nunmber out of the range
    queue.push_back(s);
    
    list<int>::iterator it;

    while(!queue.empty())
    {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
        
        for(it = listAd[s].begin(); it != listAd[s].end(); ++it) //pregunta 2 //it = 3-> begin --- it=3->end
        {
            if(!visited[*it])
                {
                    visited[*it]=true;
                    queue.push_back(*it);
                }
                
        }
    }
}

int main()
{
    Graph g(10);
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
    
    g.BFS(1);
}

// 5:3