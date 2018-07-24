#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    int n, m; //# of vertex, # of edges
    cout<<"n m?"<<endl;
    cin>>n>>m;
    queue<int> q ;
    //----------
    int incoming[n];
    for(int i=0; i<n; i++)
        incoming[i]=0;
    //----------    
    vector<vector<int>> G(n);
    //----------    
    int u, v;
    for(int i=0; i<m; i++){
        cout<<(i+1)<<": (u -> v)?: ";
        cin>>u>>v;
        incoming[v]++;
        G[u].push_back(v);
    }

//look this!
    for(int i=0; i<n;i++){
        if(incoming[i] ==0)
            q.push(i);
    }
    
    //-----------------------
    //Topological Order
    //-----------------------    
    while(!q.empty()){
        int u = q.front(); q.pop();
        cout<<u<<" ";
        for(int i=0; i<G[u].size(); i++){
            int v=G[u][i];
            incoming[v]--;
            if(incoming[v]== 0 ){
                q.push(v);
            }
        }

    }
    //-----------------------    
    return(0);
}

/*
6 5 --> (n,m)
0 3 --> (u,v)
1 3
1 4
2 4
2 5
topological order

0 1 2 3 4 5 
*/