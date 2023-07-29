#include <iostream>
#include <vector>
using namespace std;

long long rowWithFalse(vector <bool> vecComprobaciones, int m) // retorna la fila donde aun no se evalua
{                                                             
    for(int i = 0; i < m*2; i++)
    {
        if(vecComprobaciones[i] == false)
        {
            //cout << "fila " << i << "Sin evaluar" <<  endl;
            return i;
        }
    }

    return 100001;
}

int main()
{
    int n, m;
    bool verf = true;

    cin >> n ; // numero de personas
    cin >> m ; // numero de targetas

    // Se crea la matriz de 2*m filas
    int **matriz = new int*[m*2];
    for(int i = 0; i < m*2; i++)
    {
        matriz[i] = new int[3];
    }

    // Insertar Datos
    for(int i = 0; i < m*2; i++)
    {
        for( int j = 0; j < 3; j++)
        {
            if( i%2 == 0 )
            {
                cin>>matriz[i][j];
            }
            else
            {
                matriz[i][j] = matriz[i-1][j+1];
                j++;
                matriz[i][j] = matriz[i-1][j-1];
                j++;
                matriz[i][j] = (matriz[i-1][j])*(-1);
            }
        }
    }

    // ------------------------ LOGICA -----------------------------
    // ----------- LLENAR DATOS ------------

    // Vector de valores
    vector<int> vecValores;
    int contador = 1;

    // Vector de comprobaciones:
    vector<bool> vecComprobaciones;
    for(int i = 0; i < m*2; i++)
    {
        vecComprobaciones.push_back(false);
    }

    vecValores.push_back(0); // Hacemos primer push
    contador++; 

    while( vecValores.size() < n ) // While( vecValores no este completa )
    {
        for(int i = 0; i < m*2; i++) // Recorrer filas
        {   
            if( matriz[i][1] == contador && matriz[i][0] < matriz[i][1] && vecComprobaciones[i] == false ) //Busca un R en la columna 2
            {
                //Si es apto
                vecValores.push_back( vecValores[ matriz[i][0]-1 ] + matriz[i][2] ); // OPERACION 1
                vecComprobaciones[i] = true;
                contador++;
                i = m*2; // Salir del for() en fuerza bruta :)
            }
        }
    }

    // ----------- COMPROBAR ------------
    while( true ) //Si alguno todavia no se ha evaluado
    {
        int rowFalse = rowWithFalse(vecComprobaciones,m);

        // EXEPCION: Si todos ya fueron evaluados
        if(rowFalse > 10000)
        {
            break;
        }

        int aux = vecValores[ matriz[ rowFalse ][0]-1 ] + matriz[ rowFalse ][2]; //OPERACION 2
        if( aux != vecValores[ matriz[ rowFalse ][1]-1 ] )
        {
            verf = false;
            break;
        }
        else
        {
            vecComprobaciones[ rowFalse ] = true; // Marcamos como evaluado
        }
        
    }

    if(verf == true)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    

    return 0;
}