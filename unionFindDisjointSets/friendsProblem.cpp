//POR QUE EL i-- Y j--

#include <bits/stdc++.h>
#include <vector>
using namespace std;

class UFDS
{
  private:
    int n;
    int max;
    vector<int> rank;
    vector<int> parent;
    vector<int> elements;
    list<int> *matriz;
    
  
  public:
    UFDS(int n)
    {
        this->n=n;
        matriz = new list<int>[n];
        
        for(int i=0; i < n; i++)
        {
            rank.push_back(0);
            parent.push_back(i);
            elements.push_back(1);
        }
    }
    
    int getMax()
    {
        return max;
    }
    
    void setMax(int ma)
    {
        max = ma;
    }
    
    int find(int i)
    {
        if(i != parent[i])
            parent[i]=find(parent[i]);
            
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
              {
                  parent[y]=x;
                  elements[x] += elements[y];
                  max = (max < elements[x])?elements[x]:max;
              }
                
            else
            {
                parent[x]=y;
                elements[y] += elements[x];
                max = (max < elements[y])?elements[y]:max;
                
                if(rank[x]==rank[y])
                    rank[y]++;
            }
            
        }
    }
    
    void unionSet(int x, int y)
    {
        unionSetUtil(find(x), find(y));
    }
    
    void showSet()
    {
        for(int i = 0; i < n; i++)
            cout << "The parent of: " << i << " is: " << parent[i] << endl;
    }
    
};

int main()
{
    int n, m;
    int i, j;
    int cases;
    
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    cin >> cases;
    
    while(cases>0)
    {
        cin >> n >> m;
        UFDS u(n);
        u.setMax(1);
        
        while(m>0)
        {
            cin >> i >> j;
            u.unionSet(i,j);
            m--;
        }
        
        cout << u.getMax() << endl;
        cases --;
    }
}