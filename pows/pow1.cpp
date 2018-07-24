#include <bits/stdc++.h>
using namespace std;

int value = 1;

int myPow(int x, int n)
{
    int val = 1;
    
    for(int i = 0; i < n; i++)
    {
        val = val*x;
    }
    
    return val;
}

int recursivityPow(int a, int n)
{
    if(n>0)
        value = value*a;
    
    else
        return value;
    
    return recursivityPow(a, n-1);
    
}

int powVersionAlbert(int x, int n)
{
    if(n==0)
        return 1;
        
    else 
        return x*powVersionAlbert(x, n-1);
}

int main()
{
    cout << powVersionAlbert(2,3);
}