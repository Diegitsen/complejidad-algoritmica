#include <bits/stdc++.h>
using namespace std;

bool check(string s1, string s2, int n, int m, int p) {
	int j = 0;
	int cont = 0;
	for (int i = p;i<p + m;i++) {
		if (s1[i] == s2[j]) {
			j++;
			cont++;
		}
	}
	if (cont == m) return true;
	else return false;
}

bool match(string s1, string s2, int n, int m, int p) {
	if (p < n - m) {
		if (check(s1, s2, n, m, p) == true) return true;
		else return match(s1, s2, n, m, p + 1);
	}
	else 
		return false;
}

void test(string s1, string s2, int n, int m) {
	match(s1, s2, n, m, 0) ? cout << "Encontrado" : cout << "No encontrado";
}

int main(){
string s1="EXIGETE, INNOVA, UPC"; //7
string s2="ET"; //2
test(s1,s2,s1.size(),s2.size());
return 0;
}
