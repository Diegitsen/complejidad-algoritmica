#include <bits/stdc++.h>
using namespace std;



void amigos()
{
     vector<pair<int,int>> v;
     v.push_back(make_pair(1,2));
     v.push_back(make_pair(2,3));
     vector <int> amiguitos;
     amiguitos.push_back(1);
     amiguitos.push_back(2);
     
     for(int i = 0; i < v.size(); i++)
     {
         cout << v[i].first << " " << v[i].second << endl;
     }
     
     cout << "Grupo de amigos" << endl ;
     
     
    /*for(int i = 0; i < amiguitos.size(); i++)
    {
        for(int j = 1; j < v.size(); j++)
        {
            bool sonAmigos=false;
            if(v[j].first == amiguitos[i] && sonAmigos == false)
            {
                amiguitos.push_back(v[j].second);
                sonAmigos = true;
            }
                
            if(v[j].second == amiguitos[i] && sonAmigos == false)
            {
                amiguitos.push_back(v[j].first);
                sonAmigos = true;
            }
        }
    }
    */
    int j = 1;
    int cAmigos = 0;
    
    while( j < v.size())
    {
         bool sonAmigos=false;
         if(v[j].first == amiguitos[cAmigos] && sonAmigos == false)
         {
                amiguitos.push_back(v[j].second);
                sonAmigos = true;
                cAmigos++;
         }
         
         if(v[j].second == amiguitos[cAmigos] && sonAmigos == false)
         {
                amiguitos.push_back(v[j].first);
                sonAmigos = true;
                cAmigos++;
         }
         j++;
    }
    
     
     
     cout << "{";
     for(int i = 0; i < amiguitos.size(); i++)
     {
         cout << amiguitos[i] << " " ;
     }
     cout << "}" << endl << "En total son " << amiguitos.size() << " amigos";
}


int main()
{
    amigos();
    return 0;
}
/*
class Amigos
{
  private:
    int n;
    list<int> *myList;
  
  public:
    Amigos(int n)
    {
        this->n=n;
        myList = new list<int>[n];
    }
    
    void addFriend(int u, int v)
    {
        myList[u].push_back(v);
    }
    
    void grupoDeAmigos()
    {
        for(int i = 0; i < n; i++)
        {
            cout << myList[i].begin() << " " << myList[i].end() << endl;
        }
    }
    
};

int main()
{
    Amigos a(2);
    
    a.addFriend(0,1);
    a.addFriend(0,2);
    a.addFriend(1,2);
    a.addFriend(1,3);
    
    grupoDeAmigos();
    
    return 0;
}*/