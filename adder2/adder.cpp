#include <bits/stdc++.h>
using namespace std;


//divide y venceras
//maxima suma de nuemros conecutivos [4, 7 , 1 , -7]  se agarra el 4, 7, 1

class Adder
{
  public:
    int max(int a, int b)
    {
        if(a>b)
            return a;
        else
            return b;
    }
    
     int max(int a, int b, int c)
    {
        if(c>max(a,b))
            return c;
        else
            return max(a,b);
    }
    
    int max_cro_sum(vector<int> a, int l, int r, int m)
    {
        int sum = 0;
        int left_sum = 0;
        int right_sum = 0;
        
        for(int i = m; i >= l; i--)
        {
            sum += a[i];
            
            if(sum>left_sum)
                left_sum = sum;
        }
        
        sum = 0;
        
        for(int i = m + 1; i <= r; i++)
        {
            sum += a[i];
            
            if(sum>=right_sum)
                right_sum = sum;
        }
        
        return left_sum + right_sum;
    }
    
    int maxSum(vector<int> a, int l, int r)
    {
        if(r-l==1)
            return a[l];
            
        int m = (r+l)/2;
        
        int maxLeft = maxSum(a, l, m);
        int maxRight = maxSum(a, m, r);
        
        return max(maxLeft, maxRight, max_cro_sum(a,l,r,m));
    }
};

int main()
{
    vector<int> a = {1,-8,3,4,-5};
    
    Adder *add = new Adder();
    
    cout << add->maxSum(a,0,a.size());
    
    return 0;
}