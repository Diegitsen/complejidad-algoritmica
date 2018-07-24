#include <bits/stdc++.h>
using namespace std;

bool b = false;

void imprimir(vector<int> v) {
	for (int i = 0; i<v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}

int suma(vector<int> v) {
	int sum = 0;
	for (int i = 0; i<v.size(); i++)
		sum += v[i];
	return sum;
}

vector<int> el_resto(vector<int> v, vector<int> v1) {
	vector<int> v2 = v;
	for (int i = 0; i<v1.size(); i++) {
		for (int j = 0; j < v2.size(); j++) {
			if (v1[i] == v2[j]) {
				v2.erase(v2.begin() + j);
				break;
			}
		}
	}
	return v2;
}

void compare(vector<int> v, vector<int> v1, vector<int> v2) {
	vector<int> aux1;
	vector<int> aux2;
	if (v1.size() < v.size() - 1) {
		for (int i = 0; i < v2.size(); i++) {
			aux1 = v1;
			aux2 = v2;
			aux1.push_back(aux2[i]);
			aux2.erase(aux2.begin() + i);
			if (suma(aux1) == suma(aux2)&&b==false) {
				cout << "Conjuntos disjuntos: " << endl;
				imprimir(aux1);
				imprimir(aux2);
				cout << "Suma: " << suma(aux1);
				b = true;
			}
			compare(v, aux1, aux2);
		}
	}
}

void conj_disj(vector<int> v) {
	vector<int> v1;
	vector<int> v2 = el_resto(v, v1);
	vector<int> aux;
	compare(v, v1, v2);
	if (b == false){
		for(int i=0;i<v2.size();i++){
			aux=v2;
			aux.erase(aux.begin()+i);
			conj_disj(aux);
		}
	}
	if (b == false) cout << "No se hallaron conjuntos disjuntos";
}

int main() {
	vector<int> v = { 2, 3, 4, 5, 9, 6, 7, 1 };
	vector<int>aux;
	conj_disj(v);
	return 0;
}