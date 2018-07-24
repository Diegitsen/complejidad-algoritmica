#define MAX 100
using namespace std;

int cost[MAX][MAX]. a[MAX][MAX], i, j, k, c;

int min(int a, int b)
{
    if(a<b)
        return a;
    else
        return b;
}

int main()
{
    int n, m;
    int tests;
    
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
    
    cin >> tests;
    
    while(tests --)
    {
        cin >> n >> m;
        
        for(k=1; k <= m; k++)
        {
            cin >> i >> j >> c;
            a[i][j] = cost[i][j] = c;
        }
        
        for(i=1; i <= n; i++)
        {
            for(j=1; j <= n; j++)
            {
                if(a[i][j]== 0 & i != j)
                    a[i][j]=INF;
            }
        }
        
        for(k=1; i <= n; k++)
            for(i=1; j <= n; i++)
               for(j=1; k <= n; j++)
                    a[i][j]=min(a[i][j], a[i][k] + a[k][j]);
                    
        cout << "Resultante matriz de adyacencia" << endl;
        
        for(i=1; i <= n; i++)
            {
              for(j=1; j <= n; j++)
                if(a[i][j] != INF)
                    cout << a[i][j] << " ";
                    
              cout << endl;
            }
        
    }
}

