#include <bits/stdc++.h>
using namespace std;



/*void guardarLeerArchivo(){
    int n=104;

    freopen("in.txt","r",stdin);
    

    freopen("out.txt","w",stdout);
     
   
    return 0;
}*/

class Amigos{
    
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
    
        Amigos(int n){
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
            cout << endl << imprimir(visited);
        }
        
        int imprimir(bool visited[])
        {
            int cont = 0;
            for(int i = 0; i < n; i++)
            {
                if(visited[i]==true)
                    cont++;
            }
            
            return cont;
        }
};

int main(){
    
    int casos;
    int n;
    int nn, mm;
    cout << "número de pares de personas: " ;
    cin>> n;
    Amigos g(n);
    
    for(int i = 0; i < n; i++)
    {
        cout << "Escribe n y m:";
        cin >> nn >> mm;
        g.add_edge(nn , mm);
    }
    
    
    /*g.add_edge(1,2);
    g.add_edge(2,1);
    g.add_edge(3,1);
    g.add_edge(1,3);
    g.add_edge(3,4);
    g.add_edge(3,5);
    g.add_edge(4,6); 
    g.add_edge(6,7); 
    g.add_edge(5,2); 
    g.add_edge(5,4);
    g.add_edge(7,1);
    g.add_edge(8,9);
    g.add_edge(9,10);*/
    
    cout<<"Los amigos en total son: "<<endl;
    g.DFS(1);
    

    
    return 0;
}

/*
Amigos g(10);
    g.add_edge(1,2);
    g.add_edge(2,1);
    g.add_edge(3,1);
    g.add_edge(1,3);
    g.add_edge(3,4);
    g.add_edge(3,5);
    g.add_edge(4,6); 
    g.add_edge(6,7); 
    g.add_edge(5,2); 
    g.add_edge(5,4);
    g.add_edge(7,1);
    g.add_edge(8,9);
    g.add_edge(9,10);
    
    */