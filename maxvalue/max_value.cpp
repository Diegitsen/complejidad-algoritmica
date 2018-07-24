#include <bits/stdc++.h>
using namespace std;

class Finder{
    public:
        int maxValue(vector<int> a, int l, int r){
            cout<<l<<" ~ "<<r<<endl;
            if(r-l==1){
                cout<<"Condición"<<endl<<endl;
                return a[l];
            }
            cout<<endl;
            int m=(l+r)/2;
            int u=maxValue(a,l,m);
            int v=maxValue(a,m,r);
            return (u>v) ? u:v;
        }
};

int main(){
    vector <int> a;
    a={34,3,47,4,32,0};
    for(int i=0;i<a.size();i++)
        cout<<a[i]<<" ";
        cout<<endl<<endl;
    Finder *f=new Finder();
    cout<<"Max Value: "<<f->maxValue(a,0,a.size());
    return 0;
}