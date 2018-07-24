#include <bits/stdc++.h>
using namespace std;

int n=10;

int distancia(int **a, vector<int>v){
    int sum=0;
    for(int i=0;i<v.size()-1;i++){
        sum+=a[v[i]][v[i+1]];
    }
    return sum;
}

vector<int> resultados;

void _min_dis(int **a, int n, vector<int> aux){
    for(int i=0;i<aux.size();i++)
        cout<<aux[i]<<"  ";
    cout<<endl;
    int sum=0;
    int maxsum=0;
    if(aux.size()<n){
        for(int i=0;i<n;i++){
            if(find(aux.begin(),aux.end(),i)==aux.end()){
                vector<int> aux2=aux;
            aux2.push_back(i);
            _min_dis(a,n,aux2);
            }
        }
    }
    else{
    cout<<distancia(a,aux)<<endl;
    resultados.push_back(distancia(a,aux));
    }
}

void min_dis(int **a,int n){
    vector<int>v;
    _min_dis(a,n,v);
   sort(resultados.begin(),resultados.end());
   cout<<endl<<"Resultado mínima distancia: "<<resultados[0];
}

int main(){
    
    n=4;
    int **a=new int*[n];
    for(int i=0;i<n;i++)
        a[i]=new int[n];
        
    a[0][1]=4;
    a[0][2]=2;
    a[0][3]=7;
    a[1][0]=4;
    a[1][2]=10;
    a[1][3]=22;
    a[2][0]=2;
    a[2][1]=10;
    a[2][3]=13;
    a[3][0]=7;
    a[3][1]=22;
    a[3][2]=13;
    
    min_dis(a,n);
    
    return 0;
}