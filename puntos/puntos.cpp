#include <bits/stdc++.h>
using namespace std;

int min_cro_dis(vector<int> a, int l, int m, int r){
}

int min_dist(vector<int> a, int l, int r){
    sort(a.begin(),a.end());
    if(r-l==1) return a[l];
    int m=(l+r)/2;
    int min_r=min_dist(a,l,m);
    int min_l=min_dist(a,m,r);
    return 
}

int main(){
    int vector<int> a;
    a={5,0,-3,11,9};
    int min_dist(a,0,a.size(););
    return 0;
}