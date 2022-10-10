#include <iostream>
using namespace std;

void funtion(int nVertices, int mAristas, int matrix[], int numV, int contador, int ini, int fin)
{
    if(false)
    {
        funtion(nVertices,mAristas,matrix,numV, contador+1, ini, fin);
    }

    // Buscamos Adyacente
    for(int i = 0; i < mAristas*2; i = i+2)
    {
        if( (ini != matrix[i] && fin != matrix[i+1]) || ini != matrix[i+1] && fin != matrix[i] ) // Que no tome el mismo valor
        {
            if( ini == matrix[i] || ini == matrix[i+1] )
            {
                cout << matrix[i] << " ";
                cout << matrix[i+1];
                cout << "----------" << endl;
            }
        }
    }
    /*
    for(int i = 0; i < mAristas*2; i++)
    {
        int ini = matrix[i];

        for(int j = 0; j < mAristas*2; j++)
        {
            int fin = matrix[i+1];
            
            //buscamos el otro
            for(int k = 0; k < mAristas*2; k++ )
            {

            }
        }
    } */
}


int main()
{
    int nVertices;
    int mAristas;

    cin>>nVertices; cin>> mAristas;

    //int matrix[2][mAristas];
    int matrix[mAristas*2];

    /*
    for(int i = 0; i < mAristas; i++)
    {
        int u, v;
        cin>> u; cin>>v;
        
        matrix[i][0] = u;
        matrix[i][1] = v;   
    }}
    */

   for(int i = 0; i < mAristas*2; i++)
   {
        cin>> matrix[i];
   }

    /*
    cout << "Matrix"  << endl;
    for(int i = 0; i < mAristas; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            cout<<matrix[i][j] << " ";
        }
        cout << endl;
    }
    */

    cout << "Matrix"  << endl;
    for(int i = 0; i < mAristas*2; i++)
    {
        cout<<matrix[i] << " ";
    }
    cout << "-------------" << endl;
    
    funtion(nVertices, mAristas, matrix, 1,0,matrix[0], matrix[1]);


    return 0;
}