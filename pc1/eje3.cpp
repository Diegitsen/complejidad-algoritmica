#include <bits/stdc++.h>
using namespace std;

//Modificación: Empieza en (0, 0) en lugar de (1, 1)
//0->libre
//1->ocupado

bool fin=false;
int n=5;
int mapa[5][5]={{0,1,0,0,0}, {0,0,0,1,1}, {0,1,0,0,0}, {0,1,0,1,0}, {0,0,0,1,0}};

void imprimir(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mapa[i][j]==0) cout<<"|   ";
            if(mapa[i][j]==1) cout<<"| x ";
        }
        cout << "|";
        cout<<endl;
    }
}

void _encontrar_camino(int ii, int jj, vector<pair<int,int>> v)
{
    if(v[v.size()-1].first==n-1&&v[v.size()-1].second==n-1) fin=true;
    if(fin==false)
    {
        cout<<"("<<jj<<", "<<ii<<") -> ";
        for(int i=ii; i<n;i++)
        {
            for(int j=jj; j<n;j++)
            {
                vector<pair<int,int>> aux=v;
                bool b=false;
                if(mapa[i][j+1]==0&&b==false&&j+1<n)
                {
                    aux.push_back(make_pair(i,j+1));
                    _encontrar_camino(i,j+1,aux);
                    b=true;
                }
                if(mapa[i+1][j]==0&&b==false&&i+1<n)
                {
                    aux.push_back(make_pair(i+1,j));
                    _encontrar_camino(i+1,j,aux);
                    b=true;
                }
            }
        }
    }
}

void encontrar_camino(){
    vector<pair<int,int>> v;
    v.push_back(make_pair(0,0));
    _encontrar_camino(0,0,v);
    cout<<"("<<n-1<<", "<<n-1<<")";;
}

int main(){
    imprimir();
    cout<<endl<<"Se lee (x, y)"<<endl;
    encontrar_camino();
    return 0;
    
}