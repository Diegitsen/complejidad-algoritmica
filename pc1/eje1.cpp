#include <bits/stdc++.h>
using namespace std;

class Grafo{
    private:
        int n=10;
        list<int> *listAd;
        
        void DFS_util(int a, bool visited[]){
            visited[a]=true;
            cout<<char(65+a)<<" ";
            list<int>::iterator it;
            for(it=listAd[a].begin(); it!=listAd[a].end();it++){
                if(visited[*it]==false)
                DFS_util(*it,visited);
            }
            
        }
    public:
        Grafo(int n){
            this->n=n;
            listAd=new list<int>[n];
        }
        
        void add_edge(int a, int b){
            listAd[a].push_back(b);
        }
        
        void DFS(int a){
            bool *visited=new bool[n];
            for(int i=0;i<n;i++)
                visited[i]=false;
            DFS_util(a,visited);
        }
        
        void BFS(int a){
            bool *visited=new bool[n];
            for(int i=0;i<n;i++)
                visited[i]=false;
            
            visited[a]=true;
            list<int>queue;
            queue.push_back(a);
            
            list<int>::iterator it;
            
            while(queue.empty()==false){
                a=queue.front();
                cout<<char(65+a)<<" ";
                queue.pop_front();
                
                for(it=listAd[a].begin();it!=listAd[a].end();it++){
                    if(visited[*it]==false){
                        visited[*it]=true;
                        queue.push_back(*it);
                    }
                }
            }
            
        }
    
};

int main(){


    Grafo g(11);
    g.add_edge(0,1);
    g.add_edge(0,2);
    g.add_edge(0,5);
    g.add_edge(1,0);
    g.add_edge(1,3);
    g.add_edge(1,9);
    g.add_edge(2,0);
    g.add_edge(2,5);
    g.add_edge(3,1);
    g.add_edge(3,4);
    g.add_edge(3,6);
    g.add_edge(3,7);
    g.add_edge(4,3);
    g.add_edge(4,6);
    g.add_edge(5,0);
    g.add_edge(5,2);
    g.add_edge(5,7);
    g.add_edge(5,10);
    g.add_edge(6,3);
    g.add_edge(6,4);
    g.add_edge(6,8);
    g.add_edge(6,9);
    g.add_edge(7,3);
    g.add_edge(7,5);
    g.add_edge(7,8);
    g.add_edge(8,6);
    g.add_edge(8,7);
    g.add_edge(8,9);
    g.add_edge(9,1);
    g.add_edge(9,6);
    g.add_edge(9,8);
    g.add_edge(9,10);
    g.add_edge(10,5);
    g.add_edge(10,9);
    cout<<"DFS: ";
    g.DFS(7);
    cout<<endl;
    cout<<"BFS: ";
    g.BFS(7);
    return 0;
}