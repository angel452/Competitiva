#include <iostream>
using namespace std;

//https://atcoder.jp/contests/abc087/tasks/arc090_a

int main()
{
    int n;
    cin >> n;

    //creamos matriz de 2 x n
    int **matriz = new int*[2];
    for(int i = 0; i < 2; i++)
    {
        matriz[i] = new int[n];
    }

    //Llenamos datos
    for(int i = 0; i < 2; i++)
    {
        for( int j = 0; j < n; j++)
        {
            cin>>matriz[i][j];
        }
    }

    //impresion
    /*
    for(int i = 0; i < 2; i++)
    {
        for( int j = 0; j < n; j++)
        {
           cout << matriz[i][j];
        }
        cout << endl;
    }
    */

    //Logica:
    int respuesta = 0;
    for(int i = 0; i < n; i++)
    {
        int aux = 0;
        for(int j = 0; j < i+1; j++)
        {
            aux = aux + matriz[0][j];
        }
        for (int k = i; k < n; k++)
        {
            aux = aux + matriz[1][k];
        }
        respuesta = max(respuesta,aux);
    }

    cout << respuesta;

    return 0;
}