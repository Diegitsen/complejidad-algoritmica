#include <bits/stdc++.h>
using namespace std;

class Cadena
{
    private:
    
    
    public:
    
    
    Cadena()
    {
        
    }
    
    bool check(string s1, string s2, int n, int m, int p)
    {
        int j = 0;
        int cont = 0;
        
        for(int i = p; i < p + m; i++)
        {
            if(s1[i]==s2[j])
            {
                j++;
                cont++;
            }
        }
        
        if(cont==m)
            return true;
            
        else
            return false;
    }
    
    bool match(string s1, string s2, int n, int m, int p)
    {
        if(p<n-m)
        {
            if(check(s1, s2, n, m, p)==true)
                return true;
                
            else
                return match(s1, s2, n, m, p+1);
        }
        else
            return false;
    }
    
    
    void Test(string s1, string s2, int n, int m)
    {
        (match(s1, s2, n, m, 0)==true)?cout << "encontrado": cout << "no encontrado";
            
    }
    
    
};

int main()
{
    string s1 = "EXIGETE";
    string s2 = "DD";
    
    Cadena *c = new Cadena();
    
    c->Test(s1, s2, s1.size(), s2.size());
}