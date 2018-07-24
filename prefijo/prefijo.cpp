#include <bits/stdc++.h>
using namespace std;

class Prefijo{
    public:
        string pref_comun(string s1, string s2){
            string result;
            int n1=s1.size();
            int n2=s2.size();
            for(int i=0, j=0;i<n1,j<n2;i++,j++){
                if(s1[i]!=s2[j]) break;
                result.push_back(s1[i]);
            }
            return result;
        }
        
        string find_pref_comun(vector<string> a, int low, int high){
            if(high-low==1) return a[low];
                int mid=(high+low)/2;
                string s1=find_pref_comun(a,low,mid);
                string s2=find_pref_comun(a,mid,high);
                return (pref_comun(s1,s2));
        }
};

int main(){
    vector<string> a;
    a={"palito", "paloma", "palitroque", "paleta","palmera"};
    Prefijo *p=new Prefijo();
    for (int i=0;i<a.size();i++)
        cout<<a[i]<<endl;
    cout<<endl<<"Prefijo común: ";
    cout<<p->find_pref_comun(a,0,a.size());
    
    return 0;
}