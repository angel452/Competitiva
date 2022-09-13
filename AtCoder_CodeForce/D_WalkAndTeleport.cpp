#include <iostream>
#include <vector>
using namespace std;

//https://atcoder.jp/contests/abc052/tasks/arc067_b

long long minValue(vector<int> vector1, int a, int b, int i)
{
    int aux1 = vector1[i+1]-vector1[i]; 
    long long costoA = aux1*a;
    long long costoB = b;
    return min(costoA,costoB);
}

int main()
{
    int n,a,b;
    vector <int> vector1;

    //pedimos datos
    cin >> n;
    cin >> a;
    cin >> b;

    //pedimos datos
    for(int i = 0; i < n; i++)
    {
        int aux;
        cin>>aux;
        vector1.push_back(aux);
    }

    //logica:
    long long respuesta = 0;
    for(int i = 0; i < n-1; i++) // n = 4
    {
        respuesta = respuesta + minValue(vector1,a,b,i);
    }

    cout << respuesta;

    return 0;
}