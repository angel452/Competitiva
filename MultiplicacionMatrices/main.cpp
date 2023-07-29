#include<iostream>
#include<limits.h>
using namespace std;

int m[100][100];
int s[100][100];

int matrixMultiplication(int arr[],int n)
{
    int i,j,k,l,q;
    for(i=1;i<n;i++){
      m[i][i] = 0;
    }

    cout << "(";
    for(l=2; l<n ; l++)
    {
        for(i=1; i<n-l+1; i++)
        {
            j = i+l-1;
            m[i][j] = INT_MAX;
            for(k=i; k <= j-1; k++)
            {
                q = m[i][k] + m[k+1][j] + arr[i-1]*arr[k]*arr[j];
                cout << "Aux1: " << q << endl;
                if(q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
                
                /*
                if(k = i){
                    cout << "M" << i+1;
                }
                */
            }
        }
    }
    return m[1][n-1];
}



void orderMatrix(int i,int j)
{
    if(i==j)
    {
        cout<<"M"<<i+1;
    }
    else
    {
        cout<<"(";
        orderMatrix(i, s[i][j]);
        orderMatrix(s[i][j]+1, j);
        cout<<")";
    }
}

int main()
{
    int n;

    cout<<"Numero de matrices: " ; cin >> n;

    n = n +1;
    int dimensiones[n+1];
    cout<<"Dimensiones: " << endl;
    for(int i = 0; i < n; i++)
    {
        cin>>dimensiones[i];
    }

    cout<<"Numero de operaciones: "<< matrixMultiplication(dimensiones,n) << endl;
    cout<<"Orden: ";
    orderMatrix(0,n-2);
    cout << endl;

    cout << "S ->" <<  endl;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            cout << s[i][j] << " ";
        }
        cout << endl;
    }

    cout << "M ->" <<  endl;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}


//10 25 15 4 13 17