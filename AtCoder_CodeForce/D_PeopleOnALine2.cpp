#include <iostream>
#include <vector>
using namespace std;

long long rowWithFalse(vector <bool> vecComprobaciones, int m) // true -> todos estan coloreados
{                                                    // False -> alguno todavia no se evaluo
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

    //cout << "numero de personas: "; 
    cin >> n ;  //personas
    //cout << "numero de targetas: "; 
    cin >> m ; //n info

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

    /*
    cout << "----- New Matrix -----" << endl;
    for(int i = 0; i < m*2; i++)
    {
        for( int j = 0; j < 3; j++)
        {
            cout << matriz[i][j] << "  ";
        }
        cout << endl;
    }
    */

    // ------------------------ LOGICA -----------------------------

    //cout << " ----------- LLENAR DATOS ------------" << endl;

    // Vector de valores
    vector<int> vecValores;
    int contador = 1;

    // Vector de comprobaciones:
    vector<bool> vecComprobaciones;
    for(int i = 0; i < m*2; i++)
    {
        //cout << "push" << endl;
        vecComprobaciones.push_back(false);
    }

    //cout << "end" << endl;

    vecValores.push_back(0);
    contador++;
    while( vecValores.size() < n ) // While( vecValores no este completa )
    {
        for(int i = 0; i < m*2; i++) // Recorre la matriz
        {   
            //cout << "Evaluando fila: " << i << endl;

            if( matriz[i][1] == contador && matriz[i][0] < matriz[i][1] && vecComprobaciones[i] == false ) //Busca un R en la columna 2
            {
                //Si es apto

                //cout << "--------------------- " << endl;
                //cout << vecValores[ matriz[i][0]-1 ] << " + " <<   matriz[i][2] << endl;
                vecValores.push_back( vecValores[ matriz[i][0]-1 ] + matriz[i][2] );
                vecComprobaciones[i] = true;
                contador++;
                i = m*2; // Salir del for() en fuerza bruta :)
                //cout << "Tam Vector: " << vecValores.size()  << " - n: " << n << endl; 
                //cout << "Insertado" << endl;
            }
        }
        //vecValores.push_back(100);
    }

    //cout << " ----------- COMPROBAR ------------" << endl;

    //int contador2 = 0;
    while( true ) //Si alguno todavia no se ha evaluado
    {
        /*
        cout << endl << "Vector de comprobaciones " << endl;
        for( int i=0; i < m*2; i++)
        {
            cout << vecComprobaciones[i] << " ";
        }
        cout << endl;
        */

        int rowFalse = rowWithFalse(vecComprobaciones,m);

        //Comprobar si todos ya fueron evaluados
        if(rowFalse > 10000)
        {
            break;
        }

        int aux = vecValores[ matriz[ rowFalse ][0]-1 ] + matriz[ rowFalse ][2];
        //cout << "Fila sin evaluar: " << rowFalse << endl;
        //cout << vecValores[ matriz[ rowFalse ][0]-1 ] << " + " << matriz[ rowFalse ][2] << " = " << aux << endl;

        if( aux != vecValores[ matriz[ rowFalse ][1]-1 ] ) // NO COINCIDE
        {
            verf = false;
            break;
        }
        else
        {
            vecComprobaciones[ rowFalse ] = true; // Marcamos como evaluado
        }
        
    }

    /*
    cout << "Vector de Valores" << endl;
    for( int i=0; i < vecValores.size(); i++)
    {
        cout << vecValores[i] << " ";
    }
    cout << endl;
    */

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