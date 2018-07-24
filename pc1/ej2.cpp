#include <bits/stdc++.h>
using namespace std;

class Ackerman
{
   public:
   
    int algoritmo(int m, int n)
    {
        if(m==0)
            return n+1;
            
        if(m>0 && n ==0)
        {
            return algoritmo(m-1,1);
        }
        
        if(m>0 && n>0)
        {
            return algoritmo(m-1, algoritmo(m, n-1));
        }
    }
};

int main()
{
    Ackerman *a = new Ackerman();
    
    cout << a->algoritmo(3,2);
}