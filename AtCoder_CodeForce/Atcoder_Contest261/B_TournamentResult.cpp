#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool func1( char **matrix, int N )
{
    //logica:
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if( (i != j) && (j > i) )
            {
                char aux1 = matrix[i][j];
                if( aux1 == 'W')
                {
                    if( matrix[j][i] != 'L' )
                    {
                        return false;
                    }
                }
                else if( aux1 == 'L')
                {
                    if( matrix[j][i] != 'W' )
                    {
                        return false;
                    }
                }
                else if( aux1 == 'D')
                {
                    if( matrix[j][i] != 'D' )
                    {
                        return false;
                    }
                }
            } 
        }
    }
    return true;
}

int main()
{
    int N; cin >> N;
    char **matriz = new char*[N];
    for(int i = 0; i < N; i++)
    {
        matriz[i] = new char[N];
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> matriz[i][j];    
        }
    }

    /*
    //Imprimir matriz
    cout << "------- Matrix prueba de vista -----------" << endl;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout << matriz[i][j];
        }
        cout << endl;
    }

    //Imprimir matriz
    cout << "------- Matrix prueba de vista -----------" << endl;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if( (i != j) && (j > i) )
            {
                cout << matriz[i][j] << " ";
            }
            else
            {
                cout << " - ";
            }
            
        }
        cout << endl;
    }
    */

    //cout << "--------------------------------" << endl;
    bool flag = func1(matriz, N);
    if(flag == true)
    {
        cout << "correct" << endl;
    }
    else
    { 
        cout << "incorrect" << endl;
    }

    return 0;
}