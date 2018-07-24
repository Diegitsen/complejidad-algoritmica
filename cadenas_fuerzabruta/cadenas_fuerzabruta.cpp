#include <bits/stdc++.h>
using namespace std;
int main(){
string s1="UPC, EXIGETE, INNOVA";
string s2="ET";
int n=s1.size();
int m=s2.size();
int j, k;
int aux=0;
for(int i=0;i<=n-m;i++){
	j=i; k=0;
	while(s1[j]==s2[k] && k<=m){
	j++; k++;
	if(k>m-1){
		cout<<"Valor en posición: "<<i+1<<endl; aux=1;
		}
	}
}
if(aux==0) cout<<"Valor no encontrado"<<endl;
return 0;
}