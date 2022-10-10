#include <iostream>
#include <vector>
using namespace std;

//https://atcoder.jp/contests/abc075/tasks/abc075_b

int main()
{
    int h, w;
    cin >> h; // filas
    cin >> w; // columnas

    vector<string> matrix(h);

    //llenamos datos
    for (int i = 0; i < h; i++)
    {
        cin >> matrix[i];
    }

    //Imprimimos matriz
    /*
    cout << "Matriz: " << endl;
    for (int i = 0; i < h; i++)
    {
        cout << matrix[i] << endl;;
    }
    */
   
    //logica
    for(int i = 0; i < h; i++)
    {
        for( int j = 0; j < w; j++)
        {
            // caso donde #
            if(matrix[i].at(j) == '#')
            {
                cout << "#";
            }
            // caso donde esta vacio o cerca a una bomba
            else
            {
                int contBombs = 0;
                
                // recorremos la matriz nuevamente 
                // para buscar minas proximas
                for (int k = i-1; k <= i+1; k++)
                {
                    for( int l = j-1; l <= j+1; l++)
                    {
                        if(k < 0) { continue; }
                        else if(l < 0) { continue; }
                        else if(l >= w) { continue; }
                        else if(k >= h) { continue; }
                        else if (matrix[k].at(l) == '#')
                        {
                            contBombs++;
                        }
                    }
                }
                cout << contBombs;
            }
        }
        cout << endl;
    }
}