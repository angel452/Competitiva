#include<bits/stdc++.h>
#include <numeric>
using namespace std;

int main(){

    long long n;
    cin >> n;

    long long contador = 0;
    for(long long i = 1; i <= n; i++)
    {
        for(long long j = 1; j <= n; j++)
        {
            if( i == j ){
                cout << i << " - " << j << endl;
                long long resultado;
                resultado = lcm(i,j)/gcd(i,j);
                if( resultado <= 3 ){
                    contador =  contador + 1;
                }
            }
            else if(i < j){
                cout << i << " - " << j << endl;
                long  long resultado2 = lcm(i,j)/gcd(i,j);
                if( resultado2 <= 3 ){
                    contador =  contador + 2;
                }
            }
        }
    }

    cout << contador << endl;

    return 0;
}