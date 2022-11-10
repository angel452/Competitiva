#include <iostream>
using namespace std;

#define INF 0x3f3f3f3f

int main(){

    int n = 5;
    int p[] = {10,20,50,1,100}; 
    int m[n][n] = {0};
    int s[n][n] = {0};

    int j, min, q;

    for(int d = 1; d < n-1 ; d++)
    {
        for( int i = 1; i < n-d; i++)
        {
            j = i+d;
            min = INF;
            //cout << "infinito: " << min << endl;
            for( int k = 1; k <= j-1; k++)
            {
                q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
                cout << q << endl;
                if( q < min )
                {
                    min = q;
                    s[i][j] = k;
                }
            }
        }
    }

    cout << "Numero de operaciones: ";  
    cout << m[1][n-1] << endl;  

    return 0;
}