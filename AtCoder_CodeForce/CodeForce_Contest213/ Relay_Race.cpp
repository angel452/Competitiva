#include <iostream>
using namespace std;

#define N 310
#define INF 0x3f3f3f3f

int n;
int dp[N*2][N][N];
int a[N][N];

int maximo(int a, int b, int c, int d)
{
    int p, q;

    if(a > b){
        p = a;
    }
    else{ 
        p = b;
    }

    if(c > d){
        q = c;
    }
    else{ 
        q = d;
    }

    if(p > q){
        return p;
    }
    return q;
}

int main()
{
    cin >> n;
    //cout << " Guardamos la matriz ... " << endl;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    //cout << " LLenamos la matriz dp con INF ..." << endl;
    for(int i = 1; i <= 2*n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            for(int k = 0; k <= n; k++)
            {
                dp[i][j][k] = -INF;
            }
        }
    }

    /*
    for(int i = 1; i <= 2*n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            for(int k = 0; k <= n; k++)
            {
                cout << dp[i][j][k] << '\t';
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << endl;
    */

    dp[1][1][1] = a[1][1];
    for(int i = 2; i <= n*2-1; i++ )
    {
        for(int j = 1; j <= n; j++)
        {
            for(int k = 1; k <= n; k++)
            {
                dp[i][j][k] = maximo( dp[i-1][j-1][k  ],  
                                      dp[i-1][j-1][k-1],
                                      dp[i-1][j  ][k-1],
                                      dp[i-1][j  ][k  ]       );
                
                //son los punteros que permiten moverme y hacer sumas?
                int ca = i + 1 - j;
                int cb = i + 1 - k;
                //cout << "-------------------------" << endl;
                //cout << "j, ca: " << j << " - " << ca << endl;
                //cout << "k, cb: " << k << " - " << cb << endl;
                
                int cnt = 0;
                //Hacemos las 2 sumas de ida y vuelta de las 2 personas

                //cout << dp[i][j][k] << " = " << dp[i][j][k] << " + " << a[j][ca] << " + " << a[k][cb] << endl;
                if( 1 <= ca && ca <= n ){
                    dp[i][j][k] += a[j][ca];
                    cnt = cnt + 1;
                }
                if( 1 <= cb && cb <= n ){
                    dp[i][j][k] += a[k][cb];
                    cnt = cnt + 1;
                }
                if( cnt == 2 && j == k ) // FILTRO: VERIFICA SI ESTAMOS EN EL MISMO CUADRADO Y RESTA EL EXCESO
                {
                    dp[i][j][k] -= a[j][ca];
                    //cout << "filtro" << endl;
                }

            }
        }
    }

    /*
    cout << "------------ DP --------------"<<  endl;
    for(int i = 1; i <= 2*n -1; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            for(int k = 0; k <= n; k++)
            {
                cout << dp[i][j][k] << '\t';
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << endl;
    */
    //cout << "---------------------------------" << endl;

    //cout << "Resultado: " << endl;
    cout << dp[2*n-1][n][n] << endl;

    return 0;
}



/*
caso 1:
3
25 16 25
12 1 19
11 13 8

caso 2:
4
5 5 5 5 
5 1 1 5
5 5 1 5
1 5 5 5

*/