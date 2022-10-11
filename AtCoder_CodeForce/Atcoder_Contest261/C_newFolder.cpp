#include <iostream> 
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int N; cin >> N;
    string *matrix = new string[N];

    vector <int> bk;

    for(int i = 0; i < N; i++)
    {
        cin >> matrix[i];

        if( bk.size() == 0 )
        {
            bk.push_back(0);
        }

        
        cout << bk.size() << endl;
    }

    /*
    //Imprimir matriz
    cout << "------- Matrix prueba de vista -----------" << endl;
    for(int i = 0; i < N; i++)
    {
        cout << matrix[i] << endl; 
    }
    */
    //logica
    //cout << "-------------------------------------------" << endl;
    int a;
    for(int i = 0; i < N; i++)
    {
        cout << matrix[i];
        a = 0;
        for(int j = 0; j < i; j++)
        {
            if(matrix[i] == matrix[j])
            {
                a++;
            }
        }
        
        if(a != 0)
        {
            cout << "(" << a << ")" << endl;
        }
        else
        {
            cout << endl;
        }
        
    }

    return 0;
}