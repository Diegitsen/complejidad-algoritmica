#include <cstring>
#include <iostream>


#define maxN 7
#define Fill(ar, val) memset(ar, val, sizeof(ar))


using namespace std;

const int n = 5;
int a[maxN];
bool flag[maxN], solved;

bool readinput() {
	for (int i=1; i<=n; i++)	
		scanf("%d", &a[i]);
    for (int i=1; i<=n; i++)	
        if (a[i]) return true;
    return false;
}

void back_tracking(int res, int k) {
	std::cout<<"res:"<<res<<", "<<k<<endl;
    if (solved) return;
    if (res == 23 && k > n) {
        solved = true;
        return;
    }
    
	for (int i=1; i<=n; i++){
        if (flag[i]) {
            flag[i] = false;
            back_tracking(res + a[i], k + 1);
            back_tracking(res - a[i], k + 1);
            back_tracking(res * a[i], k + 1);
            flag[i] = true;
        }
    }
}

int main() {
    
	while (readinput()) {
        solved = false;
        Fill(flag, true);
		for (int i=1; i<=n; i++){
            flag[i] = false;
            back_tracking(a[i], 2);
            flag[i] = true;
            if (solved) break;
        }
        if (solved) 
			puts("Posible");
        else 
			puts("Imposible");
    }
    
    return(0);
}