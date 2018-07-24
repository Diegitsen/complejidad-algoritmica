#include <bits/stdc++.h>
using namespace std;


//divide y venceras
//maxima suma de nuemros conecutivos [4, 7 , 1 , -7]  se agarra el 4, 7, 1
class Adder{
    public:
    
    //retorn el mayor
    int max(int a, int b){ return (a>b)? a:b; }
    int max(int a, int b, int c){ return max(max(a,b),c); }
    
    
    
    int max_cro_sum(vector<int> a, int l, int m, int r){
     int sum=0;
     int left_sum=std::numeric_limits<int>::min();
     int right_sum=std::numeric_limits<int>::min();
     for(int i=m;i>=l;i--){
         sum+=a[i];
         if(sum>left_sum)
         left_sum=sum;
     }
     sum=0;
      for(int i=m+1;i<=r;i++){
         sum+=a[i];
         if(sum>right_sum)
         right_sum=sum;
     }
     return left_sum+right_sum;
    }
    
    int max_sum(vector<int> a, int l, int r){
        
        if(r-l==1) return a[l];
        int m=(r+l)/2;
        int maxleft=max_sum(a,l,m);
        int maxright=max_sum(a,m,r);
        return max(maxleft,maxright,max_cro_sum(a,l,m,r));
        
    }
    
};

int main(){
    vector<int> a;
    a={-4, 7 };
    Adder *d=new Adder();
    cout<<d->max_sum(a,0,a.size());
    return 0;
}