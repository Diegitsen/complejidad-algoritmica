//PREGUNTAS
/*
1. El rank solo puede llenarse de 1s y 0s?
*/

#include<iostream>
#include<vector>
#include<queue>
#include <list>

using namespace std;

class UFDS
{
  private:
    int n;
    int max;
    vector<int> rank;
    vector<int> parent;
    vector<int> elements;

  public:
    UFDS(int n)
    {
        this->n=n;
        
        for(int i=0; i<n; i++)
        {
            rank.push_back(0);
            parent.push_back(i);
        }
    }
    
    int find(int i)
    {
        if( i != parent[i] )
            parent[i] = find(parent[i]);
            
        return parent[i];
    }
    
    bool sameSet(int x, int y)
    {
        return find(x)==find(y);
    }
    
    void unionSetUtil(int x, int y)
    {
        if(!sameSet(x,y))
        {
            if(rank[x]>rank[y])
                parent[y]=x;
            
            else
            {
                parent[x]=y;
                if(rank[x]==rank[y])
                    rank[y]=rank[y]+1;
                    
                
            }
        }
    }
    
    void unionSet(int x, int y)
    {
        unionSetUtil(find(x), find(y));
    }
    
    void showSet()
    {
        for (int i = 0; i < n; i++)
            cout<<"parent of: "<<i<<" is " << parent[i]<<endl;
    }

};

int main()
{
    UFDS u(6);
    u.showSet();
    cout<<endl;
    
    u.unionSet(1,2);
    u.unionSet(2,4);
    u.unionSet(0,2);
    u.unionSet(3,5);
    
    cout<<endl;
    u.showSet();

}