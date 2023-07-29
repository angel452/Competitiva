#include <iostream>
#include <vector>
using namespace std;

void print(std::vector<int> const &input)
{
    for (int i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
}

int searchP(int n, int **matriz, int aux, int fila)
{
    //caso donde ya estan todas las cartas 1 ... N
    if(aux > n) // n = 3
    {
        cout << "aux : " << aux << "  j: " << fila << endl;
        return fila;
    }

    for(int i = 0; i < 2; i++)
    {
        for( int j = 0; j < n; j++)
        {
            if(matriz[i][j] == aux) 
            {
                aux = aux + 1; // aux = 4
                searchP(n,matriz,aux,j);
                cout << "aux2 : " << aux << "  j2: " << j << endl;

                //dp.push_back(aux2);
            }
        }
    }

    return 1;
}


int main()
{

    int n;
    cin >> n;

    //creamos matriz de 2 x n
    int **matriz = new int*[2];
    for (int i = 0; i < 2; i++)
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
    cout << "Matriz: " << endl;
    for(int i = 0; i < 2; i++)
    {
        for( int j = 0; j < n; j++)
        {
           cout << matriz[i][j];
        }
        cout << endl;
    }
    cout << endl;
    */

    int dp[50][3];
    //vector<vector<int>> dp(50);
    vector<int> aux2;

    //logica
    cout << "Logica: " << endl;
    cout << searchP(n, matriz,1,0);

    return 0;
}